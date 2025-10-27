/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:34:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 01:04:58 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (n--)
			((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

//memmove() kopiert n Bytes von einer Quelle in ein Ziel,
//auch wenn sich die Speicherbereiche überlappen.Dazu werden
//die Daten zuerst in einen temporären Zwischenspeicher kopiert
//und dann sicher ins Ziel übertragen.
