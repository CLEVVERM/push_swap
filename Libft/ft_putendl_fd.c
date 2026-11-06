/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 12:02:59 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/12 13:22:10 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	write(fd, "\n", 1);
}

// #include <fcntl.h>

// int main(void)
// {	
// 	char c[] = "getrgbr w";
// 	int fd;
// 	fd = open("test.txt", O_WRONLY);
// 	ft_putendl_fd(c, fd);
// 	close(fd);
// }