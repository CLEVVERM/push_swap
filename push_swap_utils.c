/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 17:54:29 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/06 18:06:52 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node new_one(int data)
{
	t_node *new;
	new = malloc(t_node);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prew = NULL;
	new->index = -1;
}

void free_group(t_group *group)
{
	t_node *curr;
	t_node *temp;

	if (!group || group == NULL)
		return ;
	curr = group -> top; 
	while (curr != NULL)
	{
		curr -> next = temp;
		free(curr);
		curr = temp -> next;
	}
	group -> size = 0;
	group -> top = NULL;
	group -> bottom = NULL;
}

void add_bottom(t_group *group, t_node *node)
{
	if (!group -> top)
	{
		group -> top = node;
		 group -> bottom = node;
		 node -> next = NULL;
	}
	else
	{
		group -> next = node;
		node -> prew = group;
		group -> bottom = node;
	}
	group -> size++;	
}

void free_both(t_group *a, t_group *b)
{
	free_group (&a);
	free_group (&b);
	write(2, "Error", 5);
	exit(1);
}