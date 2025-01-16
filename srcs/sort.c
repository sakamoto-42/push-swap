/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:31:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/16 09:20:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	if (!((*stack_a)->value < (*stack_a)->next->value))
		ra(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	ft_sort_mini(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*stack_a_min;
	int		i;
	int		n;
	int		(*move)(t_stack **);
	int		stack_a_size;

	stack_a_size = size - 3;
	i = 0;
	while (i < stack_a_size)
	{
		stack_a_min = ft_find_stack_min(*stack_a);
		if (stack_a_min->position <= size / 2)
			ft_rotate_stack_a_to_top(stack_a_min, &n, &move);
		else
			ft_reverse_rotate_stack_a_to_top(stack_a_min, size, &n, &move);
		while (n--)
			move(stack_a);
		pb(stack_a, stack_b);
		i++;
		size--;
	}
	ft_sort_three(stack_a);
	while (ft_get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}
/*
t_stack	*ft_find_stack_between(t_stack *stack, int min, int max)
{
	t_stack	*stack_min;

	stack_min = NULL;
	while (stack->next)
	{
		if (stack->next->index >= min && stack->next->index <= max)
			stack_min = stack->next;
		stack = stack->next;
	}
	return (stack_min);
}
*/

/*
void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int size)
{
	float		size_sqrt;
	float		k;
	int			n_chunks;
	int			chunk_size;
	int			first_chunks;
	int			remaining_chunks;
	int			chunk_size_first_chunks;

	k = 2;
	size = 238;
	size_sqrt = ft_sqrt_float(size);
	n_chunks = (int)ft_round_up(size_sqrt * k);
	chunk_size = size / n_chunks;
	first_chunks = size % n_chunks;
	remaining_chunks = n_chunks - first_chunks;
	chunk_size_first_chunks = chunk_size + 1;
	//ft_printf("nombre d'elements : %d\nnombre de chunks total : %d\nnombre de premiers chunks : %d\ntaille des premiers chunks : %d\nnombre de chunks restants : %d\ntaille des chunks restants: %d", size, n_chunks, first_chunks,  chunk_size_first_chunks, remaining_chunks, chunk_size);
}
*/

void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*max_stack_b;
	t_stack	*min_stack_b;
	int		count;
	int		n;
	int		(*move)(t_stack **);
	int		i;

	count = 0;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	min_stack_b = ft_find_stack_min(*stack_b);
	max_stack_b = ft_find_stack_max(*stack_b);

	// new max
	if ((*stack_a)->index > max_stack_b->index)
	{
		if ((*stack_b)->index != max_stack_b->index)
		{
			i = 0;
			size = ft_get_stack_size(*stack_b);
			if (max_stack_b->position <= size / 2)
				ft_rotate_stack_b_to_top(max_stack_b, &n, &move);
			else
				ft_reverse_rotate_stack_b_to_top(max_stack_b, size, &n, &move);
			count += n;
			while (n--)
				move(stack_b);
			i++;
			size--;
		}
		pb(stack_a, stack_b);
		count++;
	}
	// new min
	if ((*stack_a)->index < min_stack_b->index)
	{
		if ((*stack_b)->index != max_stack_b->index)
		{
			i = 0;
			size = ft_get_stack_size(*stack_b);
			if (max_stack_b->position <= size / 2)
				ft_rotate_stack_b_to_top(max_stack_b, &n, &move);
			else
				ft_reverse_rotate_stack_b_to_top(max_stack_b, size, &n, &move);
			count += n;
			while (n--)
				move(stack_b);
			i++;
			size--;
		}
		pb(stack_a, stack_b);
		count++;
	}
	// si le premier element de a n'est ni le nouveau min ni le nouveau max de b
	/*
	if ((*stack_a)->index > min_stack_b->index && (*stack_a)->index < max_stack_b->index)
	{
		// on cherche entre quels nombres il doit etre insere :
		// si current->index > number et current->next-index < number
		// on rotate b pour que current->next arrive en haut de b
		// on push a dans b
		// si current->index < number && current->next-index > number
		// on rotate b pour que current->next arrive en haut de b
		// on push a dans b
		//ft_printf("%d", (*stack_a)->index);
		t_stack *current = *stack_b;
		if ((current->index > (*stack_a)->index) && (current->next->index < (*stack_a)->index))
		{
			//ft_printf("%d %d %d", current->index, (*stack_a)->index, current->next->index);
			if (current->next)
				current = current->next;
			// on met current->next en haut
			rb(stack_b);
			pb(stack_a, stack_b);
		}
			// inutile ?
			//((current->index < number) && (current->next->index > number)))
			// on rotate b pour que current->next soit le premier element de b
			// on push a dans b
	//}
	(void)size;*/
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size >= 4 && size <= 6)
		ft_sort_mini(stack_a, stack_b, size);
	else if (size >= 7 && size <= 100)
		ft_sort_medium(stack_a, stack_b, size);
	//else
		//ft_sort_big(&stack_a, &stack_b, size);
}
