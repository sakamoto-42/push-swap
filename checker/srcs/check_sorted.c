/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:21:39 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/26 15:52:20 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (!stack_a || stack_b)
		return (0);
	if (!stack_a->next)
		return (1);
	min = stack_a->value;
	while (stack_a)
	{
		if (min > stack_a->value)
			return (0);
		min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
