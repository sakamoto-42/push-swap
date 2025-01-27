/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/27 09:40:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_strs_errors(char **strs)
{
	if (!strs)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!*strs)
	{
		if (!*strs)
			free(strs);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**strs;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc - 1 == 0)
		return (1);
	strs = ft_parse_params(argc, argv);
	if (!ft_check_strs_errors(strs))
		return (1);
	if (!ft_set_stack_a(&stack_a, strs))
		return (1);
	if (ft_check_sorted(stack_a, stack_b))
		return (ft_free_stack(stack_a), 0);
	size = ft_get_stack_size(stack_a);
	ft_sort(&stack_a, &stack_b, size);
	return (ft_free_stack(stack_a), ft_free_stack(stack_b), 0);
}
