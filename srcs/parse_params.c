/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:38:33 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/07 10:58:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_check_params_errors(char **strs_to_check, char **strs_to_free)
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
char	**concat_strs(char **strs1, char **strs2)
{
	size_t		strs1_len;
	size_t		strs2_len;
	char		**strs;
	size_t		i;
	size_t		j;

	strs1_len = 0;
	strs2_len = 0;
	while (strs1[strs1_len])
		strs1_len++;
	while (strs2[strs2_len])
		strs2_len++;
	strs = malloc((strs1_len + strs2_len + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < strs1_len)
	{
		strs[i] = ft_strdup(strs1[i]);
		if (!strs[i])
		{
			ft_free_strs_until(strs, i);
			return (NULL);
		}
		i++;
	}
	j = 0;
	while (j < strs2_len)
	{
		strs[i + j] = ft_strdup(strs2[j]);
		if (!strs[i + j])
		{
			ft_free_strs_until(strs, i + j);
			return (NULL);
		}
		j++;
	}
	strs[i + j] = NULL;
	return (strs);
}

char	**ft_concat_and_free_strs(char **strs, char **current_strs)
{
	char	**temp_strs;
	
	temp_strs = strs;
	strs = concat_strs(strs, current_strs);
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
			write(2, "Error\n", 6);
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