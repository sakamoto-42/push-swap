/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:31 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/07 10:59:43 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*create_node(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(Node **head, int value)
{
	Node	*new_node;
	Node	*current;

	new_node = create_node(value);
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