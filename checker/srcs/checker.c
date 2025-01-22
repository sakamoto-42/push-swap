/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:00:23 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 09:54:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	**strs;
	t_stack	*stack_a;
	//t_stack	*stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	if (argc - 1 == 0)
		return (1);
	strs = ft_parse_params(argc, argv);
	if (!strs)
		return (1);
	if (!ft_set_stack_a(&stack_a, strs))
		return (1);
	if (ft_check_stack_a_sorted(stack_a))
		return (0);
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