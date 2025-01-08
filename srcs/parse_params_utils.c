/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:54:02 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/08 10:23:34 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_nbr(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	set_sign_strtoll(const char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

static long long	ft_strtoll(const char *str)
{
	long long	result;
	int			sign;
	int			digit;

	result = 0;
	sign = 1;

	while (ft_isspace(*str))
		str++;
	set_sign_strtoll(&str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > (LLONG_MAX - digit) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

int	ft_is_int(const char *str)
{
	long long	n;

	n = ft_strtoll(str);
	return (n >= INT_MIN && n <= INT_MAX);
}

int	ft_is_unique(Node *head, int value)
{
	Node	*current;

	current = head;
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	return (1);
}