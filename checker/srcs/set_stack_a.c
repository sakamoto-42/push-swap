/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:19:40 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/23 12:45:31 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			ft_free_strs(strs);
			ft_free_stack(*stack_a);
			return (0);
		}
		ft_add_stack(stack_a, value);
		i++;
	}
	ft_free_strs(strs);
	return (1);
}
