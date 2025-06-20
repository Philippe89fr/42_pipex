/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:26:28 by prambaud          #+#    #+#             */
/*   Updated: 2025/01/10 10:06:46 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_check(char **av)
{
	if (access(av[1], W_OK | R_OK) != -1)
		return (1);
	else
	{
		ft_printf("I don't have permission ou fichier n existe pas\n");
		return (0);
	}
}

char	**ft_add_backslash(char **path)
{
	int		i;
	int		k;
	char	**new_path;

	k = 0;
	i = ft_strlen2((const char **)path);
	new_path = malloc((i + 1) * sizeof(char *));
	if (!new_path)
		return (NULL);
	new_path[i] = NULL;
	while (path[k])
	{
		new_path[k] = ft_strjoin(path[k], "/");
		k++;
	}
	return (new_path);
}

char	**ft_path(char **env)
{
	int		i;
	int		j;
	char	*str;
	char	**path;
	char	**new_path;

	i = 0;
	j = 0;
	while (!ft_strnstr(env[i], "PATH", 6))
		i++;
	while (env[i][j])
		j++;
	str = ft_substr(env[i], 5, j - 4);
	path = ft_split(str, ':');
	new_path = ft_add_backslash(path);
	free(str);
	ft_liberator_max(path);
	return (new_path);
}

void	close_inherited_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_list2	pipex;

	close_inherited_fds();
	pipex.ac = ac;
	pipex.av = av;
	pipex.env = env;
	if (pipex.ac != 5)
		return (0);
	pipex.pid = malloc((pipex.ac - 3) * sizeof(pid_t));
	if (!pipex.pid)
		return (0);
	ft_mandatory(pipex);
	free(pipex.pid);
	return (0);
}
