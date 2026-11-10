/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 14:36:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/10 17:34:22 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct s_node
{
	int data;
	int index;
	struct s_node *next;
	struct s_node *prew;
}	t_node;

typedef struct s_group
{
	t_node *top;
	int size;
	t_node *bottom;
}	t_group;

typedef struct s_for_pars
{
	t_group a;
	t_group b;
	double disorder;
	int sa;
	int sb;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	
}	t_for_pars;




int str_to_nmb(int *numb, char str);
t_node *new_one(int data);
void free_group(t_group *group);
void add_bottom(t_group *group, t_node *node);
void free_both(t_group *a, t_group *b);
void sa(t_group *a);
void sb(t_group *b);
void pa(t_group *a,t_group *b);
void pb(t_group *a,t_group *b);
void ra(t_group *a);
void rb(t_group *b);
void rr(t_group *a,t_group *b);
void rra(t_group *a);
void rrb(t_group *b);
void rrr(t_group *a,t_group *b);
#endif