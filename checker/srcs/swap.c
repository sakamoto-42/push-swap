/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:36:24 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 19:58:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack *stack)
{
	int	temp_value;

	if (!stack || !stack->next)
		return ;
	temp_value = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp_value;
}

int	sa(t_stack **stack_a)
{
	swap(*stack_a);
	return (1);
}

int	sb(t_stack **stack_b)
{
	swap(*stack_b);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return (1);
}
