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
int		ft_lstcompare(t_lst **lst, int num_comp);
void	ft_get_index(t_lst **lst);
void	ft_lstadd_front_ps(t_lst **lst, t_lst *new);
void	swap(t_lst **stack, char tipo);
void	swap_ss(t_lst **stack_a, t_lst **stack_b);
void	push(t_lst **stack_a, t_lst **stack_b, char tipo);
void	push_pp(t_lst **stack_a, t_lst **stack_b);
void	rotate(t_lst **stack, char tipo);
void	rotate_rr(t_lst **stack_a, t_lst **stack_b);
void	reverse_rotate(t_lst **stack, char tipo);
void	reverse_rotate_rrr(t_lst **stack_a, t_lst **stack_b);
int     ft_lstsize_ps(t_lst *lst);
void    sort(t_lst **stack_a);

#endif