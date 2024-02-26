/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:47 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/23 18:46:50 by mfuente-         ###   ########.fr       */
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
		if (temp->next->index_f > last->index_f && temp->next->index_f > temp->index_f
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

void	sort_three(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*last;

	temp = *stack;
	last = temp->next->next;
	if (temp->index_f < last->index_f && temp->next->index_f < last->index_f)
		swap(&temp, 'a');
	if (temp->index_f > last->index_f
		&& temp->next->index_f < temp->index_f && temp->next->index_f > last->index_f)
	{
		swap(&temp, 'a');
		reverse_rotate(stack, 'a');
	}
	else
	{
		sort_three_2(stack, temp, last);
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
