/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:17:06 by ekypraio          #+#    #+#             */
/*   Updated: 2026/01/10 22:17:13 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	sa(t_stack **a)
{
	int	tmp_v;
	int	tmp_i;

	if (!*a || !(*a)->next)
		return ;
	tmp_v = (*a)->value;
	tmp_i = (*a)->index;
	(*a)->value = (*a)->next->value;
	(*a)->index = (*a)->next->index;
	(*a)->next->value = tmp_v;
	(*a)->next->index = tmp_i;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp_v;
	int	tmp_i;

	if (!*b || !(*b)->next)
		return ;
	tmp_v = (*b)->value;
	tmp_i = (*b)->index;
	(*b)->value = (*b)->next->value;
	(*b)->index = (*b)->next->index;
	(*b)->next->value = tmp_v;
	(*b)->next->index = tmp_i;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
