/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 16:49:27 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_a_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_stack_a_three_a_inf_b(t_stack **stack_a, int a, int c)
{
	if (a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		rra(stack_a);
}

void	ft_sort_stack_a_three_b_inf_c(t_stack **stack_a, int a, int c)
{
	if (a < c)
		sa(stack_a);
	else
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
	if (a < b)
		ft_sort_stack_a_three_a_inf_b(stack_a, a, c);
	else if (b < c)
		ft_sort_stack_a_three_b_inf_c(stack_a, a, c);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	ft_sort_stack_a_four(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*stack_a_min;
	int		n;

	(void) stack_b;
	stack_a_min = ft_find_stack_min(*stack_a);
	ft_printf("index min : %d", stack_a_min->index);
	ft_printf("position min : %d", stack_a_min->position);
	if (stack_a_min->position < size / 2)
	{
		ft_printf("up");
		n = stack_a_min->position;
		ft_printf("%d", n);
		while (n--)
		{
			ft_printf("RA");
			ra(&stack_a_min);
		}
	}
	else
	{
		ft_printf("down");
		n = size - stack_a_min->position;
		while (n--)
		{
			ft_printf("RRA");
			rra(&stack_a_min);
		}
	}	 
	//ft_printf("MIN %d", stack_a_min->value);
}

/*
void	ft_sort_stack_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_b;
	int	count;
	
	(void) size;
	count = 0;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	max_b = ft_find_max(*stack_b);
	if ((*stack_a)->value > max_b)
	{
		if ((*stack_b)->value != max_b)
		{
			count++;
			//count += rb(stack_b);
		}
		count++;
		//count += pb(stack_a, stack_b);
	}
	ft_printf("%d", count);
}
*/
