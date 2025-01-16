/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/16 15:17:53 by julien           ###   ########.fr       */
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
			ft_printf("%d : ", stack_a->position);
			ft_printf("(%d) ", stack_a->index);
			ft_printf("%d\t", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			ft_printf("\t");
		if (stack_b)
		{
			ft_printf("%d : ", stack_b->position);
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
	size = ft_get_stack_size(stack_a);
	ft_sort(&stack_a, &stack_b, size);
	//ft_set_stack_index(stack_a);
	//ft_printf_stacks(stack_a, stack_b);
	return (0);
}
