/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:44:51 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 16:45:50 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	find_size;

	i = 0;
	j = 0;
	find_size = 0;
	while (to_find[find_size] != '\0')
		find_size++;
	if (find_size == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
		{
			if (j == find_size - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

// #include <unistd.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "fantasmita";
// 	char	to_find[] = "mita";

// 	printf("%s\n", ft_strstr(str, to_find));
// 	return (0);
// }	