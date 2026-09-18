/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:06:42 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/16 14:17:20 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	howlong;
	int	startval;
	int	endval;

	index = 0;
	howlong = size / 2;
	while (howlong > 0)
	{
		size--;
		startval = tab[size];
		endval = tab[index];
		tab[size] = endval;
		tab[index] = startval;
		index++;
		howlong--;
	}
}

/*int	main(void)
{
	int	array[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int	i;
	int	size;

	i = 0;
	size = 9;
	ft_rev_int_tab(array, size);
	while (i != size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}*/
