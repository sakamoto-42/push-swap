/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:31 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 15:29:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(int value)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->next = NULL;
	return (new_stack);
}

void	ft_add_stack(t_stack **stack, int value)
{
	t_stack	*new_stack;
	t_stack	*current;

	new_stack = ft_create_stack(value);
	if (!*stack)
		*stack = new_stack;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_stack;
	}
}

void	ft_free_stack(t_stack *stack)
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
