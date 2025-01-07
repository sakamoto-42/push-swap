/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:32:52 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/07 11:16:42 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_set_lst(Node **head, char **strs)
{
	int		i;
	int		value;
	
	i = 0;
	while (strs[i])
	{
		value = ft_atoi(strs[i]);
		if (!ft_is_unique(*head, value))
		{
			write(2, "Error\n", 6);
			ft_free_lst(*head);
			return (0);
		}
		add_node(head, value);
		i++;
	}
	ft_free_strs(strs);
	return (1);
}
// DEBUG ONLY
void	ft_printf_list(Node *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
}
//

int	main(int argc, char **argv)
{
	char	**strs;
	Node	*head = NULL;

	if (argc - 1 == 0)
		return (1);
	strs = ft_parse_params(argc, argv);
	if (!strs)
	{
		// DEBUG ONLY
		printf("error 1\n");
		//
		return (1);
	}
	if (!ft_set_lst(&head, strs))
	{
		// DEBUG ONLY
		printf("error 2\n");
		//
		return (1);
	}
	// DEBUG ONLY
	printf("ok\n");
	ft_printf_list(head);
	//
	return (0);
}
