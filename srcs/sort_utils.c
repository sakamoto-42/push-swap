/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:45:04 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/10 10:57:21 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	while ((current_estimate - previous_estimate > 0.0000001) || (previous_estimate - current_estimate > 0.0000001))
	{
		previous_estimate = current_estimate;
		current_estimate = (previous_estimate + x / previous_estimate) / 2.0;
	}
	return (current_estimate);
}