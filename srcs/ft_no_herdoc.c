/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_herdoc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:21:27 by prambaud          #+#    #+#             */
/*   Updated: 2025/01/06 15:42:48 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_new_processus(t_list2 pipex)
{
	int		i;
	char	*full_cmd;

	i = 0;
	if (pipex.path_check == 1)
		ft_new_processus_path_included(pipex);
	else
	{
		while (pipex.path[i])
		{
			full_cmd = ft_strjoin(pipex.path[i], pipex.cmd[0]);
			if (access(full_cmd, F_OK | X_OK) != -1)
				execve(full_cmd, pipex.cmd, pipex.env);
			free(full_cmd);
			i++;
		}
		ft_liberator_max(pipex.path);
		ft_liberator_max(pipex.cmd);
		free(pipex.pid);
		close(pipex.fd2);
		close(pipex.pipefd[1]);
		perror(strerror(errno));
		exit(0);
	}
}

void	ft_new_processus_path_included(t_list2 pipex)
{
	execve(pipex.cmd[0], pipex.cmd, pipex.env);
	ft_liberator_max(pipex.cmd);
	ft_liberator_max(pipex.path);
	free(pipex.pid);
	close(pipex.fd2);
	close(pipex.pipefd[1]);
	perror(strerror(errno));
	exit(0);
}

int	ft_pipex_loop(t_list2 pipex)
{
	int	i;
	int	j;

	if (pipex.bonus == 0)
		i = 2;
	else
		i = 3;
	j = 0;
	pipex.path = ft_path(pipex.env);
	if (!pipex.path)
		return (perror(strerror(errno)), free(pipex.pid), close(pipex.fd2), 0);
	while (i < pipex.ac - 1)
	{
		pipex.cmd = ft_split(pipex.av[i], ' ');
		if (!pipex.cmd)
			return (ft_liberator_max(pipex.path), close(pipex.fd2), 0);
		if ((!pipex.cmd[0]))
			return (ft_liberator_max(pipex.cmd), ft_liberator_max(pipex.path),
				close(pipex.fd2), 0);
		ft_pipex_loop2(pipex, j, i);
		i++;
		j++;
	}
	ft_liberator_max(pipex.path);
	return (1);
}

int	ft_pipex_loop2(t_list2 pipex, int j, int i)
{
	if (ft_strchr(pipex.cmd[0], '/'))
		pipex.path_check = 1;
	else
		pipex.path_check = 0;
	if (pipe(pipex.pipefd) == -1)
		return (perror(strerror(errno)), ft_liberator_max(pipex.cmd),
			free(pipex.pid), close(pipex.fd2), 0);
	pipex.pid[j] = fork();
	if (pipex.pid[j] == -1)
		return (perror(strerror(errno)), ft_liberator_max(pipex.cmd),
			free(pipex.pid), close(pipex.fd2), 0);
	if (pipex.pid[j] == 0 && i != pipex.ac - 2)
		ft_life_fils(pipex);
	else if (pipex.pid[j] > 0 && i != pipex.ac - 2)
		ft_life_papa(pipex);
	else if (pipex.pid[j] == 0)
		ft_life_dernier_fils(pipex);
	else if (pipex.pid[j] > 0)
		ft_life_dernier_papa(pipex);
	ft_liberator_max(pipex.cmd);
	return (1);
}

int	ft_mandatory(t_list2 pipex)
{
	pipex.bonus = 0;
	pipex.first = 1;
	pipex.fd2 = open(pipex.av[pipex.ac - 1], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (pipex.fd2 == -1)
		return (perror(strerror(errno)), 0);
	ft_pipex_loop(pipex);
	return (0);
}
