/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:47 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/21 12:32:41 by mfuente-         ###   ########.fr       */
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
	if (temp->index > last->index && temp->next->index < last->index)
		rotate(stack, 'a');
	else
	{
		if (temp->next->index > last->index && temp->next->index > temp->index
			&& last->index > temp->index)
		{
			swap(&temp, 'a');
			rotate(stack, 'a');
		}
		else
		{
			if (temp->next->index > last->index
				&& temp->next->index > temp->index
				&& last->index < temp->index)
				reverse_rotate(stack, 'a');
		}
	}
}

static void	sort_three(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*last;

	temp = *stack;
	last = temp->next->next;
	if (temp->index < last->index && temp->next->index < last->index)
		swap(&temp, 'a');
	if (temp->index > last->index
		&& temp->next->index < temp->index && temp->next->index > last->index)
	{
		swap(&temp, 'a');
		reverse_rotate(stack, 'a');
	}
	else
	{
		sort_three_2(stack, temp, last);
	}
}

void	sort(t_lst **stack_a)
{
	if (ft_lstsize_ps(*stack_a) == 2)
		sort_two(stack_a);
	else
	{
		if (ft_lstsize_ps(*stack_a) == 3)
			sort_three(stack_a);
	}
}
