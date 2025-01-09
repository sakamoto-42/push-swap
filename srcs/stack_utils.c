/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:24:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 21:43:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(t_stack *stack)
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

t_stack	*ft_find_stack_min(t_stack *stack)
{
	t_stack	*stack_min;

	stack_min = stack;
	while (stack->next)
	{
		if (stack->next->index < stack_min->index)
			stack_min = stack->next;
		stack = stack->next;
	}
	return (stack_min);
}

t_stack	*ft_find_stack_max(t_stack *stack)
{
	t_stack	*stack_max;

	stack_max = stack;
	while (stack->next)
	{
		if (stack->next->index < stack_max->index)
			stack_max = stack->next;
		stack = stack->next;
	}
	return (stack_max);
}
