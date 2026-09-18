/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:56:14 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/16 14:14:14 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// 	int	main(void)
// {
// 	int	a = 10;
// 	int	b = 2;

// 	ft_ultimate_div_mod(&a, &b);
// 	printf("a: %d \nb: %d", a, b);
// }
