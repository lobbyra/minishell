/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_builder_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:05:48 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/27 11:40:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_child(t_child child)
{
	l_printf("### DEBUG CHILD ###\n\n");
	l_printf("c.args = [");
	ft_putarrstr(child.args, "], [");
	write(1, "]", 1);
}

void	free_child(t_child child)
{
	if (child.args)
		ft_freestrs(child.args);
	if (child.path)
		free(child.path);
	if (child.exec_name)
		free(child.exec_name);
}

int		panic_ib(t_child child, int err)
{
	free_child(child);
	if (err == ERR_ERRNO)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(strerror(errno), STDERR);
		ft_putstr_fd("\n", STDERR);
	}
	else if (err == ERR_MALLOC)
		ft_putstr_fd("minishell: instance_builder: memalloc error.\n", STDERR);
	return (errno);
}

void	print_exec_err(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	ft_putstr_fd(": ", STDERR);
	if (ft_c_finder('/', path) == FALSE)
		ft_putstr_fd("command not found\n", STDERR);
	else if (S_ISDIR(path_stat.st_mode) == TRUE)
		ft_putstr_fd("is a directory\n", STDERR);
	else if (S_ISREG(path_stat.st_mode) == TRUE)
		ft_putstr_fd("Permission denied\n", STDERR);
	else
		ft_putstr_fd("No such file or directory\n", STDERR);
	exit(127);
}
