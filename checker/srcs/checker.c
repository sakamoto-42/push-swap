/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:00:23 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/29 11:58:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static int	execute_instructions(char *str,
	t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	ft_process_instructions(t_stack	**stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!execute_instructions(str, stack_a, stack_b))
		{
			free(str);
			return (0);
		}
		free(str);
		str = get_next_line(0);
	}
	return (1);
}

static void	ft_check_sorted_and_free_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_sorted(*stack_a, *stack_b))
	{
		ft_printf("OK\n");
		ft_free_stack(*stack_a);
		ft_free_stack(*stack_b);
	}
	else
	{
		ft_printf("KO\n");
		ft_free_stack(*stack_a);
		ft_free_stack(*stack_b);
	}
}

int	main(int argc, char **argv)
{
	char	**strs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc - 1 == 0)
		return (1);
	strs = ft_parse_params(argc, argv);
	if (!strs)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!*strs)
		return (free(strs), ft_putstr_fd("Error\n", 2), 1);
	if (!ft_set_stack_a(&stack_a, strs))
		return (1);
	if (!ft_process_instructions(&stack_a, &stack_b))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_free_stack(stack_a), ft_free_stack(stack_b), 1);
	}
	ft_check_sorted_and_free_stack(&stack_a, &stack_b);
	return (0);
}
