/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:43:25 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 17:09:35 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// Check auf NULL:
// Wenn s NULL ist, passiert nichts.

// String ausgeben:
// write(fd, s, ft_strlen(s));

// fd wohin geschrieben wird

// s Startadresse des Strings

// ft_strlen(s) Länge des Strings in Bytes
// Gibt den String s auf dem File Descriptor fd aus.
// Parameter:
// s Der auszugebende String.
// fd Der File Descriptor (z.B. 1 für stdout, 2 für stderr).


