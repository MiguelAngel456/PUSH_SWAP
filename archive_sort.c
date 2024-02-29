/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:47 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/27 15:35:10 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void pos_max(t_lst **stack)

static void	sort_two(t_lst **stack)
{
	t_lst	*temp;

	temp = *stack;
	if (temp->next->num < temp->num)
	{
		swap(stack, 'a');
	}
}

static void	sort_three_2(t_lst **stack, t_lst *temp, t_lst *last)
{
	if (temp->index_f > last->index_f && temp->next->index_f < last->index_f)
		rotate(stack, 'a');
	else
	{
		if (temp->next->index_f > last->index_f
			&& temp->next->index_f > temp->index_f
			&& last->index_f > temp->index_f)
		{
			swap(&temp, 'a');
			rotate(stack, 'a');
		}
		else
		{
			if (temp->next->index_f > last->index_f
				&& temp->next->index_f > temp->index_f
				&& last->index_f < temp->index_f)
				reverse_rotate(stack, 'a');
		}
	}
}
//PRIMER IF: SI EL DEL MEDIO ES MAS PEQUEÑO QUE EL PRIMERO Y EL PRIMERO MAS PEQUEÑO QUE EL ULTIMO
//
//SEGUNDO IF: SI EL DEL MEDIO ES MAS PEQUEÑO QUE EL PRIMERO, SI EL ULTIMO ES MAS PEQUEÑO QUE EL PRIMERO
//			  Y EL ULTIMO ES MAS GRANDE QUE EL DEL MEDIO
//
//TERCER IF: SI EL DEL MEDIO ES MAS GRANDE QUE EL PRIMERO, SI EL DEL MEDIO ES MAS GRANDE QUE EL ULTIMO
//			 Y SI EL PRIMERO ES MAS PEQUEÑO QUE EL ULTIMO
//
//CUARTO IF: SI EL DEL MEDIO ES MAYOR AL PRIMERO, SI EL DEL MEDIO ES MAYOR AL ULTIMO Y SI EL PRIMERO ES
//			 MAYOR AL ULTIMO
//
//QUINTO IF: SI EL DEL MEDIO ES MAYOR A AL PRIMERO, EL DEL MEDIO ES AL ULTIMO Y EL PRIMERO ES MAYOR A
//			 AL ULTIMO
//
//SEXTO IF: SI EL PRIMERO ES MAYOR AL DEL MEDIO, EL PRIMERO ES MAYOR AL ULTIMO Y EL DEL MEDIO ES MAYOR 
//			AL ULTIMO
void	sort_three(t_lst **stack)
{
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		swap(stack, 'a');
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		rotate(stack, 'a');
	else if ((*stack)->next->num > (*stack)->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if ((*stack)->next->num > (*stack)->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		reverse_rotate(stack, 'a');
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num > (*stack)->next->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}

void	sort(t_lst **stack_a, t_lst **stack_b)
{
	if (ft_lstsize_ps(*stack_a) == 2)
		sort_two(stack_a);
	else
	{
		if (ft_lstsize_ps(*stack_a) == 3)
			sort_three(stack_a);
		else
			sort_final(stack_a, stack_b);
	}
}
