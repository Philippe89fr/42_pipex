/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vie_de_famille_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:05:08 by prambaud          #+#    #+#             */
/*   Updated: 2025/01/06 15:42:55 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_file(t_list2 pipex)
{
	int	fd;

	pipex.first = 0;
	fd = open(pipex.av[1], O_RDWR);
	if (fd == -1)
	{
		perror(strerror(errno));
		ft_liberator_max(pipex.path);
		ft_liberator_max(pipex.cmd);
		free(pipex.pid);
		close(pipex.fd2);
		close(pipex.pipefd[1]);
		close(pipex.pipefd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
		perror(strerror(errno));
		close(fd);
	}
	close(fd);
}

int	ft_life_fils(t_list2 pipex)
{
	if (pipex.first == 1 && pipex.bonus == 0)
		ft_open_file(pipex);
	pipex.first = 0;
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	ft_new_processus(pipex);
	close(pipex.pipefd[1]);
	return (1);
}

int	ft_life_dernier_fils(t_list2 pipex)
{
	close(pipex.pipefd[0]);
	dup2(pipex.fd2, 1);
	ft_new_processus(pipex);
	close(pipex.pipefd[1]);
	close(pipex.fd2);
	return (1);
}

int	ft_life_papa(t_list2 pipex)
{
	close(pipex.pipefd[1]);
	dup2(pipex.pipefd[0], 0);
	close(pipex.pipefd[0]);
	return (1);
}

int	ft_life_dernier_papa(t_list2 pipex)
{
	int	i;

	i = 0;
	close(pipex.pipefd[1]);
	dup2(pipex.pipefd[0], 0);
	close(pipex.pipefd[0]);
	if (pipex.bonus == 0)
	{
		while (i <= pipex.ac - 4)
		{
			waitpid(pipex.pid[i], &pipex.status, 0);
			i++;
		}
	}
	else
	{
		while (i <= pipex.ac - 5)
		{
			waitpid(pipex.pid[i], &pipex.status, 0);
			i++;
		}
	}
	close(pipex.fd2);
	return (1);
}
