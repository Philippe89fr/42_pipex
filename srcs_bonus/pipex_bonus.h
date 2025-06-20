/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:03:06 by vincent           #+#    #+#             */
/*   Updated: 2025/01/06 14:58:09 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 160
# endif

typedef struct a_list
{
	int		status;
	int		path_check;
	char	**cmd;
	char	**path;
	pid_t	*pid;
	int		pipefd[2];
	int		ac;
	int		fd2;
	int		bonus;
	int		fist;
	char	**av;
	char	**env;
}			t_list2;

void		ft_new_processus(t_list2 pipex);
void		ft_new_processus_path_included(t_list2 pipex);
int			ft_life_fils(t_list2 pipex);
int			ft_life_dernier_fils(t_list2 pipex);
int			ft_life_papa(t_list2 pipex);
int			ft_life_dernier_papa(t_list2 pipex);
char		**ft_add_backslash(char **path);
char		**ft_path(char **env);
int			ft_file_check(char **av);
int			ft_pipex_loop(t_list2 pipex);
int			ft_pipex_loop2(t_list2 pipex, int j, int i);
int			ft_mandatory(t_list2 pipex);
char		*ft_liberator(char *s1, char *s2, char *s3);
char		*ft_substr2(char const *s, unsigned int start, size_t len);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_endoflinecheck(char *buf);
char		*ft_takeright(char *str);
char		*ft_takeleft(char *stash);
int			ft_read_line(int fd, char **str);
char		*get_next_line(int fd);
void		ft_free_gnl(void);
int			ft_bonus(t_list2 pipex);
int			ft_get_input(t_list2 *pipex, int fd1);

#endif
