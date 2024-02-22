NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/src/so_long.c

OBJ = $(patsubst mandatory/src/%.c, mandatory/obj/%.o, $(SRC))

INCLUDE = -I./mandatory/include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

$(OBJ): $(SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) -r $(OBJ) $(wildcard */obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re