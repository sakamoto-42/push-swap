/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:55:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 16:13:50 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rotation	ft_count_rotations_to_top(t_stack *stack, t_stack *elem)
{
	t_rotation	rotations;
	int			size;

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

	if ((rotations_a.direction == 'u' && rotations_b.direction == 'u')
		|| (rotations_a.direction == 'd' && rotations_b.direction == 'd'))
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
