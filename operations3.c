/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:37:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/11 15:38:37 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrr(t_group *a, t_group *b)
{
	if (!b || !a || a->size < 2 || b->size < 2)
		return ;
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
