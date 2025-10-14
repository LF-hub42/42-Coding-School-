/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:43:23 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/14 15:35:16 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// #include <unistd.h>

// int	main(void)
// {
// 	int	rv;

// 	rv = ft_isalpha('c');
// 	if (rv == 1)
// 		write(1, "yes it is a letter", 18);
// 	else
// 		write(1, "nein, es ist kein Buchstabe", 27);
// 	return (1);
// }
