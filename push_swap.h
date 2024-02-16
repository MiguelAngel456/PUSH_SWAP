#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//LIBRERIAS NECESARIAS
# include <stdarg.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_lst
{
	int				num; //NUMERO
    int				index; //POSICION
	struct s_lst	*next; //SIGUIENTE
    struct s_lst    *previus; //ANTERIOR
}	t_lst; //APODO

//FUNCIONES
int		check_is_number(char num);
void	ft_lstadd_back_ps(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew_ps(int content);
void	ft_free_stack(t_lst *lst);
void	ft_leaks(void);
long	ft_atol(const char *str);

#endif