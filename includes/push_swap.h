/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/07 10:56:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct Node {
	int		value;
	struct	Node *next;
} Node;

Node		*create_node(int value);
void		add_node(Node **head, int value);
void		ft_free_lst(Node *head);

char		**ft_parse_params(int ac, char **av);
int			ft_check_params_errors(char **strs_to_check, char **strs_to_free);
char		**ft_concat_and_free_strs(char **strs, char **current_strs);
char		**concat_strs(char **strs1, char **strs2);

int			ft_is_nbr(const char *str);
long long	ft_strtoll(const char *str);
int			ft_is_int(const char *str);
int			ft_is_unique(Node *head, int value);

#endif