/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/16 20:05:51 by julien           ###   ########.fr       */
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

int	has_valid_range(t_stack *stack_b, int index)
{
	t_stack	*current;

	current = stack_b;
	while (current->next)
	{
		if (current->index > index && current->next->index < index)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_rotate_to_top(t_stack **stack, t_stack *elem, char stack_name)
{
	int		size;

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

void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*max_stack_b;
	t_stack	*min_stack_b;
	t_stack	*current;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (size - 2 > 3)
	{
		min_stack_b = ft_find_stack_min(*stack_b);
		max_stack_b = ft_find_stack_max(*stack_b);
		if ((*stack_a)->index > max_stack_b->index)
		{
			ft_rotate_to_top(stack_b, max_stack_b, 'b');
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->index < min_stack_b->index)
		{
			ft_rotate_to_top(stack_b, max_stack_b, 'b');
			pb(stack_a, stack_b);
		}
		else
		{
			if (has_valid_range(*stack_b, (*stack_a)->index))
			{
				current = *stack_b;
				while (current->next)
				{
					if (current->index > (*stack_a)->index
						&& current->next->index < (*stack_a)->index)
					{
						ft_rotate_to_top(stack_b, current->next, 'b');
						break ;
					}
					current = current->next;
				}
				pb(stack_a, stack_b);
			}
			else
				pb(stack_a, stack_b);
		}
		size--;
	}
	ft_sort_three(stack_a);


	t_stack *max_stack_a;
	t_stack *min_stack_a;
	t_stack *target;
	while (*stack_b)
	{
		int index_b = (*stack_b)->index;
		min_stack_a = ft_find_stack_min(*stack_a);
		max_stack_a = ft_find_stack_max(*stack_a);
		if ((*stack_b)->index > max_stack_a->index)
		{
			ft_rotate_to_top(stack_a, min_stack_a, 'a');
			pa(stack_a, stack_b);
		}
		else if ((*stack_a)->index > index_b && is_closest_sup(*stack_a, (*stack_a)->index, index_b))
			pa(stack_a, stack_b);
		else
		{
			target = find_closest_sup(*stack_a, index_b);
			while ((*stack_a)->index != target->index)
				ft_rotate_to_top(stack_a, target, 'a');
			pa(stack_a, stack_b);
		}
	}
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
		ft_sort_medium(stack_a, stack_b, size);
}
