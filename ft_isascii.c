/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:58:03 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 16:34:47 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prüft, ob ein Zeichen ein ASCII-Zeichen ist(0-127)
int	ft_isascii(int character)
{
	// Wenn der Wert zwischen 0 und 127 liegt ,gültiges ASCII Zeichen
	if (character >= 0 && character <= 127)
		return (1);  // true,ist ASCII
	return (0);      // false,ist kein ASCII
}
