/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/08 18:26:46 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_set_lst(t_stack **head, char **strs)
{
	int		i;
	int		value;

	i = 0;
	while (strs[i])
	{
		value = ft_atoi(strs[i]);
		if (!ft_is_unique(*head, value))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_lst(*head);
			return (0);
		}
		ft_add_node(head, value, i);
		i++;
	}
	ft_free_strs(strs);
	return (1);
}

// DEBUG ONLY
void	ft_printf_list(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("   A\t   B\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("(%d) ", stack_a->index);
			ft_printf("%d\t", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			ft_printf("\t");
		if (stack_b)
		{
			ft_printf("(%d) ", stack_b->index);
			ft_printf("%d", stack_b->value);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;

	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!stack_b)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (!stack_b)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}

int	ft_lst_is_sorted(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			return (0);
		min = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**strs;
	t_stack	*stack_a;
	t_stack	*stack_b;
	// DEBUG ONLY
	int		sorted;

	stack_a = NULL;
	stack_b = NULL;
	if (argc - 1 == 0)
		return (1);
	strs = ft_parse_params(argc, argv);
	if (!strs)
	{
		// DEBUG ONLY
		ft_printf("error 1\n");
		//
		return (1);
	}
	if (!ft_set_lst(&stack_a, strs))
	{
		// DEBUG ONLY
		ft_printf("error 2\n");
		//
		return (1);
	}
	// DEBUG ONLY
	sorted = ft_lst_is_sorted(stack_a);
	if (sorted)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");
	// TODO COUNT n ELEM
	// IF 2
	if (!sorted && !stack_a->next->next)
	{
		if (!(stack_a->value < stack_a->next->value))
			ra(&stack_a);
	}
	sorted = ft_lst_is_sorted(stack_a);
	if (sorted)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");
	// IF 3
	int	ela = 0;
	int	elb = 0;
	int	elc = 0;
	if (!sorted && !stack_a->next->next->next)
	{
		ela = stack_a->value;
		elb = stack_a->next->value;
		elc = stack_a->next->next->value;
		if (ela < elb)
		{
			if (ela < elc)
			{
				sa(&stack_a);
				ra(&stack_a);
			}
			else
				rra(&stack_a);
		}
		else if (elb < elc)
		{
			if (ela < elc)
				sa(&stack_a);
			else
				ra(&stack_a);
		}
		else
		{
			sa(&stack_a);
			rra(&stack_a);
		}
	}
	ft_printf_list(stack_a, stack_b);
	/*
	sa(&stack_a);
	//ft_printf_list(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	rr(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	rrr(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	sa(&stack_a);
	//ft_printf_list(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	//ft_printf_list(stack_a, stack_b);
	pa(&stack_a, &stack_b);*/
	sorted = ft_lst_is_sorted(stack_a);
	if (sorted)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");
	ft_printf("\n");
	//
	return (0);
}
