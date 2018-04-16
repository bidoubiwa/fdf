#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvermand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 08:28:21 by cvermand          #+#    #+#              #
#    Updated: 2018/02/08 17:42:02 by pfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC			=	gcc
FLAGS		= 	-Wall -Werror -Wextra -g

_SRC 		= 	ft_handler.c ft_parser.c ft_int_handler.c ft_printf.c \
	  			ft_chainfct.c ft_error_handler.c ft_flags.c ft_recognize.c \
	  			ft_precision.c ft_width.c ft_str_handler.c ft_str_w_handler.c \
				ft_parser_flags.c ft_conversion_symbols.c ft_extend_w_char.c \
				ft_w_char_bytes.c

_LSRC 		=	ft_putchar.c ft_putstr.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memccpy.c ft_strlen.c ft_strdup.c ft_tolower.c ft_toupper.c \
				ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
				ft_isalpha.c ft_atoi.c ft_strncmp.c	ft_strcmp.c ft_strstr.c \
				ft_strnstr.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
				ft_strclr.c ft_striter.c ft_striteri.c \
				ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
				ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c \
				ft_putnbr.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
				ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strdel.c ft_strdel_n.c \
				ft_lstaddafter.c ft_lstswap.c ft_listmerge.c ft_lstlast.c \
				ft_lstsize.c ft_itoa_ll.c ft_match.c ft_itoa_base.c \
				ft_itoa_base_ll.c ft_strjoin_clr.c ft_atoi_base.c \
				ft_atoi_base_ll.c ft_strdupifexist.c ft_strtrim_c.c \
				get_next_line.c ft_swap.c ft_strisvalidint.c\
				ft_get_fd.c ft_strtabdup.c ft_strtablen.c ft_min_int.c\
				ft_check_arguments.c ft_to_degrees.c ft_to_radians.c

PRINTF_DIR	= printf
LIBFT_DIR	= basics
SRC			= $(addprefix $(PRINTF_DIR)/, $(_SRC))
LSRC		= $(addprefix $(LIBFT_DIR)/, $(_LSRC))
BIN 		= $(SRC:.c=.o)
LBIN		= $(LSRC:.c=.o)
BIN			+= $(LBIN)
RM			= /bin/rm

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I includes/

clean :
	rm -f $(BIN)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make
