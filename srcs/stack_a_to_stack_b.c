/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_to_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:23:35 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 14:23:56 by juduchar         ###   ########.fr       */
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

void	ft_stack_a_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	
	int		min_cost;
	t_stack	*best_a;
	t_stack	*best_target_b;
	
	t_stack	*target_b;
	int		rotations;
	t_stack	*min_stack_b;
	t_stack	*max_stack_b;
	
	t_rotation	rotations_a;
	t_rotation	rotations_b;
	
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

	int size = ft_get_stack_size(*stack_a);
	while (size > 3)
	{
		current_a = *stack_a;
		min_cost = INT_MAX;
		best_a = NULL;
		best_target_b = NULL;
		while (current_a)
		{
			min_stack_b = ft_find_stack_min(*stack_b);
			max_stack_b = ft_find_stack_max(*stack_b);
			if ((current_a->index < min_stack_b->index) || (current_a->index > max_stack_b->index))
				target_b = max_stack_b;
			else
				target_b = find_target_in_stack_b(*stack_b, current_a->index);
			rotations_a = ft_count_rotations_to_top(*stack_a, current_a);
			rotations_b = ft_count_rotations_to_top(*stack_b, target_b);
			rotations = ft_count_total_rotations(rotations_a, rotations_b);
			if (rotations < min_cost)
			{
				min_cost = rotations;
				best_a = current_a;
				best_target_b = target_b;
			}
			current_a = current_a->next;
		}
		rotations_a = ft_count_rotations_to_top(*stack_a, best_a);
		rotations_b = ft_count_rotations_to_top(*stack_b, best_target_b);
		ft_rotate_to_top_double(stack_a, &rotations_a, stack_b, &rotations_b);
		pb(stack_a, stack_b);
		size--;
	}
}