/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:20 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/13 14:25:20 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int				ft_printf(const char *s, ...);
int				ft_sizeint(int nb);
int				ft_putstr(char *str);
int				ft_putnbr(int nb, int k);
int				ft_putnbru(unsigned int nb, int k);
int				ft_printhex(unsigned int nb, int k);
int				ft_printhexx(unsigned int nb, int k);
int				ft_printpointer(void *p);

#endif
