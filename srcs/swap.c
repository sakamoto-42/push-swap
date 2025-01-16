/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:17:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/16 14:12:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp_value;
	int	temp_index;

	if (!stack || !stack->next)
		return ;
	temp_value = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp_value;
	temp_index = stack->next->index;
	stack->next->index = stack->index;
	stack->index = temp_index;
	ft_set_stack_position(stack);
}

int	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (1);
}
