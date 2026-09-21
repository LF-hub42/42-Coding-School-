/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:16:41 by ekypraio          #+#    #+#             */
/*   Updated: 2026/01/10 22:16:48 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_stack *a)
{
	t_stack	*curr;
	t_stack	*compare;
	int		idx;

	curr = a;
	while (curr)
	{
		idx = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < curr->value)
				idx++;
			compare = compare->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	parse_input(argc, argv, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_index(a);
	radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
