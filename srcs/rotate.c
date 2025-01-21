/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:11:35 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 09:29:34 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	ft_set_stack_position(*stack);
}

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	ra_silent(t_stack **stack_a)
{
	rotate(stack_a);
	return (1);
}

int	rb_silent(t_stack **stack_b)
{
	rotate(stack_b);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	ft_printf("rr\n");
	return (1);
}
