/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:27:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:45:42 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_special_case(char *s)
{
	int	i;

	i = 0x0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		i++;
	}
	return (0x0);
}

char	*ft_key(char *s)
{
	int		i;

	i = 0x0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '=')
		{
			return (ft_substr_executor_1(s, 0x0, i));
		}
		i++;
	}
	return (NULL);
}

int	no_equal(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i++] == '=')
			return (0x0);
	}
	return (0x1);
}

void	export_error(t_minishell *m, int option, char *s, char *o)
{
	(void) o;
	ft_putstr_fd("export: ", 0x2);
	if (option == 0x0)
		ft_put_err(s, " : not a valid identifier");
	if (option == 0x1)
		ft_put_err(s, ": bad pattern");
	if (option == 0x2)
		ft_put_err(s, " : not valid in this context");
	ex_st_f(0x1, 0x1);
	if (m)
	{
		if (m->size > 1)
			exit(0x1);
	}
}

char	*ft_key_1(char *s)
{
	int		i;

	i = 0x0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '=')
			return (ft_substr_executor(s, 0x0, i));
		i++;
	}
	return (s);
}
