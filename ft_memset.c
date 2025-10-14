/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:26:40 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/14 19:59:43 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	void			*r;
	unsigned char	byte;

	byte = c;
	i = 0;
	r = s;
	while (n > i)
	{
		*(unsigned char *)s = byte;
		i++;
		s++;
	}
	return (r);
}
