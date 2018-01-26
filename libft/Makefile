NAME = libft.a
OBJ = $(SRC:%.c=%.o)
ifeq ($(shell uname -s),Linux)
	SRC := ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_strrchr.c ft_strdel.c \
		ft_memalloc.c ft_strncpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strncat.c ft_putnchar.c \
		ft_strstr.c ft_strnstr.c ft_strncmp.c ft_memdel.c \
		ft_strnew.c ft_include_strstr.c ft_sleep.c ft_numberlen.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c ft_putnbr_fd.c ft_putnstr.c get_next_line.c \
		ft_putnbr_endl.c ft_strdupchr.c ft_strlenchr.c ft_strndup.c \
		ft_itoa_base.c ft_putbase.c ft_include_int.c ft_atoi_base.c \
		ft_putbase_uint64.c ft_strcpy.c ft_strdup.c ft_memccpy.c ft_ltoa.c \
		ft_strjoin_free.c ft_array_length.c
else
	SRC := ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_strrchr.c ft_strdel.c \
		ft_memalloc.c ft_strncpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strncat.c ft_putnchar.c \
		ft_strstr.c ft_strnstr.c ft_strncmp.c ft_memdel.c \
		ft_strnew.c ft_include_strstr.c ft_sleep.c ft_numberlen.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c ft_putnbr_fd.c ft_putnstr.c get_next_line.c \
		ft_putnbr_endl.c ft_strdupchr.c ft_strlenchr.c ft_strndup.c \
		ft_itoa_base.c ft_putbase.c ft_include_int.c ft_atoi_base.c \
		ft_putbase_uint64.c ft_strcpy.c ft_memccpy.c ft_ltoa.c \
		ft_strjoin_free.c ft_array_length.c
endif
CXX = gcc
FLAGS = -Werror -Wextra -Wall
SRC_DIR = src
OBJ_DIR = obj
OBJ = $(SRC:%.c=obj/%.o)

all: libasm $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CXX) $(FLAGS) -c $< -o $@ -I includes

libasm:
	@make -C libftasm
	@ln -fs libftasm/libfts.a libftasm.a
	@ln -sf libft/libft.a ..
	@ln -sf libft/libftasm.a ..

obj:
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C libftasm
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libftasm
	rm -f libftasm.a
	/bin/rm -f $(NAME)

re: clean fclean all

.PHONY: all libasm obj clean fclean re libftasm
