/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:34:36 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 10:05:59 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_stack_a(t_stack **head, char **strs)
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
