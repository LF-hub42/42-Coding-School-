/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:17:46 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 16:13:45 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	nsrc;
	size_t	ndst;
	size_t	cpy;

	nsrc = ft_strlen(src);
	ndst = ft_strlen(dst);
	if (ndst >= size)
		return (nsrc + size);
	if (nsrc + ndst >= size)
		cpy = size - ndst - 1;
	else
		cpy = nsrc;
	if (size > 0)
	{
		ft_memcpy(dst + ndst, src, cpy);
		dst[ndst + cpy] = '\0';
	}
	return (nsrc + ndst);
}
