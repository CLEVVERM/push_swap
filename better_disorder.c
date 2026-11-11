/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   better_disorder.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmolotko <mmolotko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 13:38:39 by mmolotko      #+#    #+#                 */
/*   Updated: 2026/11/11 13:42:58 by mmolotko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//This one should combine all the func from before, however, I havent 
//tested it so did not remove the other func yet
double better_dissorder(t_group *a)
{
	double mistakes;
	double pairs;

	if (a->size <= 1)
		return (0);
	mistakes = 0;
	pairs = 0;
	t_node *i;
	i = a->top;
	while (i)
	{
		t_node *j = i->next;
		while (j)
		{
			pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / pairs);
}
