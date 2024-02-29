/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:36 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/28 14:36:46 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **stack, char tipo)
{
	t_lst	*aux;
	t_lst	*temp;

	temp = *stack;
	aux = temp;
	temp = temp->next;
	while (temp->next)
	{
		temp = temp->next;
	}
	*stack = aux->next;
	aux->next->previus = NULL;
	aux->next = NULL;
	aux->previus = temp;
	temp->next = aux;
	if (tipo == 'a')
		ft_printf("ra\n");
	else
	{
		if (tipo == 'b')
			ft_printf("rb\n");
	}
}

void	rotate_rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a, ' ');
	rotate(stack_b, ' ');
	ft_printf("rr\n");
}

void	reverse_rotate(t_lst **stack, char tipo)
{
	t_lst	*aux;
	t_lst	*temp;

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->previus->next = NULL;
	temp->previus = NULL;
	aux = temp;
	temp->next = NULL;
	temp = *stack;
	temp->previus = aux;
	temp->previus->next = temp;
	*stack = temp->previus;
	if (tipo == 'a')
		ft_printf("rra\n");
	else
	{
		if (tipo == 'b')
			ft_printf("rrb\n");
	}
}

void	reverse_rotate_rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a, ' ');
	reverse_rotate(stack_b, ' ');
	ft_printf("rrr\n");
}
