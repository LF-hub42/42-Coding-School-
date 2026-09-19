/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:18:16 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 17:18:19 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// Die Funktion ft_putchar_fd schreibt direkt ein einzelnes Zeichen
// auf einen angegebenen Ausgabekanal
// (File Descriptor), z. B. Standardausgabe oder Standardfehler.
// Gibt ein einzelnes Zeichen c auf dem
// angegebenen File Descriptor fd aus
