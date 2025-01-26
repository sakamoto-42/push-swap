/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/26 15:44:04 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_stack_a;

	min_stack_a = ft_find_stack_min(*stack_a);
	ft_rotate_to_top_simple(stack_a, min_stack_a, 'a');
	if (!ft_check_sorted(*stack_a, *stack_b))
	{
		pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_stack_a;

	ft_stack_a_to_stack_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_stack_b_to_stack_a(stack_a, stack_b);
	min_stack_a = ft_find_stack_min(*stack_a);
	ft_rotate_to_top_simple(stack_a, min_stack_a, 'a');
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else
		ft_sort_big(stack_a, stack_b);
}
