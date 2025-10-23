/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:15:22 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 21:16:16 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		n;

	n = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * n);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, n);
	return (dup);
}
