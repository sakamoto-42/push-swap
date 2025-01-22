/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:53:18 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 13:53:27 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	ra_silent(t_stack **stack_a)
{
	rotate(stack_a);
	return (1);
}

int	rb_silent(t_stack **stack_b)
{
	rotate(stack_b);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	ft_printf("rr\n");
	return (1);
}
