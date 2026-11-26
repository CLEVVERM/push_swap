/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 14:36:15 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/26 17:51:00 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_to_num(int *num, char *str)
{
	int		s;
	long	res;
	int		c;

	s = 1;
	res = 0;
	c = 0;
	if (str[c] == '-')
		s = -s;
	if (str[c] == '-' || str[c] == '+')
		c++;
	if (str[c] == '\0')
		return (0);
	while (str[c] != '\0')
	{
		if (str[c] > '9' || str[c] < '0')
			return (0);
		res = res * 10 + str[c] - '0';
		c++;
		if (res * s > INT_MAX || res * s < INT_MIN)
			return (0);
	}
	*num = res * s;
	return (1);
}

int	check_duplicates(t_group *group)
{
	t_node	*curr;
	t_node	*lower;

	curr = group->top;
	while (curr != NULL)
	{
		lower = curr->next;
		while (lower != NULL)
		{
			if (lower->data == curr->data)
				return (1);
			lower = lower->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	compere_flags(char *flag, t_data *data)
{
	if (ft_strncmp(flag, "--bench", 8) == 0)
		data->bench = 1;
	else if (ft_strncmp(flag, "--adaptive", 11) == 0)
		data->strategy = 0;
	else if (ft_strncmp(flag, "--simple", 9) == 0)
		data->strategy = 1;
	else if (ft_strncmp(flag, "--medium", 9) == 0)
		data->strategy = 2;
	else if (ft_strncmp(flag, "--complex", 10) == 0)
		data->strategy = 3;
	else
		return (0);
	return (1);
}

int	add_num(char *str, t_data *data)
{
	char	**split;
	t_node	*node;
	int		num;
	int		c;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	c = 0;
	while (split[c] != NULL && str_to_num(&num, split[c]))
	{
		node = new_one(num);
		if (!node)
			break ;
		add_bottom(&data->a, node);
		c++;
	}
	c = (c > 0 && split[c] == NULL);
	free_split(split);
	return (c);
}

int	pars(int argc, char *argv[], t_data *data)
{
	int		c;

	c = 1;
	while (c < argc)
	{
		if (argv[c][0] == '-' && argv[c][1] == '-')
		{
			if (compere_flags(argv[c], data) == 0)
				return (0);
		}
		else if (add_num(argv[c], data) == 0)
			return (0);
		c++;
	}
	if (check_duplicates(&data->a) == 1)
		return (0);
	return (1);
}
