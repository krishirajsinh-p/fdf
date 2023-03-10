# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 05:07:15 by kpuwar            #+#    #+#              #
#    Updated: 2023/03/09 22:34:50 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDES = $(wildcard src/include/*.h)

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = 
#-Wall -Werror -Wextra
RM = rm -f

LIBMLX	:= ./lib/mlx42
LIBFT	:= ./lib/libft

all: libmlx libft $(NAME)

libmlx:
	@make -C $(LIBMLX)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -I $(INCLUDES) -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/" -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBMLX) clean
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBMLX) fclean
	@make -C $(LIBFT) fclean

re: fclean all

norm:
	@norminette src
	@norminette lib/libft

install:
	brew update
	brew install glfw

.PHONY: all clean fclean re libmlx libft norm install