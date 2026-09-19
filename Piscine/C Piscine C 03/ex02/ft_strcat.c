/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:40:20 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 16:40:47 by ekypraio         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	src_lenght;
	int	dest_lenght;

	src_lenght = 0;
	dest_lenght = strlenght(dest);
	while (src[src_lenght] != '\0')
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
// 	char	src[30] = "Helloooo";
// 	char	dest[] = "world!";

// 	printf("%s", ft_strcat(src, dest));
// 	return (0);
// }