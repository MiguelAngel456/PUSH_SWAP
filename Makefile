#VARIABLES
NAME = push_swap
BONUS_NAME = so_long_bonus
CC = gcc -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
LIBFT_PATH = ./libft

#ARCHIVOS
FILES = archive_sort_4.c\
		archive_sort_3.c\
		archive_sort_2.c\
		archive_sort.c\
		operations.c\
		operations_2.c\
		push_swap_utils.c\
		push_swap_utils_2.c\
		push_swap.c\

#CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)

#COMPILA LOS ARCHIVOS
#SE ENCARGA DE QUE AGREGAR A LA LIBRERIA .A LOS OBJETOS
all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	make -C $(LIBFT_PATH)
	$(CC) -I ./push_swap.h -c $< -o $@

#ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN FT_PRINTF

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re