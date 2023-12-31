/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:55:42 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/12 04:36:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_init(t_dlist *list)
{
	t_dlist_node *const	head = (t_dlist_node*) malloc(sizeof(t_dlist_node));
	t_dlist_node *const	tail = (t_dlist_node*) malloc(sizeof(t_dlist_node));

	assert(head != NULL && tail != NULL);
	head->prev = tail;
	head->next = tail;
	tail->prev = head;
	tail->next = head;
	list->head = head;
	list->tail = tail;
	list->size = 0;
}

void	dlist_destroy(t_dlist *list, void (*del)(void *))
{
	const t_dlist_node	*cur = list->head->next;

	while (cur != list->tail)
	{
		cur = cur->next;
		del(cur->prev->item);
		free(cur->prev);
	}
	free(list->head);
	free(list->tail);
}

bool	dlist_is_empty(t_dlist *list)
{
	return (list->size == 0);
}

size_t	dlist_size(t_dlist *list)
{
	return (list->size);
}

t_dlist_node	*dlist_get_iterator(t_dlist *list, int pos)
{
	t_dlist_node	*cur;

	if (pos >= 0)
	{
		cur = list->head->next;
		while (pos--)
			cur = cur->next;
	}
	else
	{
		cur = list->tail;
		while (pos++)
			cur = cur->prev;
	}
	return (cur);
}
