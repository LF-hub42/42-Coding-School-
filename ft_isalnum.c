/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:09:30 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 15:34:09 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <unistd.h>

// int	main(void)
// {
// 	int	rv;

// 	rv = ft_isalnum('1');
// 	if (rv == 1)
// 		write(1, "its true", 8);
// 	return (0);
// }

// Prüft, ob ein Zeichen alphanumerisch ist.
// Das bedeutet, es ist entweder ein Buchstabe (A-Z oder a-z) oder eine Ziffer (0-9).
