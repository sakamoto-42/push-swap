/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_to_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:23:35 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 16:43:44 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_in_stack_b(t_stack *stack_b, int index_a)
{
	t_stack	*current;

	current = stack_b;
	while (current->next)
	{
		if (current->index > index_a && current->next->index < index_a)
			return (current->next);
		current = current->next;
	}
	return (NULL);
}

t_stack	*ft_get_target_b(t_stack *current_a, t_stack *stack_b)
{
	t_stack	*min_stack_b;
	t_stack	*max_stack_b;

	min_stack_b = ft_find_stack_min(stack_b);
	max_stack_b = ft_find_stack_max(stack_b);
	if ((current_a->index < min_stack_b->index)
		|| (current_a->index > max_stack_b->index))
		return (max_stack_b);
	else
		return (find_target_in_stack_b(stack_b, current_a->index));
}

t_stack_a_to_b	ft_get_best_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack				*current_a;
	int					min_cost;
	t_stack_a_to_b		info;
	t_stack_a_to_b		best_info;

	current_a = *stack_a;
	min_cost = INT_MAX;
	while (current_a)
	{
		info.current_a = current_a;
		info.target_b = ft_get_target_b(current_a, *stack_b);
		info.rotations_a = ft_count_rotations_to_top(*stack_a, info.current_a);
		info.rotations_b = ft_count_rotations_to_top(*stack_b, info.target_b);
		info.total_rotations = ft_count_total_rotations(info.rotations_a,
				info.rotations_b);
		if (info.total_rotations < min_cost)
		{
			min_cost = info.total_rotations;
			best_info = info;
		}
		current_a = current_a->next;
	}
	return (best_info);
}

void	ft_stack_a_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack_a_to_b		best;
	int					size;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	size = ft_get_stack_size(*stack_a);
	while (size > 3)
	{
		best = ft_get_best_a_to_b(stack_a, stack_b);
		ft_rotate_to_top_double(stack_a, &best.rotations_a,
			stack_b, &best.rotations_b);
		pb(stack_a, stack_b);
		size--;
	}
}
