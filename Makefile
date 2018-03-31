NAME = ft_sha256

CC = gcc

FLAGS = -Ofast -Wextra -Wall -Werror

PATH_SRC = src

PATH_OBJ = obj

PATH_INCLUDES = includes/

SRC =	main.c \
		error.c \
		options.c \
		read_input.c \
		map_file.c \
		fit_data.c \
		hash.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	$(CC) $(FLAGS) -MMD -o $@ -c $< -I includes

clean:
	$(RM) $(OBJ)

fclean: clean

re: clean fclean all

-include $(OBJ:.o=.d)

