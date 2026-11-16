/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:37:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/16 18:11:34 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	if (data->a.size < 2 || data->b.size < 2)
		return ;
	rrotate(&data->a);
	rrotate(&data->b);
	data->rrr_c++;
	write(1, "rrr\n", 4);
}
