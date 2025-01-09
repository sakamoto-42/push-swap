/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:17:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 15:45:30 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp;
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
