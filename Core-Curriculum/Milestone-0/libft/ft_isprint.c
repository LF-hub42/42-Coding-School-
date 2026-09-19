/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:16:03 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 21:25:19 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prüft, ob ein Zeichen druckbar ist.
// Druckbare Zeichen sind alle Zeichen mit ASCII-Werten von 32 bis 126,
// also alle sichtbaren Zeichen inklusive Leerzeichen.

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
