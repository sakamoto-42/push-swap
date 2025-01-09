/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:24:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 15:34:49 by juduchar         ###   ########.fr       */
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

int	ft_find_stack_min(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack->next)
	{
		if (stack->next->index < min)
			min = stack->next->index;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_stack_max(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack->next)
	{
		if (stack->next->index > max)
			max = stack->next->index;
		stack = stack->next;
	}
	return (max);
}
