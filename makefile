NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_SRC = mandatory/src/so_long.c

OBJ = $(patsubst mandatory/src/%.c, mandatory/obj/%.o, $(MANDATORY_SRC))

INCLUDE = -I./mandatory/include

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): $(MANDATORY_SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: clean
clean:
	$(RM) -r $(OBJ) $(wildcard */obj)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
