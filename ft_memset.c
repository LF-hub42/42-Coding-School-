/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:26:40 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/15 23:00:52 by ekypraio         ###   ########.fr       */
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
	while (i < n)
	{
		*(unsigned char *)s = byte;
		i++;
		s++;
	}
	return (r);
}

#include <unistd.h>
#include <stdlib.h>

// int	main(void)
// {
// 	char	*string;
// 	void	*ptr;

// 	string = malloc(sizeof(char) * 5);
// 	ptr = string;
// 	string[0] = 'a';
// 	string[1] = 'b';
// 	string[2] = 'c';
// 	string[3] = 'd';
// 	string[4] = '\0';
// 	write(1, ptr, 9);
// 	write(1, "\n", 1);
// 	ft_memset(ptr, 'A', 5);
// 	write(1, ptr, 9);
// 	write(1, "\n", 1);
// 	return (0);
// }
