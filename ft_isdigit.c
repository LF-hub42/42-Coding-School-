/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:45:53 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/14 15:35:29 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <unistd.h>

// int	main(void)
// {
// 	int	rv;

// 	rv = ft_isdigit('0');
// 	if (rv == 1)
// 		write(1, "Yes its a digit", 15);
// 	else
// 		write(1, "No its not a digit", 18);
// 	return (1);
// }
