/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:52:54 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/30 00:15:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*ptr;
	unsigned char		to_find;

	ptr = (unsigned char *)s;
	to_find = (unsigned char)c;
	i = 0;
	if (n != 0)
	{
		n--;
		while (n != 0 && ptr[i] != to_find)
		{
			n--;
			i++;
		}
		if (ptr[i] == to_find)
			return ((void *)(ptr + i));
	}
	return (NULL);
}

// int main (void)
// {
// 	char k[17] = "01234567890abcdef";
// 	char *b = (char*)ft_memchr(k,'4',7);
// 	printf("%s\n",k);
// 	printf("%s",b);
// }
