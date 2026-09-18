/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:41:20 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 16:42:28 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strlenght(char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	src_lenght;
	unsigned int	dest_lenght;

	src_lenght = 0;
	dest_lenght = strlenght(dest);
	while (src[src_lenght] != '\0' && src_lenght < nb)
	{
		dest[dest_lenght + src_lenght] = src[src_lenght];
		src_lenght++;
	}
	dest[dest_lenght + src_lenght] = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[30] = "world!";
// 	char	dest[] = "Hello, ";

// 	printf("%s", ft_strncat(dest, src, 3));
// 	return (0);
// }