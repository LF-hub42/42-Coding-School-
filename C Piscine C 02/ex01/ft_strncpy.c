/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:35:00 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 15:35:06 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	start;

	start = 0;
	while (src[start] != '\0' && start < n)
	{
		dest[start] = src[start];
		start++;
	}
	while (start < n)
	{
		dest[start] = '\0';
		start++;
	}
	return (dest);
}

// int main (void)
// {
// 	char s1[] = "Hello";
// 	char s2[] = "World";

// 	printf("%s", ft_strncpy(s2, s1, 0));

// 	return (0);
// }