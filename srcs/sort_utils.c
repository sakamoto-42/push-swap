/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:45:04 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/16 08:55:59 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_sqrt_float(int nb)
{
	float	x;
	float	previous_estimate;
	float	current_estimate;

	if (nb <= 0)
		return (0);
	x = (float)nb;
	previous_estimate = 0;
	current_estimate = x / 2.0;
	while ((current_estimate - previous_estimate > 0.0000001)
		|| (previous_estimate - current_estimate > 0.0000001))
	{
		previous_estimate = current_estimate;
		current_estimate = (previous_estimate + x / previous_estimate) / 2.0;
	}
	return (current_estimate);
}

int	ft_round_up(float value)
{
	if (value > (int)value)
		return ((int)value + 1);
	return ((int)value);
}
