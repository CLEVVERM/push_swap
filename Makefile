# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: msotnych <msotnych@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/10/23 17:33:59 by msotnych      #+#    #+#                  #
#    Updated: 2026/11/10 17:21:09 by msotnych      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = Libft/libft.a
SRC = push_swap.c push_swap_utils_1.c push_swap_utils_2.c main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@  
$(LIBFT):
	make -C Libft
$(FT_PRINTF):
	make -C ft_printf
$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAG) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

clean: 
	$(RM) $(OBJ) 
	make -C ft_printf clean
	make -C Libft clean
fclean: 
	$(RM) $(OBJ) $(NAME) $(FT_PRINTF) $(LIBFT)
	make -C ft_printf fclean
	make -C Libft fclean
re: fclean all

.PHONY: clean fclean all re