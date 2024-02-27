/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:54:12 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/27 12:34:54 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_lst *src, t_lst **stack_a)
{
	t_lst	*temp;
	int		size;

	temp = *stack_a;
	size = ft_lstsize_ps(*stack_a);
	while (temp != NULL)
	{
		if (src->node_dst->num == temp->num)
		{
			if (temp->index != 0)
			{
				if (temp->index <= size/2)
					rotate(stack_a, 'a');
				else
					reverse_rotate(stack_a, 'a');
				ft_get_index(stack_a);
				temp = *stack_a;
			}
			else
				temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

void	lower_num_final(t_lst **stack_a)
{
	t_lst	*temp;
	t_lst	*min;
	int		tipe;

	temp = *stack_a;
	min = temp;
	while (temp != NULL)
	{
		if(min->num > temp->num)
			min = temp;
		temp = temp->next;
	}
	tipe = 2;
	if (min->index <= (ft_lstsize_ps(*stack_a)/2))
		tipe = 1;
	while (min->index != 0)
	{
		if(tipe == 1)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
		ft_get_index(stack_a);
	}
}