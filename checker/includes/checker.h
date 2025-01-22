/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:59:07 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/22 19:57:53 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int					ft_check_stack_a_sorted(t_stack *stack);
int					ft_is_nbr(const char *str);
int					ft_is_int(const char *str);
int					ft_is_unique(t_stack *stack_a, int value);
char				**ft_parse_params(int ac, char **av);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					ft_set_stack_a(t_stack **stack_a, char **strs);
t_stack				*ft_create_stack(int value);
void				ft_add_stack(t_stack **stack, int value);
void				ft_free_stack(t_stack *stack);
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

#endif
