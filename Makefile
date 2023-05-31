# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:06:43 by aelsiddi          #+#    #+#              #
#    Updated: 2023/05/31 17:30:45 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c flow.c parsing_tmp.c player.c
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror

ifeq ($(shell uname -s), Darwin)
	CFLAGS += -Imlx
	MLX = -Lminilibx_macos -lmlx -framework OpenGl -framework APPKit
#MLX_LIB = minilibx_macos
else ifeq ($(shell uname -s), Linux)
	CFLAGS += -Imlx
	MLX =  -Imlx_Linux -lmlx -L/usr/lib -Imlx_linux -lmlx -lXext -lX11  -o
# 	MLX_LIB = minilibx-linux
endif

CC = gcc

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFALGS) $(SRCS) $(MLX) -Imlx_linux -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re