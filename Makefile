# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: msotnych <msotnych@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/10/23 17:33:59 by msotnych      #+#    #+#                  #
#    Updated: 2026/11/05 14:23:00 by msotnych      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAG = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = Libft/libft.a
SRC = ft_printf.c ft_printf_char.c ft_printf_numb.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@  
	
$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	$(AR) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) 
fclean: 
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re