/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:46 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/30 14:36:16 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT);
	if (fd == -1)
		return (1);
	ft_putchar_fd('c', fd);	
	return (0);
} */
