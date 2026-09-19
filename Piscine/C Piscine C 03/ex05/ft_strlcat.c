/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:47:21 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 16:48:49 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	c;

	i = 0;
	k = 0;
	c = 0;
	while (dest[k] && k < size)
	{
		k++;
		c++;
	}
	while (src[i] && k + 1 < size)
	{
		dest[k] = src[i];
		i++;
		k++;
	}
	dest[k] = '\0';
	while (*src != '\0')
	{
		c++;
		src++;
	}
	return (c);
}

// #include <stdint.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *src = "Test";
// 	char des[] = "Test";
// 	int n = 10;
// 	ft_strlcat(des, src, n);
// 	printf("%d", ft_strlcat(des, src, n));
// 	printf("%s%s\n\n", des, src);
// }