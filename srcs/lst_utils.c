/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:31 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/08 10:38:13 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*ft_create_node(int value, int index)
{
	Node *new_node = ft_calloc(1, sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node(Node **head, int value, int index)
{
	Node	*new_node;
	Node	*current;

	new_node = ft_create_node(value, index);
	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	ft_set_index(Node *head, int n)
{
	if (!head)
		return ;
	head->index = n;
}

void	ft_free_lst(Node *head)
{
	Node	*current;
	Node	*temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}