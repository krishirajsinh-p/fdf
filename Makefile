# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 05:07:15 by kpuwar            #+#    #+#              #
#    Updated: 2023/04/15 01:23:58 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDES = $(wildcard src/include/*.h)
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

LIBMLX	:= ./lib/mlx42
LIBFT	:= ./lib/libft

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: libmlx libft $(NAME)

libmlx:
	@make -C $(LIBMLX)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -I $(INCLUDES) -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/" -o $(NAME)

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

brew:
	if [ -d $(HOME)/goinfre/.brew ]; then \
		brew update && brew install glfw; \
	else \
		git clone --depth=1 https://github.com/Homebrew/brew $(HOME)/goinfre/.brew; \
		$(shell echo 'export PATH=$$HOME/goinfre/.brew/bin:$$PATH' >> $(HOME)/.zshrc) \
		brew update && brew install glfw; \
	fi

.PHONY: all clean fclean re libmlx libft norm brew