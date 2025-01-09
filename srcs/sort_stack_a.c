/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 10:15:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_a_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_stack_a_three_a_inf_b(t_stack **stack_a, int a, int c)
{
	if (a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		rra(stack_a);
}

void	ft_sort_stack_a_three_b_inf_c(t_stack **stack_a, int a, int c)
{
	if (a < c)
		sa(stack_a);
	else
		ra(stack_a);
}

void	ft_sort_stack_a_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a < b)
		ft_sort_stack_a_three_a_inf_b(stack_a, a, c);
	else if (b < c)
		ft_sort_stack_a_three_b_inf_c(stack_a, a, c);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	ft_sort_stack_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	(void) stack_a;
	(void) stack_b;
	ft_printf("%d", size);
}
