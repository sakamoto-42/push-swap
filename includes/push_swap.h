/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/08 10:38:24 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <libft.h>

typedef struct Node {
	int		index;
	int		value;
	struct	Node *next;
} Node;

Node		*ft_create_node(int value, int index);
void		ft_add_node(Node **head, int value, int index);
void		ft_set_index(Node *head, int n);
void		ft_free_lst(Node *head);

char		**ft_parse_params(int ac, char **av);

int			ft_is_nbr(const char *str);
int			ft_is_int(const char *str);
int			ft_is_unique(Node *head, int value);

#endif