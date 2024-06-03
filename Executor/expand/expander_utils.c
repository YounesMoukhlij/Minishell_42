/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:20:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 17:14:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	case_1(char *s, int pos)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == DBL)
		{
			i++;
			while (s[i] != DBL && s[i])
			{
				if (i == pos)
					return (0x1);
				i++;
			}
			if (i + 1 == pos)
				return (0x1);
		}
		i++;
	}
	return (0x0);
}

int	case_2(char *s, int pos)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == SGL)
		{
			i++;
			while (s[i] != SGL && s[i])
			{
				if (i == pos)
					return (0x0);
				i++;
			}
		}
		i++;
	}
	return (1);
}

int	dollar_position(char *s, int pos)
{
	if (case_1(s, pos))
		return (0x1);
	if (case_2(s, pos))
		return (0x1);
	return (0x0);
}

int	check_single(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (s[i] == SGL && s[ft_strlen(s) - 1] == SGL)
			return (0x1);
		i++;
	}
	if (!strcmp_f(s, "\'", 0x0, 0x0) || !strcmp_f(s, "\"", 0x0, 0x0))
		return (0x1);
	if (s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL && ft_strlen(s) > 2)
		return (0x1);
	return (0x0);
}

char	*do_single(char *s, int i, int j)
{
	char	*r;

	while (s[i])
	{
		if (s[i] == SGL && s[ft_strlen(s) - 1] == SGL)
			return (s);
		i++;
	}
	i = 0;
	if (!strcmp_f(s, "\"", 0x0, 0x0))
		return (ft_strdup("\""));
	if (!strcmp_f(s, "\'", 0x0, 0x0))
		return (ft_strdup("\'"));
	r = ft_calloc(ft_strlen(s), 1);
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] == SGL)
			i++;
		if (!s[i])
			break ;
		r[j++] = s[i++];
	}
	return (r);
}
