/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:58:44 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/20 11:08:15 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*g_stash = NULL;

char	*ft_liberator(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
	return (NULL);
}

int	ft_endoflinecheck(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_takeright(char *str)
{
	int		i;
	int		j;
	char	*stash;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (str[i] != '\n' && str[i])
		i++;
	if (i == j)
		return (NULL);
	stash = ft_substr2(str, i + 1, j - i);
	return (stash);
}

char	*ft_takeleft(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	str = ft_substr2(stash, 0, i + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	char *(str) = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	int (i) = ft_read_line(fd, &str);
	if (i == -1)
	{
		if (g_stash)
			free(g_stash);
		g_stash = NULL;
		free(str);
		return (NULL);
	}
	char *(str2) = ft_strjoin2(g_stash, str);
	if (str2[0] == '\0')
		return (ft_liberator(str, g_stash, str2));
	free(g_stash);
	g_stash = ft_takeright(str2);
	free(str);
	char *(str1) = ft_takeleft(str2);
	free(str2);
	return (str1);
}
