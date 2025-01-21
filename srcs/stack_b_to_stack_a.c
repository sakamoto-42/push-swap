/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:24:19 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 14:24:26 by juduchar         ###   ########.fr       */
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
void	ft_stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	
	int		min_cost;
	t_stack	*best_b;
	t_stack	*best_target_a;
	
	t_stack	*target_a;
	int		rotations;
	t_stack *min_stack_a;
	t_stack *max_stack_a;

	t_rotation	rotations_a;
	t_rotation	rotations_b;

	int size = ft_get_stack_size(*stack_b);
	while (size)
	{
		current_b = *stack_b;
		min_cost = INT_MAX;
		best_b = NULL;
		best_target_a = NULL;
		while (current_b)
		{
			min_stack_a = ft_find_stack_min(*stack_a);
			max_stack_a = ft_find_stack_max(*stack_a);
			if ((current_b->index < min_stack_a->index) || (current_b->index > max_stack_a->index))
				target_a = ft_find_stack_min(*stack_a);
			else
				target_a = find_target_in_stack_a(*stack_a, current_b->index);
			rotations_a = ft_count_rotations_to_top(*stack_a, target_a);
			rotations_b = ft_count_rotations_to_top(*stack_b, current_b);
			rotations = ft_count_total_rotations(rotations_a, rotations_b);
			if (rotations < min_cost)
			{
				min_cost = rotations;
				best_b = current_b;
				best_target_a = target_a;
			}
			current_b = current_b->next;
		}
		rotations_a = ft_count_rotations_to_top(*stack_a, best_target_a);
		rotations_b = ft_count_rotations_to_top(*stack_b, best_b);
		ft_rotate_to_top_double(stack_a, &rotations_a, stack_b, &rotations_b);
		pa(stack_a, stack_b);
		size--;
	}
}