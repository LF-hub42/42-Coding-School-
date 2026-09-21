/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:58:03 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 17:48:12 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count = count + ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		count = count + ft_putnbr_fd(num / 10, fd);
	count = count + ft_putchar_fd((num % 10) + '0', fd);
	return (count);
}
// gibt eine Ganzzahl (int) Zeichen für Zeichen auf einen
// bestimmten Dateideskriptor (fd) aus (z. B. 1 für die Konsole)
// Wenn die Zahl negativ ist → '-' ausgeben und positiv machen.
// Jede Ziffer wird durch ft_putchar_fd() als Zeichen geschrieben.
// Gibt zurück, wie viele Zeichen insgesamt ausgegeben wurden.
