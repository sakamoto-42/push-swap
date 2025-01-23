/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:38:33 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/23 12:26:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_params_errors(char **strs_to_check, char **strs_to_free)
{
	int	i;

	i = 0;
	while (strs_to_check[i])
	{
		if (!ft_is_nbr(strs_to_check[i]) || !ft_is_int(strs_to_check[i]))
		{
			ft_free_strs(strs_to_check);
			if (strs_to_free)
				ft_free_strs(strs_to_free);
			return (1);
		}
		i++;
	}
	return (0);
}

static char	**ft_copy_strs_until(char **dst, char **src,
				size_t start, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		dst[start + i] = ft_strdup(src[i]);
		if (!dst[start + i])
		{
			ft_free_strs_until(dst, start + i);
			return (NULL);
		}
		i++;
	}
	return (dst);
}

static char	**concat_strs(char **strs1, char **strs2)
{
	size_t		strs1_len;
	size_t		strs2_len;
	char		**strs;

	strs1_len = 0;
	strs2_len = 0;
	while (strs1[strs1_len])
		strs1_len++;
	while (strs2[strs2_len])
		strs2_len++;
	strs = ft_calloc((strs1_len + strs2_len + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	if (!ft_copy_strs_until(strs, strs1, 0, strs1_len))
		return (NULL);
	if (!ft_copy_strs_until(strs, strs2, strs1_len, strs2_len))
		return (NULL);
	strs[strs1_len + strs2_len] = NULL;
	return (strs);
}

static char	**ft_concat_and_free_strs(char **strs, char **current_strs)
{
	char	**temp_strs;

	temp_strs = strs;
	strs = concat_strs(strs, current_strs);
	if (!strs)
		return (NULL);
	ft_free_strs(temp_strs);
	ft_free_strs(current_strs);
	return (strs);
}

char	**ft_parse_params(int ac, char **av)
{
	int		i;
	char	**strs;
	char	**current_strs;

	i = 1;
	strs = NULL;
	while (i < ac)
	{
		current_strs = ft_split(av[i], ' ');
		if (ft_check_params_errors(current_strs, strs))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		if (!strs)
			strs = current_strs;
		else
			strs = ft_concat_and_free_strs(strs, current_strs);
		i++;
	}
	return (strs);
}
