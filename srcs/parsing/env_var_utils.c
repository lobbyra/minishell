/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:48:32 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/27 16:23:47 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function is the continuation of env_var.c
**	(replaces a environment variable by this value)
*/

#include "minishell.h"

int		number_env_var(char *user_input)
{
	int		i;
	int		quote;
	int		number_env_var;

	i = 0;
	quote = 0;
	number_env_var = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\'' || user_input[i] == '\"')
		{
			word_between_simple_quote(&i, user_input, &quote);
			i++;
		}
		if (i > 0)
		{
			if (user_input[i] == '$' && user_input[i - 1] != '\\' && \
			(quote == 0 || quote == 2))
				number_env_var++;
		}
		else if (user_input[0] == '$')
			number_env_var++;
		i++;
	}
	return (number_env_var);
}

char	**pre_malloc_arrstring(int nb_env_var)
{
	int		i;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (nb_env_var + 1))))
		return (NULL);
	tab[nb_env_var] = NULL;
	i = 0;
	while (i < nb_env_var)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		tab[i][0] = '\0';
		i++;
	}
	return (tab);
}

int		free_env_var_data(char **tab, char **value)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	if (value)
	{
		i = 0;
		while (value[i])
			free(value[i++]);
		free(value);
	}
	return (0);
}

int		count_len_new_str(char *user_input, char **value)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (user_input[i])
	{
		if (user_input[i] == '$' && !is_escaped(user_input, i))
		{
			i++;
			while ((user_input[i] && (ft_isalnum(user_input[i]) ||
			user_input[i] == '_')))
				i++;
		}
		else
		{
			n++;
			i++;
		}
	}
	return (n + ft_full_len_arrstr(value));
}

char	*remove_and_replace(char *user_input, char **value)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * \
	(count_len_new_str(user_input, value) + 1))))
		return (NULL);
	new[count_len_new_str(user_input, value)] = '\0';
	new = remove_and_replace_utils(user_input, new, value);
	return (new);
}
