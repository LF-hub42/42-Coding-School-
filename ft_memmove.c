/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:34:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 00:47:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t number_of_bytes)
{
	if (!dest && !source)
		return (NULL);
	if (source < dest)
	{
		while (number_of_bytes--)
		{
			((unsigned char *)dest)[number_of_bytes] = ((const unsigned char *)source)[number_of_bytes];
		}
	}
	else
	{
		ft_memcpy(dest, source, number_of_bytes);
	}
	return (dest);
}
//memmove() kopiert n Bytes von einer Quelle in ein Ziel,
//auch wenn sich die Speicherbereiche überlappen.Dazu werden
//die Daten zuerst in einen temporären Zwischenspeicher kopiert
//und dann sicher ins Ziel übertragen.
