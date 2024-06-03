/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/30 17:46:38 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	c_length(char **s)
{
	int	i;

	i = 0;
	if (!*s || !s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

t_minishell	*parcing(char *str)
{
	t_minishell	*cmp;
	t_minishell	*head;
	char		**strs;

	cmp = NULL;
	head = NULL;
	strs = ft_spliter(str);
	if (!strs)
		return (NULL);
	cmp = get_link_cmd(strs, head, cmp, c_length(strs));
	return (cmp);
}
