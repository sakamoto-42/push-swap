/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:43 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/09 14:59:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <libft.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

int			ft_set_stack_a(t_stack **stack_a, char **strs);		

int			ft_check_stack_a_sorted(t_stack *stack);

t_stack		*ft_create_node(int value);
void		ft_add_node(t_stack **stack_a, int value);
void		ft_set_index(t_stack *stack);
void		ft_free_lst(t_stack *stack);
int			ft_stack_size(t_stack *stack);

char		**ft_parse_params(int ac, char **av);

int			ft_is_nbr(const char *str);
int			ft_is_int(const char *str);
int			ft_is_unique(t_stack *stack_a, int value);

void		rotate(t_stack **stack);
int			ra(t_stack **stack_a);
int			rb(t_stack **stack_b);
int			rr(t_stack **stack_a, t_stack **stack_b);

void		reverse_rotate(t_stack **stack);
int			rra(t_stack **stack_a);
int			rrb(t_stack **stack_b);
int			rrr(t_stack **stack_a, t_stack **stack_b);

void		push(t_stack **src, t_stack **dst);
int			pa(t_stack **stack_a, t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);

void		swap(t_stack *stack);
int			sa(t_stack **stack_a);
int			sb(t_stack **stack_b);
int			ss(t_stack **stack_a, t_stack **stack_b);

void		ft_sort_stack_a_two(t_stack **stack_a);
void		ft_sort_stack_a_three(t_stack **stack_a);
void		ft_sort_stack_a_three_a_inf_b(t_stack **stack_a, int a, int c);
void		ft_sort_stack_a_three_b_inf_c(t_stack **stack_a, int a, int c);


void		ft_sort_stack_a(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_sort_stack_a_four(t_stack **stack_a, t_stack **stack_b);

#endif