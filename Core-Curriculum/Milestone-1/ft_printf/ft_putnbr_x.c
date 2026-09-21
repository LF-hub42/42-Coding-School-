/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:18:28 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 17:53:56 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned long long nbr, char c)
{
	char	*base;
	int		base_len;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
		count += ft_putnbr_x(nbr / base_len, c);
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}
// Gibt eine Zahl im bestimmten Zahlensystem (meist Hexadezimal)
// aus und zählt,wie viele Zeichen ausgegeben wurden.
