/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:22 by julien            #+#    #+#             */
/*   Updated: 2025/01/16 08:56:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stack_a_to_top(t_stack *stack, int *n,
	int (**move)(t_stack **))
{
	*n = stack->position;
	*move = ra;
}

void	ft_reverse_rotate_stack_a_to_top(t_stack *stack, int size,
	int *n, int (**move)(t_stack **))
{
	*n = size - stack->position;
	*move = rra;
}

void	ft_rotate_stack_b_to_top(t_stack *stack, int *n,
	int (**move)(t_stack **))
{
	*n = stack->position;
	*move = rb;
}

void	ft_reverse_rotate_stack_b_to_top(t_stack *stack, int size,
	int *n, int (**move)(t_stack **))
{
	*n = size - stack->position;
	*move = rrb;
}
