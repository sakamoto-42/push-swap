/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:08 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 10:06:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_a_sorted(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			return (0);
		min = stack->value;
		stack = stack->next;
	}
	return (1);
}
