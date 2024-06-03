/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:35:22 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 13:48:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	helper(t_minishell *m, int *fin, int *fout, int *fher)
{
	if (m->tab[m->len_tab - 1] == 0x4)
	{
		close (*fin);
		m->fd_in = *fher;
	}
	else if (*fin != 0x0)
	{
		if (m->fd_in != 0)
			close (m->fd_in);
		m->fd_in = *fin;
	}
	if (*fout != 0x1)
		m->fd_out = *fout;
}

int	ft_open_others(t_minishell *mini, int i, int f_in, int f_out)
{
	int	*fd;

	fd = &mini->fd_in;
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 0x1)
		{
			if (ft_open_1(mini, mini->files[i + 0x1], &f_out, &i))
				return (0x1);
		}
		else if (mini->tab[i] == 0x2)
		{
			if (ft_open_2(mini, mini->files[i + 1], &f_out, &i))
				return (0x1);
		}
		else if (mini->tab[i] == 0x3)
		{
			if (ft_open_3(mini, mini->files[i + 1], &f_in, &i))
				return (0x1);
		}
	}
	helper(mini, &f_in, &f_out, fd);
	return (0);
}

int	expanded_content(char *s)
{
	if ((s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL)
		|| (s[0x0] == DBL && s[ft_strlen(s) - 1] == DBL))
		return (0x1);
	return (0x0);
}

int	ft_helper_heredoc(t_minishell *m, char *s)
{
	if (ft_strlen(m->cmd[0]) == 0)
	{
		close (m->fd_in);
		return (0x0);
	}
	close(m->fd_in);
	m->fd_in = open(s, O_RDWR | O_APPEND, 0777);
	if (m->fd_in == -0x1)
		return (-0x1);
	unlink(s);
	return (m->fd_in);
}

int	func(char *p, char *res, int *i, char *s)
{
	int	j;

	j = 0x0;
	if (ft_strlen(p) || !ft_strlen(res))
		*i += grep(&s[*i]);
	j = ft_strlen(p);
	return (j);
}
