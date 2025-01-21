/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:17:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 13:55:14 by juduchar         ###   ########.fr       */
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
