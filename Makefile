# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 18:05:43 by aalvarez          #+#    #+#              #
#    Updated: 2021/08/16 11:35:21 by aalvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

FILES = so_long			\
		map_fts1		\
		map_fts2		\
		hook_fts1		\
		keymoves_fts1	\
		keymoves_fts2	\
		errors

RM = rm -rf
CC = clang
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -fsanitize=address -g3
FFLAGS = -framework OpenGL -framework AppKit

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./minilibx_opengl_20191021/
	mv ./minilibx_opengl_20191021/libmlx.a .
	$(CC) $(CFLAGS) $(OBJS) -L . -lmlx $(FFLAGS) -o so_long.a

clean:
	$(MAKE) -C ./minilibx_opengl_20191021/ clean
	$(RM) $(OBJS)

all: $(NAME)

re: clean all

fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.a

.PHONY: all re clean fclean
