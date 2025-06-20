/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liberator_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:32:07 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/12 16:20:53 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_liberator_part(char **tab, int k)
{
	int	i;

	i = 0;
	while (i <= k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
