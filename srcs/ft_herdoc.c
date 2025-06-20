/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:35:37 by prambaud          #+#    #+#             */
/*   Updated: 2025/01/06 15:24:18 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_gnl(void)
{
	extern char	*g_stash;

	if (g_stash)
	{
		free(g_stash);
		g_stash = NULL;
	}
}

int	ft_strcmp1(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_get_input(t_list2 *pipex, int fd1)
{
	char	*buf;
	char	*limiter;

	pipex->fd2 = open(pipex->av[pipex->ac - 1], O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (pipex->fd2 == -1)
		return (perror("open"), 0);
	buf = get_next_line(0);
	limiter = ft_strjoin(pipex->av[2], "\n");
	if (!limiter)
		return (perror("join"), close(pipex->fd2), 0);
	while (ft_strcmp1(buf, limiter) || ft_strlen(buf) != ft_strlen(limiter))
	{
		write(fd1, buf, ft_strlen(buf));
		free(buf);
		buf = get_next_line(0);
		if (!buf)
			return (perror("GetNL"), close(pipex->fd2), free(limiter),
				ft_free_gnl(), 0);
	}
	free(buf);
	free(limiter);
	ft_free_gnl();
	return (1);
}

int	ft_bonus(t_list2 pipex)
{
	int		fd1;
	char	*infile_bonus;

	infile_bonus = "infile_bonus";
	pipex.first = 0;
	fd1 = open(infile_bonus, O_WRONLY | O_CREAT, 0644);
	if (fd1 == -1)
		return (perror(strerror(errno)), unlink(infile_bonus), 0);
	pipex.bonus = 1;
	if (!ft_get_input(&pipex, fd1))
		return (unlink(infile_bonus), close(fd1), 0);
	close(fd1);
	fd1 = open(infile_bonus, O_RDONLY);
	if (fd1 == -1)
		return (perror(strerror(errno)), unlink(infile_bonus), 0);
	if (dup2(fd1, 0) == -1)
		return (perror(strerror(errno)), unlink(infile_bonus), close(fd1),
			close(pipex.fd2), free(pipex.pid), 0);
	close(fd1);
	ft_pipex_loop(pipex);
	unlink(infile_bonus);
	return (0);
}
