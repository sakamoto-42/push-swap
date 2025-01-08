/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/08 12:06:50 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_set_lst(Node **head, char **strs)
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
void	ft_printf_list(Node *stack_a, Node *stack_b)
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

void	swap(Node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp;
}

void	sa(Node **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}
void	sb(Node **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(Node **stack_a, Node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	push(Node **src, Node **dst)
{
	Node	*temp;

	if (!src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	pa(Node **stack_a, Node **stack_b)
{
	if (!stack_b)
		return ;
	else
		push(stack_b, stack_a);
}

void	pb(Node **stack_a, Node **stack_b)
{
	if (!stack_a)
		return ;
	else
		push(stack_a, stack_b);
}


int	main(int argc, char **argv)
{
	char	**strs;
	Node	*stack_a;
	Node	*stack_b;

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
	ft_printf_list(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	ft_printf_list(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	ft_printf_list(stack_a, stack_b);
	ft_printf("\n");
	//
	return (0);
}
