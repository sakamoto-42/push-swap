/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:55:22 by julien            #+#    #+#             */
/*   Updated: 2025/01/21 16:08:12 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_set_min_rotations(t_rotation *rotations_a,
	t_rotation *rotations_b, int *min_rotations)
{
	if (rotations_a->count < rotations_b->count)
		*min_rotations = rotations_a->count;
	else
		*min_rotations = rotations_b->count;
	rotations_a->count -= *min_rotations;
	rotations_b->count -= *min_rotations;
}

void	ft_rotate_double(int (*do_rot)(t_stack **, t_stack **),
			t_stack **stack_a, t_stack **stack_b, int *min_rotations)
{
	while (*min_rotations > 0)
	{
		do_rot(stack_a, stack_b);
		(*min_rotations)--;
	}
}

void	ft_rotate_simple(t_stack **stack, t_rotation *rotations,
			char stack_name)
{
	while (rotations->count > 0)
	{
		if (rotations->direction == 'u')
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
		rotations->count--;
	}
}

void	ft_rotate_to_top_double(t_stack **stack_a, t_rotation *rotations_a,
	t_stack **stack_b, t_rotation *rotations_b)
{
	int	min_rotations;

	if (rotations_a->direction == 'u' && rotations_b->direction == 'u')
	{
		ft_set_min_rotations(rotations_a, rotations_b, &min_rotations);
		ft_rotate_double(rr, stack_a, stack_b, &min_rotations);
	}
	else if (rotations_a->direction == 'd' && rotations_b->direction == 'd')
	{
		ft_set_min_rotations(rotations_a, rotations_b, &min_rotations);
		ft_rotate_double(rrr, stack_a, stack_b, &min_rotations);
	}
	ft_rotate_simple(stack_a, rotations_a, 'a');
	ft_rotate_simple(stack_b, rotations_b, 'b');
}
