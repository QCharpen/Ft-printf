# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/26 01:24:46 by qcharpen     #+#   ##    ##    #+#        #
#    Updated: 2018/12/02 16:03:36 by qcharpen    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Werror -Wextra -Wall

LIBFT_PATH = ./sources/libft

LIBFT = sources/libft/ft_bzero.c \
		sources/libft/ft_isdigit.c \
		sources/libft/ft_isinstr.c \
		sources/libft/ft_memalloc.c \
		sources/libft/ft_tabset.c \
		sources/libft/ft_memdel.c \
		sources/libft/ft_strchr.c \
		sources/libft/ft_strdup.c \
		sources/libft/ft_strcut.c \
		sources/libft/ft_strlen.c \
		sources/libft/ft_strnjoin.c \
		sources/libft/ft_itoa.c \
		sources/libft/ft_ftoa.c \
		sources/libft/ft_itoa_base.c \
		sources/libft/ft_strisdigit.c \
		sources/libft/ft_strsub.c \
		sources/libft/ft_strnew.c \

LISTS_PATH = ./sources/lists

LISTS = sources/lists/ft_lstdel.c \
		sources/lists/ft_lstaddend.c \
		sources/lists/ft_lstlen.c \
		sources/lists/ft_lstnew.c \
		sources/lists/ft_lstprint.c \

PARSE_PATH = ./sources/parse

PARSE = sources/parse/parse_tests.c \
		sources/parse/parsing.c \

HANDLERS_PATH = ./sources/handlers

HANDLERS = sources/handlers/ft_printf.c \
		   sources/handlers/handle.c \
		   sources/handlers/handle_percent.c \
		   sources/handlers/handle_char.c \
		   sources/handlers/handle_str.c \
		   sources/handlers/handle_signed_int.c \
		   sources/handlers/handle_unsigned_int.c \
		   sources/handlers/handle_hex.c \
		   sources/handlers/handle_oct.c \
		   sources/handlers/handle_p.c \
		   sources/handlers/handle_float.c \


SRCS = $(LIBFT) $(LISTS) $(PARSE)

OBJ = $(LIBFT:.c=.o) $(LISTS:.c=.o) $(PARSE:.c=.o) $(HANDLERS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(LIBFT_PATH)%.o: $(LIBFT)%.c
	@gcc -c $(FLAGS) $(LIBFT)

$(LISTS_PATH)%.o: $(LISTS)%.c
	@gcc -c $(FLAGS) $(LISTS)

$(PARSE_PATH)%.o: $(PARSE)%.c
	@gcc -c $(FLAGS) $(PARSE)

$(HANDLERS_PATH)%.o: $(HANDLERS)%.c
	@gcc - c $(FLAGS) $(HANDLERS)

valgrind:
	@gcc -ggdb3 ./sources/*/*.c test.c -I includes
	@valgrind --leak-check=full --track-origins=yes ./a.out
	@@rm -f $(OBJ) test.o a.out

clean:
	@rm -f $(OBJ)
	@echo "[SUPPRESSION DE LA LIBFT_PRINTF]"

fclean: clean
	@rm -f $(NAME)
	@echo "[SUPPRESSION DES SRCs_PRINTF]"

re: fclean all
