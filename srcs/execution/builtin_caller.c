/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_caller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:18:48 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 18:00:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_caller(char **job, char *exit_stat, int is_child, char ***envp)
{
	char *exec_name;

	if (!(exec_name = ft_basename(*job)))
		return (ERR_MALLOC);
	if (ft_strcmp(exec_name, "cd") == 0)
		*exit_stat = cd(job[1]);
	else if (ft_strcmp(exec_name, "echo") == 0)
		*exit_stat = echo(job, 1);
	else if (ft_strcmp(exec_name, "env") == 0)
		*exit_stat = env(*envp, 1);
	else if (ft_strcmp(exec_name, "export") == 0)
		*exit_stat = export(envp, job, 1);
	else if (ft_strcmp(exec_name, "exit") == 0)
		ft_exit(ft_atoi(job[1]));
	else if (ft_strcmp(exec_name, "pwd") == 0)
		*exit_stat = pwd(1);
	else if (ft_strcmp(exec_name, "unset") == 0)
		*exit_stat = unset(envp, job);
	free(exec_name);
	if (is_child == TRUE)
		exit(*exit_stat);
	return (0);
}