/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:00:23 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 11:47:03 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	ft_process_instructions(t_stack	**stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	if (str[0] == 'a')
		ra(stack_a);
	(void)stack_b;
	return (1);
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
		return (1);
	if (!ft_set_stack_a(&stack_a, strs))
		return (1);
	if (ft_check_stack_a_sorted(stack_a))
		return (0);
	if (!ft_process_instructions(&stack_a, &stack_b))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	//ft_printf("OK\n");
	//pa(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//rra(&stack_a);
	//rrb(&stack_a);
	//rrr(&stack_a, &stack_b);
	//ra(&stack_a);
	//rb(&stack_b);
	//rr(&stack_a, &stack_b);
	//sa(&stack_a);
	//sb(&stack_b);
	//ss(&stack_a, &stack_b);
	if (ft_check_stack_a_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	//size = ft_get_stack_size(stack_a);
	//ft_sort(&stack_a, &stack_b, size);
	return (0);
}