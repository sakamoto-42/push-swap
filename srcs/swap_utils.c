/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:55:01 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 16:09:21 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sa_silent(t_stack **stack_a)
{
	swap(*stack_a);
	return (1);
}

int	sb_silent(t_stack **stack_b)
{
	swap(*stack_b);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_silent(stack_a);
	sb_silent(stack_b);
	ft_printf("ss\n");
	return (1);
}
