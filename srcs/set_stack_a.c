/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:34:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 14:41:58 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_stack_a(t_stack **stack_a, char **strs)
{
	int		i;
	int		value;

	i = 0;
	while (strs[i])
	{
		value = ft_atoi(strs[i]);
		if (!ft_is_unique(*stack_a, value))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_lst(*stack_a);
			return (0);
		}
		ft_add_node(stack_a, value);
		i++;
	}
	ft_free_strs(strs);
	ft_set_index(*stack_a);
	return (1);
}
