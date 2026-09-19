/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:06:20 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/29 13:54:52 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <stdlib.h>

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*res;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[start] && i < len)
// 		i++;
// 	res = (char *)malloc(i + 1);
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (s[start + i] && i < len)
// 	{
// 		res[i] = s[start + i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

// ft_substr() erstellt einen neuen String, der ein
// Teilstück (Substring) von s ist.

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	len_big_str;
	size_t	i;
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	len_big_str = ft_strlen(s);
	if (start >= len_big_str)
		return (ft_strdup(""));
	if (len > len_big_str - start)
		len = len_big_str - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
