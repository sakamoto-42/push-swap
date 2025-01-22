/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:34:05 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 19:12:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
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
}

int	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	return (1);
}
