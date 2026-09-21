/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:01:06 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 17:32:56 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	addr = (unsigned long long)ptr;
	count = ft_putstr_fd("0x", 1);
	count += ft_putnbr_x(addr, 'x');
	return (count);
}
// ft_putptr() gibt den Wert eines Zeigers formatiert als
// Hexadezimaladresse aus, ähnlich wie printf("%p", ptr)
