/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:31 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 14:41:28 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_node(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = ft_create_node(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	ft_set_index(t_stack *stack_a)
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

void	ft_free_lst(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	ft_stack_size(t_stack *stack)
{
	int		count;

	if (!stack)
		return (0);
	count = 1;
	while (stack->next)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
