/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:41:59 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/02 17:49:31 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	temp = NULL;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*lst = NULL;
}
