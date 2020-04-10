# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-hou <rvan-hou@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/16 14:45:59 by rvan-hou       #+#    #+#                 #
#    Updated: 2020/04/09 10:56:13 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# mlx na name weggehaald en na clean name

CFILES =	cub3d.c map.c store_utils.c store_arguments.c \
			utils/get_next_line/get_next_line.c \
			utils/get_next_line/get_next_line_utils.c utils/ft_atoi.c \
			utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c \
			utils/ft_strlen.c utils/ft_putnbr.c utils/ft_putchar.c \
			utils/ft_putstr.c utils/ft_strncmp.c map_valid.c window.c \
			scan_map.c create_bmp.c initialize.c init_textures.c store_utils2.c \
			textures.c textures2.c tex_utils.c sprite_hit.c sprite_utils.c \
			raycasting.c move.c check_map.c \
		
SRCS = $(addprefix mandatory/,$(CFILES))

OBJS = $(SRCS:.c=.o)

CC = gcc -O3 -Wall -Wextra -Werror -I.

LIBS = -L mlx -lmlx -framework OpenGL -framework AppKit -lm

MLX = libmlx.dylib

NAME = cub3D

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) -g -o $(NAME) $(OBJS) $(LIBS)
	./$(NAME)

$(MLX):
	@$(MAKE) -C mlx
	@cp mlx/$(MLX) .

clean:
	@$(MAKE) -C mlx clean
	rm -f $(OBJS)
	rm -rf screenshot.bmp

fclean: clean
	rm -f $(NAME) $(MLX)

re: fclean all
