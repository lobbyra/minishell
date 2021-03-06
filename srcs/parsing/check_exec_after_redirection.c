/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec_after_redirection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:34:56 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/23 19:47:53 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_exec_after_redirection(t_stock *s, int n, int *status,
char **exec)
{
	int	i;

	i = 0;
	if (*exec == NULL)
	{
		while (s->jobs[n][i])
			i++;
		if (i > 2 && ft_isalnum(s->jobs[n][2][0]))
		{
			*exec = ft_strjoin("/", s->jobs[n][2]);
			*status = 1;
		}
		else
			return (0);
	}
	return (1);
}
