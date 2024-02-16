/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:54:44 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/16 16:23:24 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks push_swap > leaks.txt");
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void printList(t_lst* head) {
    t_lst* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
	if(argc >= 2)
	{
		t_lst	*stack_a;//PRIMER NODO
		t_lst	*aux_a;
		t_lst	*stack_b;
		char	**split;
		int		i;

		i = 0;
		stack_a = NULL;
		aux_a = stack_a;
		stack_b = NULL;
		if(argc == 2)
		{
			atexit(ft_leaks);
			split = ft_split(argv[1], ' ');
			if (!split)
				return (0);	
			while(split[i] != (void *)0)
			{
				if(ft_str_is_numeric(split[i]) == 1 && (ft_atol(split[i]) <= FT_INT_MAX && ft_atol(split[i]) >= FT_INT_MIN))
				{	
					aux_a = ft_lstnew_ps(ft_atoi(split[i]));
					ft_lstadd_back_ps(&stack_a, aux_a);
				}else
				{
					ft_printf("ERROR\nNUMERO NO VALIDO");
					ft_free_stack(stack_a);
					return (0);
				}
				i++;
			}
			free_split(split);
		}
		printList(stack_a);
		ft_free_stack(stack_a);
	}
	else
		ft_printf("ERROR\nNUMERO DE ARGUMENTOS NO VALIDO");
	return (0);
}