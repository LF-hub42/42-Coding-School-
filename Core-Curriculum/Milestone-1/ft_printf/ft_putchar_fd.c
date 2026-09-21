/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:08:22 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 17:55:03 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
// chreibt ein einzelnes Zeichen(c)auf einen bestimmten
// Dateideskriptor(fd)also z. B. auf die Konsole oder in eine Datei.
