/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:07:44 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 11:37:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char *s, int i)
{
	ft_putstr_fd_executor("cd: no such file or directory: ", 2, 0);
	if (i == 1)
		ft_putstr_fd_executor(s, 2, 1);
}

int	cmd_length(t_minishell *m)
{
	int	i;

	i = 0;
	if (!ft_strlen(m->cmd[0]) || !m->cmd || !m->cmd[0])
		return (0);
	while (m->cmd[i])
		i++;
	return (i);
}

int	error_case(t_minishell *mini, char *s)
{
	int		i;

	i = 0x0;
	(void) s;
	if (mini->cmd[0x1])
	{
		if (ft_strlen(mini->cmd[0x1]) == 0 && mini->cmd[0x1][0] == '$')
			return (0x0);
	}
	if (cmd_length(mini) > 2)
		return (0x1);
	if (s)
	{
		while (s[i])
		{
			if (s[i] == DBL && s[i + 1] == '~' && s[i + 2] == DBL)
				return (print_error("~", 0x1), 0x1);
			i++;
		}
	}
	return (0x0);
}

t_env	*env_node(t_env **envi, char *keyy)
{
	while ((*envi))
	{
		if (!strcmp_f((*envi)->key, keyy, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
	}
	return (NULL);
}

void	change_dir(t_env *envi, int flag, char	*buff)
{
	t_env	*t;
	t_env	*t_1;
	char	*new_pwd;

	new_pwd = NULL;
	if (flag == 0x1)
	{
		t = env_node(&envi, "PWD");
		t_1 = env_node(&envi, "OLDPWD");
		if (t_1)
			(1) && (free (t_1->value),
				t_1->value = ft_strdup_1(t->value));
	}
	else
	{
		new_pwd = getcwd(buff, sizeof(new_pwd));
		if (new_pwd)
		{
			t = env_node(&envi, "PWD");
			if (t)
				(1) && (free (t->value), t->value = ft_strdup_1(new_pwd));
		}
	}
	free (new_pwd);
}
