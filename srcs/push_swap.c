/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 10:15:44 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// DEBUG ONLY
void	ft_printf_stacks(t_stack *stack_a, t_stack *stack_b)
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
	if (!strs)
		return (1);
	if (!ft_set_stack_a(&stack_a, strs))
		return (1);
	//ft_printf_stacks(stack_a, stack_b);
	if (ft_check_stack_a_sorted(stack_a))
		return (0);
	size = ft_stack_size(stack_a);
	if (size == 2)
		ft_sort_stack_a_two(&stack_a);
	else if (size == 3)
		ft_sort_stack_a_three(&stack_a);
	else
		ft_sort_stack_a(&stack_a, &stack_b, size);
	//ft_printf_stacks(stack_a, stack_b);
	return (0);
}
