/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:34:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 15:35:03 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_stack_a(t_stack **stack_a, char **strs)
{
	int		i;
	int		value;

	i = 0;
	while (strs[i])
	{
		value = ft_atoi(strs[i]);
		if (!ft_is_unique(*stack_a, value))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_stack(*stack_a);
			return (0);
		}
		ft_add_stack(stack_a, value);
		i++;
	}
	ft_free_strs(strs);
	ft_set_stack_index(*stack_a);
	ft_set_stack_position(*stack_a);
	return (1);
}

void	ft_set_stack_index(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*temp;
	int		index;

	if (!stack_a)
		return ;
	current = stack_a;
	while (current)
	{
		index = 1;
		temp = stack_a;
		while (temp)
		{
			if (temp->value < current->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_set_stack_position(t_stack *stack)
{
	int	position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}
