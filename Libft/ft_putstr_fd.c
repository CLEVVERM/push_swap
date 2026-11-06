/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/09 19:01:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/19 13:19:34 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

// #include <fcntl.h>

// int main(void)
// {	
// 	char c[] = "wve w";
// 	int fd;
// 	fd = open("test.txt", O_WRONLY);
// 	ft_putstr_fd(c, fd);
// 	close(fd);
// }