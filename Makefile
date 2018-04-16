# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvermand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/28 11:09:36 by cvermand          #+#    #+#              #
#    Updated: 2018/04/16 15:17:50 by cvermand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FDF			=	fdf

CC			=	gcc
CFLAGS		=   -Wall -Werror -Wextra -g3

_SRCS		=	fdf.c file_parsing.c line_parsing.c show_functions.c check_validity_of_input.c set_env.c transform_points.c init_mlx.c fdf_handler.c rotation_matrix.c events_listener.c apply_change.c free_all.c line_drawing.c
_LIBFT		=	libft.a
_MLX		= 	libmlx.a

SRCS_DIR	=	src
LIB_DIR		=	libft
MLX_DIR		=	minilibx_macos
SRCS		=	$(addprefix	$(SRCS_DIR)/, $(_SRCS))
LIBFT		=	$(addprefix $(LIB_DIR)/, $(_LIBFT))
MLX			=	$(addprefix $(MLX_DIR)/, $(_MLX))

OBJS		=	$(SRCS:.c=.o)

all:	$(FDF)

$(FDF) : $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(FDF) $(OBJS) -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lm
	@echo "$(FDF) : $(_GREEN)Done$(_END)"

$(LIBFT):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(MLX_DIR)
	@/bin/rm -f $(OBJS)
	@echo "FDF clean : $(_GREEN)Done$(_END)"

fclean: clean
	@/bin/rm -f $(FDF)
	@echo "FDF fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re

