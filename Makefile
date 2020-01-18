# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdube <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 15:47:16 by rdube             #+#    #+#              #
#    Updated: 2019/10/29 14:17:33 by rdube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = srcs
SRC_NAME = main.c analyser.c ray_casting.c hook.c draw.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft
clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:
	@make -C libft fclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
