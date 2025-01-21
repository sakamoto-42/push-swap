/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:17:07 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 09:30:05 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_set_stack_position(*stack);
}

int	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return (1);
}

int	rra_silent(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	return (1);
}

int	rrb_silent(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	ft_printf("rrr\n");
	return (1);
}
