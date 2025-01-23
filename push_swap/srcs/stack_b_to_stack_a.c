/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:24:19 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/23 08:20:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_in_stack_a(t_stack *stack_a, int index_b)
{
	t_stack	*current;

	current = stack_a;
	while (current->next)
	{
		if (current->index < index_b && current->next->index > index_b)
			return (current->next);
		current = current->next;
	}
	return (NULL);
}

t_stack	*ft_get_target_a(t_stack *current_b, t_stack *stack_a)
{
	t_stack		*min_stack_a;
	t_stack		*max_stack_a;

	min_stack_a = ft_find_stack_min(stack_a);
	max_stack_a = ft_find_stack_max(stack_a);
	if ((current_b->index < min_stack_a->index)
		|| (current_b->index > max_stack_a->index))
		return (min_stack_a);
	else
		return (find_target_in_stack_a(stack_a, current_b->index));
}

t_stack_b_to_a	ft_get_best_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack			*current_b;
	int				min_cost;
	t_stack_b_to_a	info;
	t_stack_b_to_a	best_info;

	current_b = *stack_b;
	min_cost = INT_MAX;
	while (current_b)
	{
		info.current_b = current_b;
		info.target_a = ft_get_target_a(current_b, *stack_a);
		info.rotations_a = ft_count_rotations_to_top(*stack_a, info.target_a);
		info.rotations_b = ft_count_rotations_to_top(*stack_b, info.current_b);
		info.total_rotations = ft_count_total_rotations(info.rotations_a,
				info.rotations_b);
		if (info.total_rotations < min_cost)
		{
			min_cost = info.total_rotations;
			best_info = info;
		}
		current_b = current_b->next;
	}
	return (best_info);
}

void	ft_stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack_b_to_a	best;
	int				size;

	size = ft_get_stack_size(*stack_b);
	while (size)
	{
		best = ft_get_best_b_to_a(stack_a, stack_b);
		ft_rotate_to_top_double(stack_a, &best.rotations_a,
			stack_b, &best.rotations_b);
		pa(stack_a, stack_b);
		size--;
	}
}
