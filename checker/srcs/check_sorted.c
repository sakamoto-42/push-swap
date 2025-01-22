/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:21:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 09:21:41 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
