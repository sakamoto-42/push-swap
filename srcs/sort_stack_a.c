/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/10 11:15:51 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	ft_sort_stack_a_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_stack_a_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	ft_sort_stack_a_four(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*stack_a_min;
	int		i;
	int		n;
	int		(*move)(t_stack **);
	int		stack_a_size;

	stack_a_size = size;
	i = 0;
	while (i < stack_a_size - 3)
	{
		stack_a_min = ft_find_stack_min(*stack_a);
		if (stack_a_min->position <= size / 2)
		{
			n = stack_a_min->position;
			move = ra;
		}
		else
		{
			n = size - stack_a_min->position;
			move = rra;
		}
		while (n--)
			move(stack_a);
		pb(stack_a, stack_b);
		i++;
		size--;
	}
	ft_sort_stack_a_three(stack_a);
	while (ft_get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}

#include <stdio.h>

void		ft_sort_stack_a_chunks(t_stack **stack_a, t_stack **stack_b, int size)
{
	float		size_sqrt;
	float		k;
	int		n_chunks;
	//int		chunk_size;



	k = 2.0;
	size = 500;
	size_sqrt = ft_sqrt_float(size);
	//printf("%.7f", size_sqrt);
	if (size_sqrt != (int)size_sqrt)
		n_chunks = (size_sqrt * k) + 1;
	else
		n_chunks = size_sqrt * k;
	ft_printf("%d", n_chunks);
	//int int_part = (int)size_sqrt;
	//n_chunks = (((int)size_sqrt) + 1) * k;
	//ft_printf("%d", int_part);
	(void) stack_a;
	(void) stack_b;
}
