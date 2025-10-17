/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:43:36 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/16 22:05:50 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// size_t	ft_strlcpy(char *dst, const char *src, int size)
// {
// 	int	i;

// 	i = 0;
// 	char *tmp;
// 	tmp = dst;
// 	while (*tmp && i < size)
// 	{
// 		*tmp = *src;
// 		tmp++;
// 		src++;
// 		i++;
// 	}

// 	return (strlen(*src));
// }
#include <string.h>
#include<stdio.h>
int	main(void)
{
	char	*dst = "00000000000000";
	char	*src = "Hello World";

	printf("dst war: %s, \n src war: %s \n",dst, src);

	printf("%d", strlcpy(dst, src, 5));
	printf("%s", dst);
	return (0);
}
