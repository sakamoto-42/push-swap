/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:22 by julien            #+#    #+#             */
/*   Updated: 2025/01/21 14:14:18 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rotation	ft_count_rotations_to_top(t_stack *stack, t_stack *elem)
{
	t_rotation	rotations;
	int	size;

	rotations.count = 0;
	rotations.direction = 0;
	if (!stack || !elem)
		return (rotations);
	size = ft_get_stack_size(stack);
	if (elem->position <= size / 2)
	{
		rotations.count = elem->position;
		rotations.direction = 'u';
	}
	else
	{
		rotations.count = size - elem->position;
		rotations.direction = 'd';
	}
	return (rotations);
}

int	ft_count_total_rotations(t_rotation	rotations_a, t_rotation rotations_b)
{
	int	total_rotations;

	if ((rotations_a.direction == 'u' && rotations_b.direction == 'u') || (rotations_a.direction == 'd' && rotations_b.direction == 'd'))
	{
		if (rotations_a.count > rotations_b.count)
			total_rotations = rotations_a.count;
		else
			total_rotations = rotations_b.count;
	}
	else
		total_rotations = rotations_a.count + rotations_b.count;
	return (total_rotations);
}

void	ft_rotate_to_top_simple(t_stack **stack, t_stack *elem, char stack_name)
{
	int		size;

	if (!elem)
		return ;
	size = ft_get_stack_size(*stack);
	if (elem->position <= size / 2)
	{
		while (elem->position != 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
	}
	else
	{
		while (elem->position != 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
	}
}

void	ft_rotate_to_top_double(t_stack **stack_a, t_rotation *rotations_a, t_stack **stack_b, t_rotation *rotations_b)
{
	int	min_rotations;

	if (rotations_a->direction == 'u' && rotations_b->direction == 'u')
	{
		if (rotations_a->count < rotations_b->count)
			min_rotations = rotations_a->count;
		else
			min_rotations = rotations_b->count;
		rotations_a->count -= min_rotations;
		rotations_b->count -= min_rotations;
		while (min_rotations > 0)
		{
			rr(stack_a, stack_b);
			min_rotations--;
		}
	}
	else if (rotations_a->direction == 'd' && rotations_b->direction == 'd')
	{
		if (rotations_a->count < rotations_b->count)
			min_rotations = rotations_a->count;
		else
			min_rotations = rotations_b->count;
		rotations_a->count -= min_rotations;
		rotations_b->count -= min_rotations;
		while (min_rotations > 0)
		{
			rrr(stack_a, stack_b);
			min_rotations--;
		}
	}
	while (rotations_a->count > 0)
	{
		if (rotations_a->direction == 'u')
			ra(stack_a);
		else
			rra(stack_a);
		rotations_a->count--;
	}
	while (rotations_b->count > 0)
	{
		if (rotations_b->direction == 'u')
			rb(stack_b);
		else
			rrb(stack_b);
		rotations_b->count--;
	}
}