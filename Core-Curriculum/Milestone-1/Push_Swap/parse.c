/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:18:11 by ekypraio          #+#    #+#             */
/*   Updated: 2026/01/10 22:18:13 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_ps(const char *str, t_stack **a)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		error_exit(a, NULL);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error_exit(a, NULL);
		res = res * 10 + (*str - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			error_exit(a, NULL);
		str++;
	}
	return (res * sign);
}

static void	check_duplicates(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			error_exit(&a, NULL);
		a = a->next;
	}
}

void	parse_input(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi_ps(argv[i], a);
		check_duplicates(*a, (int)num);
		new = ft_lstnew((int)num);
		if (!new)
			error_exit(a, NULL);
		ft_lstadd_back(a, new);
		i++;
	}
}
