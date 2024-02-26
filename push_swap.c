/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:54:44 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/23 18:37:36 by mfuente-         ###   ########.fr       */
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
		printf("NUM:%d---INDEX:%i---INDEX FINAL:%i---DESTINO FINAL:%i---COSTE:%i\n", temp->num, temp->index, temp->index_f, temp->node_dst->num,temp->cost);
		//printf("NUM:%d---INDEX:%i---INDEX FINAL:%i\n", temp->num, temp->index, temp->index_f);
		temp = temp->next;
	}
}
int main(int argc, char **argv)
{
	if(argc >= 2)
	{
		t_lst	*stack_a;
		t_lst	*aux_a;
		t_lst	*stack_b;
		char	**split;
		int		i;

		i = 0;
		stack_a = NULL;
		aux_a = stack_a;
		stack_b = NULL;
		split = NULL;
		if(argc == 2)
		{
			atexit(ft_leaks);
			split = ft_split(argv[1], ' ');
			if (!split)
				return (0);	
			while(split[i] != (void *)0)
			{
				if(ft_str_is_numeric(split[i]) == 1 && (ft_atol(split[i]) <= FT_INT_MAX
					&& ft_atol(split[i]) >= FT_INT_MIN))
				{
					aux_a = ft_lstnew_ps(ft_atoi(split[i]));
					ft_lstadd_back_ps(&stack_a, aux_a);
					if(ft_lstcompare(&stack_a, ft_atol(split[i])) == 1)
					{
						ft_printf("ERROR\n");
						ft_free_stack(stack_a);
						return (0);
					}
				}else
				{
					ft_printf("ERROR\n");
					ft_free_stack(stack_a);
					return (0);
				}
				i++;
			}
			ft_get_index(&stack_a);
			ft_get_index_f(&stack_a);
			free_split(split);
		}else
		{
			i = 1;
			while(i < argc)
			{
				if(ft_str_is_numeric(argv[i]) == 1 && (ft_atol(argv[i]) <= FT_INT_MAX
					&& ft_atol(argv[i]) >= FT_INT_MIN))
				{
					aux_a = ft_lstnew_ps(ft_atoi(argv[i]));
					ft_lstadd_back_ps(&stack_a, aux_a);
					if(ft_lstcompare(&stack_a, ft_atol(argv[i])) == 1)
					{
						ft_printf("ERROR\n");
						ft_free_stack(stack_a);
						return (0);
					}
				}else
				{
					ft_printf("ERROR\n");
					ft_free_stack(stack_a);
					return (0);
				}
				i++;
			}
			ft_get_index(&stack_a);
			ft_get_index_f(&stack_a);
		}
		sort(&stack_a, &stack_b);
		//printList(stack_a);
		
		ft_free_stack(stack_a);
	}
	return (0);
}
