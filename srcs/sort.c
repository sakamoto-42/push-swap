/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 11:52:47 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	ft_sort_mini(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*stack_a_min;
	int		i;
	int		n;
	int		(*move)(t_stack **);
	int		stack_a_size;

	stack_a_size = size - 3;
	i = 0;
	while (i < stack_a_size)
	{
		stack_a_min = ft_find_stack_min(*stack_a);
		if (stack_a_min->position <= size / 2)
			ft_rotate_stack_a_to_top(stack_a_min, &n, &move);
		else
			ft_reverse_rotate_stack_a_to_top(stack_a_min, size, &n, &move);
		while (n--)
			move(stack_a);
		pb(stack_a, stack_b);
		i++;
		size--;
	}
	ft_sort_three(stack_a);
	while (ft_get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	ft_rotate_to_top(t_stack **stack, t_stack *elem, char stack_name)
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

t_stack	*find_target(t_stack *stack_a, int target_index)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		if (current->index == target_index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_stack	*find_closest_sup(t_stack *stack_a, int index_b)
{
	t_stack	*current;
	t_stack	*closest;

	current = stack_a;
	closest = NULL;
	while (current)
	{
		if (current->index > index_b)
		{
			if (!closest || current->index < closest->index)
				closest = current;
		}
		current = current->next;
	}
	return (closest);
}

int	is_closest_sup(t_stack *stack_a, int index_a, int index_b)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		if (current->index > index_b && current->index < index_a)
			return (0);
		current = current->next;
	}
	return (1);
}
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


t_rotation	ft_count_rotations_to_top_optimized(t_stack *stack, t_stack *elem)
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

void	ft_rotate_to_top_optimized(t_stack **stack_a, t_rotation *rotations_a, t_stack **stack_b, t_rotation *rotations_b)
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
			if ((current_a->index < min_stack_b->index)
				|| (current_a->index > max_stack_b->index))
				target_b = max_stack_b;
			else
				target_b = find_target_in_stack_b(*stack_b, current_a->index);
			rotations_a = ft_count_rotations_to_top_optimized(*stack_a, current_a);
			rotations_b = ft_count_rotations_to_top_optimized(*stack_b, target_b);
			rotations = ft_count_total_rotations(rotations_a, rotations_b);
			if (rotations < min_cost)
			{
				min_cost = rotations;
				best_a = current_a;
				best_target_b = target_b;
			}
			current_a = current_a->next;
		}
		rotations_a = ft_count_rotations_to_top_optimized(*stack_a, best_a);
		rotations_b = ft_count_rotations_to_top_optimized(*stack_b, best_target_b);
		ft_rotate_to_top_optimized(stack_a, &rotations_a, stack_b, &rotations_b);
		pb(stack_a, stack_b);
		size--;
	}
}

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
			rotations_a = ft_count_rotations_to_top_optimized(*stack_a, target_a);
			rotations_b = ft_count_rotations_to_top_optimized(*stack_b, current_b);
			rotations = ft_count_total_rotations(rotations_a, rotations_b);
			if (rotations < min_cost)
			{
				min_cost = rotations;
				best_b = current_b;
				best_target_a = target_a;
			}
			current_b = current_b->next;
		}
		rotations_a = ft_count_rotations_to_top_optimized(*stack_a, best_target_a);
		rotations_b = ft_count_rotations_to_top_optimized(*stack_b, best_b);
		ft_rotate_to_top_optimized(stack_a, &rotations_a, stack_b, &rotations_b);
		pa(stack_a, stack_b);
		size--;
	}
}

void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_stack_a;

	ft_stack_a_to_stack_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_stack_b_to_stack_a(stack_a, stack_b);
	min_stack_a = ft_find_stack_min(*stack_a);
	ft_rotate_to_top(stack_a, min_stack_a, 'a');
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size >= 4 && size <= 6)
		ft_sort_mini(stack_a, stack_b, size);
	else if (size >= 7)
		ft_sort_medium(stack_a, stack_b);
}
