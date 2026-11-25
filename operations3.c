/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:37:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/25 13:56:56 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	if (data->a.size < 2 && data->b.size < 2)
		return ;
	rrotate(&data->a);
	rrotate(&data->b);
	data->rrr_c++;
	write(1, "rrr\n", 4);
}

void	free_split(char **split)
{
	int	c;

	if (!split)
		return ;
	c = 0;
	while (split[c] != NULL)
	{
		free(split[c]);
		c++;
	}
	free(split);
}
