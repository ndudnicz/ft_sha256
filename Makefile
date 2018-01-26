NAME = ft_md5

CC = gcc

FLAGS = -Werror -Wextra -Wall

PATH_SRC = src

PATH_OBJ = obj

PATH_INCLUDES = includes/

SRC =	main.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): obj $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ) -I includes

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I includes

obj:
	mkdir -p obj/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) libft_malloc.so

re: clean fclean all
