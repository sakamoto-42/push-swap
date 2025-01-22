/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:33:14 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 09:46:59 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	return (1);
}
