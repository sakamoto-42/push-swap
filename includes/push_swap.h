/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/21 14:46:01 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				index;
	int				value;
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_rotation
{
	int 	count;
	char	direction;
}	t_rotation;

int					ft_check_stack_a_sorted(t_stack *stack);
t_rotation			ft_count_rotations_to_top(t_stack *stack, t_stack *elem);
int					ft_count_total_rotations(t_rotation	rotations_a, t_rotation rotations_b);
void				ft_rotate_to_top_simple(t_stack **stack, t_stack *elem, char stack_name);
void				ft_rotate_to_top_double(t_stack **stack_a, t_rotation *rotations_a, t_stack **stack_b, t_rotation *rotations_b);
int					ft_is_nbr(const char *str);
int					ft_is_int(const char *str);
int					ft_is_unique(t_stack *stack_a, int value);
char				**ft_parse_params(int ac, char **av);
void				push(t_stack **src, t_stack **dst);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rra_silent(t_stack **stack_a);
int					rrb_silent(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate(t_stack **stack);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					ra_silent(t_stack **stack_a);
int					rb_silent(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **stack);
int					ft_set_stack_a(t_stack **stack_a, char **strs);
void				ft_set_stack_index(t_stack *stack_a);
void				ft_set_stack_position(t_stack *stack);
void				ft_sort_two(t_stack **stack_a);
void				ft_sort_three(t_stack **stack_a);
void				ft_sort_big(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_target_in_stack_b(t_stack *stack_b, int index_a);
void				ft_stack_a_to_stack_b(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_target_in_stack_a(t_stack *stack_a, int index_b);
void				ft_stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b);
t_stack				*ft_create_stack(int value);
void				ft_add_stack(t_stack **stack, int value);
void				ft_free_stack(t_stack *stack);
int					ft_get_stack_size(t_stack *stack);
t_stack				*ft_find_stack_min(t_stack *stack);
t_stack				*ft_find_stack_max(t_stack *stack);
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					sa_silent(t_stack **stack_a);
int					sb_silent(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

#endif
