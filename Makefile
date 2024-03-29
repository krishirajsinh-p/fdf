# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 05:07:15 by kpuwar            #+#    #+#              #
#    Updated: 2023/04/17 16:06:36 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDES = $(wildcard src/include/*.h)
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

LIBMLX	:= ./lib/mlx42
LIBFT	:= ./lib/libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ofast
RM = rm -f

all: libmlx libft $(NAME)

libmlx:
	@make -C $(LIBMLX) -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lm -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/" -I $(INCLUDES) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) clean

re: fclean all

norm:
	@norminette src
	@norminette lib/libft

brew:
	if [ -d $(HOME)/goinfre/.brew ]; then \
		brew update; \
		brew install glfw; \
		brew install cmake; \
	else \
		git clone --depth=1 https://github.com/Homebrew/brew $(HOME)/goinfre/.brew; \
		$(shell echo 'export PATH=$$HOME/goinfre/.brew/bin:$$PATH' >> $(HOME)/.zshrc) \
		brew update; \
		brew install glfw; \
		brew install cmake; \
	fi

deps:
	cmake $(LIBMLX) -B $(LIBMLX)

.PHONY: all clean fclean re libmlx libft norm brew deps