/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:13:30 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/22 10:35:20 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack, char tipo)
{
	t_lst	*temp;
	int		index;
	int		num;

	if (!(*stack)->next)
		return ;
	temp = (*stack);
	num = temp->num;
	index = temp->index;
	temp->num = temp->next->num;
	temp->index = temp->next->index;
	temp->next->num = num;
	temp->next->index = index;
	if (tipo == 'a')
		ft_printf("sa\n");
	else
	{
		if (tipo == 'b')
			ft_printf("sb\n");
	}
}

void	swap_ss(t_lst **stack_a, t_lst **stack_b)
{
	swap(stack_a, ' ');
	swap(stack_b, ' ');
	ft_printf("ss\n");
}

static void	help_push(char tipo)
{
	if (tipo == 'a')
		ft_printf("pa\n");
	else
		if (tipo == 'b')
			ft_printf("pb\n");
}

//EN CASO DE PA SRC ES B Y DST ES A
void	push(t_lst **dst, t_lst **src, char tipo)
{
	t_lst	*aux;
	t_lst	*temp;
	t_lst	*temp2;

	if (!src)
		return ;
	temp = (*dst);
	temp2 = (*src);
	aux = temp2;
	temp2 = temp2->next;
	*src = temp2;
	temp2->previus->next = NULL;
	temp2->previus = NULL;
	if (!temp)
	{
		temp = aux;
		*dst = temp;
	}
	else
	{
		temp->previus = aux;
		temp->previus->next = temp;
		*dst = temp->previus;
	}
	help_push(tipo);
}

void	push_pp(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_a, stack_b, ' ');
	push(stack_b, stack_a, ' ');
	ft_printf("pp\n");
}
