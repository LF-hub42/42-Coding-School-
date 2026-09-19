/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:43:02 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/13 16:39:44 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*#include <stdio.h>
int main()
{
	int *a;
	int *b;
	a = 5;
	b= 7;

	printf("a was: %d\n", a);
	printf("b was: %d\n", b);
	ft_swap(&a, &b);
	printf("a now is: %d\n", a);
	printf("b now is: %d\n", b);
	
}*/