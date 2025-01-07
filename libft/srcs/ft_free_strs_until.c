/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:56:16 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/07 10:00:46 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// free an array of strings until n (not included)
char	**ft_free_strs_until(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}