/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:16 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/16 14:10:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	hold[2];
	int	index[3];

	index[2] = 1;
	while (index[2] < size)
	{
		index[0] = 0;
		hold[0] = -2147483648;
		while (index[0] <= size - index[2])
		{
			if (hold[0] < tab[index[0]])
			{
				hold[0] = tab[index[0]];
				index[1] = index[0];
				hold[1] = tab[size - index[2]];
			}
			index[0]++;
			if (index[0] > size - index[2])
			{
				tab[size - index[2]] = hold[0];
				tab[index[1]] = hold[1];
			}
		}
		index[2]++;
	}
}

/*int	main(void)
{
	int	array[] = {-123, -7, -876, -2147483648, -876, -2147483648};
	int	i;
	int	size;

	i = 0;
	size = 6;
	ft_sort_int_tab(array, size);
	while (i != size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}*/
