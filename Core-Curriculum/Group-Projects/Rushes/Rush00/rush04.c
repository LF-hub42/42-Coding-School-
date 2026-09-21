/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:14:54 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/04 00:37:40 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_string(char *buffer)
{
	while (*buffer != '\0')
	{
		write(1, &(*buffer), 1);
		buffer++;
	}
}

int	jank(int x, int y, int x1, int y1)
{
	if ((x1 > 0 && x1 < x - 1) && (y1 == 0 || y1 == y - 1))
		ft_putchar('B');
	return (1);
}

void	row(int x, int y, int x1, int y1)
{
	while (++x1 <= x - 1)
	{
		if (y1 == 0 && jank(x, y, x1, y1))
		{
			if (x1 == 0)
				ft_putchar('A');
			else if (x1 == x - 1)
				ft_putchar('C');
		}
		else if (y1 == y - 1 && jank(x, y, x1, y1))
		{
			if (x1 == 0)
				ft_putchar('C');
			else if (x1 == x - 1)
				ft_putchar('A');
		}	
		else
		{
			if (x1 == 0 || x1 == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
	}
}

void	rush(int x, int y)
{
	int	x1;
	int	y1;

	if (x > 0 && y > 0)
	{
		y1 = 0;
		while (y1 <= y - 1)
		{
			x1 = -1;
			row(x, y, x1, y1);
			y1++;
			ft_putchar('\n');
		}
	}
	else
	{
		print_string("ERROR: Invalid parameters");
	}
}
