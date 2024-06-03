/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 14:35:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin_cmd(t_minishell *m, t_env *envir)
{
	full_fill_path(m, envir);
	if (check_fd(m, envir))
		return (-0x1);
	expander(&m, envir);
	handle_fd(m);
	if (!strcmp_f(m->cmd[0], "cd", 0, 0))
		return (ft_cd(m, envir));
	else if (!strcmp_f(m->cmd[0], "env", 0, 0) || !strcmp_f(m->cmd[0], "ENV", 0,
			0))
		return (ft_env(m, envir));
	else if (!strcmp_f(m->cmd[0], "pwd", 0, 0) || !strcmp_f(m->cmd[0], "PWD", 0,
			0))
		return (ft_pwd(m, &envir));
	else if (!strcmp_f(m->cmd[0], "export", 0, 0))
		return (ft_export(m, envir, 0x1, 0x0));
	else if (!strcmp_f(m->cmd[0], "exit", 0, 0))
		return (ft_exit(m));
	else if (!strcmp_f(m->cmd[0], "unset", 0, 0))
		return (ft_unset(m, envir));
	else if (!strcmp_f(m->cmd[0], "echo", 0, 0) || !strcmp_f(m->cmd[0], "ECHO",
			0, 0))
		return (ft_echo(m, envir, 0x1, 0x0));
	else
		return (-1);
}

int	is_builtin(t_minishell *m)
{
	if (!ft_strlen(m->cmd[0]))
		return (0x0);
	if (!strcmp_f(m->cmd[0], "cd", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "env", 0, 0) || !strcmp_f(m->cmd[0], "ENV", 0,
			0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "pwd", 0, 0) || !strcmp_f(m->cmd[0], "PWD", 0,
			0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "export", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "exit", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "unset", 0, 0))
		return (0x1);
	else if ((!strcmp_f(m->cmd[0], "echo", 0, 0) || !strcmp_f(m->cmd[0], "ECHO",
				0, 0)) || (!strcmp_f(m->cmd[1], "echo", 0, 0)
			|| !strcmp_f(m->cmd[1], "ECHO", 0, 0)))
		return (0x1);
	else
		return (0x0);
}

char	**get_cmd_splited(char **s, int i, int q, int j)
{
	char	**r;
	char	**res;
	int		len;

	res = splited_cmd(s, &len);
	if (!res)
		return (NULL);
	while (s[i])
	{
		r = ft_split_executor(s[i], ' ');
		j = 0;
		while (r[j])
		{
			res[q] = ft_strdup(r[j]);
			j++;
			q++;
		}
		i++;
	}
	res[q] = 0;
	return (res);
}

int	check_before(char *s)
{
	if (ft_strlen(s) > 0 && (s[0x0] != '.' || s[0] != '/'))
		return (0x0);
	return (0x1);
}

int	is_bin_cmd(t_minishell *mini, t_env *envir, int flag, int i)
{
	char	*s;
	char	**res;

	i_b_n(mini->cmd[0], envir, mini);
	i_b_n_2(mini, &res);
	while (mini->path_d[i])
	{
		if (ft_strlen(res[0x0]) > 0 && !(res[0x0][0x0] == '.'
			|| res[0x0][0x0] == '/'))
			s = ft_strjoin_space_executor(mini->path_d[i], res[0x0], '/');
		else
			s = res[0x0];
		if (access(s, X_OK) == 0x0)
		{
			if (execve(s, res, execv_env(envir)) == 0)
			{
				flag = 0x0;
				break ;
			}
		}
		i++;
	}
	i_b_n_1(flag, mini->cmd[0x0]);
	return (0x1);
}
