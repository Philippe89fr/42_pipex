/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:15:06 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/05 13:48:58 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			j;
	long long	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			j++;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 - '0' + nptr[i];
		i++;
	}
	if (j % 2 != 0)
		nb = nb * (-1);
	return (nb);
}
/*
int	main (int argc, char **argv)
{
	char	*str = argv[1];

	argc = argc + 0;
	printf("%lld\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
} */
