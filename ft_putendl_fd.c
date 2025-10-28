/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:32 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 20:12:46 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

//ft_putendl_fd:
//Gibt den String 's' auf dem File Descriptor 'fd' aus,
//gefolgt von einem '\n'

//Parame.:
//s -Der auszugebende String
//fd-Der File Descriptor
//(z.B. 1 für stdout, 2 für stderr)

//Rückgabew.:
//None
//Hinweis:
//Die Funktion verwendet write() direkt
//und beendet den String mit '\n'
