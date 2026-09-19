/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:21:59 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 16:26:57 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		nb = nb + '0';
		write(fd, &nb, 1);
	}
}
// Funktion ft_putnbr_fd nimmt zwei Parameter:
// n: die Zahl, die ausgegeben werden soll
// fd: der Dateideskriptor, auf den geschrieben wird
// (z.B. 1 = stdout, 2 = stderr)
// Rückgabewert ist void, also gibt sie nichts zurück.
//fd=file descriptor
