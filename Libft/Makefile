# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: msotnych <msotnych@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/09/28 14:18:10 by msotnych      #+#    #+#                  #
#    Updated: 2026/10/20 14:54:18 by msotnych      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror



SRC =	ft_atoi.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_isalpha.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_isalnum.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_isascii.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c \
		ft_isdigit.c ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c \
		ft_isprint.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_strlcat.c ft_lstmap.c\
		ft_strlen.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_toupper.c \
		ft_tolower.c


OBJ = $(SRC:.c=.o)

all: $(NAME)
AR = ar rcs
RM: rm -f
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@  
	
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) 
fclean: 
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re