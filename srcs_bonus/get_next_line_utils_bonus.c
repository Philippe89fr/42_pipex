/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:33:47 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/17 14:34:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_size(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	t;

	t = 0;
	while (s[t])
		t++;
	j = 0;
	while ((start + j) < t && j < len)
		j++;
	return (j);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*tab;

	size_t(i) = 0;
	size_t(t) = 0;
	while (s[t])
		t++;
	if (start > t)
	{
		tab = (char *)malloc((1) * sizeof(char));
		if (tab == 0)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	tab = (char *)malloc((ft_size(s, start, len) + 1) * sizeof(char));
	if (tab == 0)
		return (NULL);
	while (start + i < t && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*ft_malloc1(char *s1, char *s2)
{
	int		j;
	int		i;
	int		k;
	char	*tab;

	i = 0;
	k = 0;
	while (s2[i])
		i++;
	if (!s1)
	{
		tab = (char *)malloc((i + 1) * sizeof(char));
		if (tab == NULL)
			return (NULL);
		return (tab);
	}
	while (s1[k])
		k++;
	j = i + k;
	tab = (char *)malloc((j + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char *(tab) = ft_malloc1(s1, s2);
	if (tab == NULL)
		return (NULL);
	int (i) = -1;
	int (j) = 0;
	if (!s1)
	{
		while (s2[j])
		{
			tab[i + j + 1] = s2[j];
			j++;
		}
		tab[i + j + 1] = '\0';
		return (tab);
	}
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[j])
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}

int	ft_read_line(int fd, char **str)
{
	char	*temp;

	int (count_read) = -1;
	int (a) = 0;
	char *(buf) = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	buf[0] = '\0';
	while (!ft_endoflinecheck(buf) && count_read != 0)
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(buf);
			return (-1);
		}
		buf[count_read] = '\0';
		temp = ft_strjoin2(*str, buf);
		free(*str);
		*str = temp;
	}
	if (count_read == 0)
		a = 1;
	free(buf);
	return (a);
}
