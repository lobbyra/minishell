/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:33:24 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/02 08:59:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	char	*temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp)
		temp++;
	return (temp - str);
}
