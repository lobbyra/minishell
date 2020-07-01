/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_metacharacter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:15:46 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/07/01 14:56:20 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_metacharacter(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}	

int				verif_metacharacter(t_stock *s, char **command)
{
	int i;

	i = 0;
	while (command[i + 1])
	{
		if (is_metacharacter(command[i][0]) && is_metacharacter(command[i + 1][0]))
		{
			s->error_strings = ft_strjoindel(s->error_strings, \
			"minishell: syntax error near unexpected token `", 1);
			s->error_strings = ft_strjoindel(s->error_strings, \
			ft_strjoin(command[i + 1], "'"), 2);
			l_printf("[%s]\n", s->error_strings);
			return (0);
		}
		i++;
	}
	return (1);
}