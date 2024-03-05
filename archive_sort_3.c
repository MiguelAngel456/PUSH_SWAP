/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:54:12 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/04 12:50:10 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*low_cost(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*final;
	int		cheapest_value;

	temp = *stack;
	final = temp;
	cheapest_value = 2147483647;
	while (temp != NULL)
	{
		if (temp->cost < cheapest_value)
		{
			cheapest_value = temp->cost;
			final = temp;
		}
		temp = temp->next;
	}
	return (final);
}

void	prepare_b(t_lst *stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		size;

	temp = *stack_b;
	size = ft_lstsize_ps(*stack_b);
	while (temp != NULL)
	{
		if (stack_a->node_dst->num == temp->num)
		{
			if (temp->index != 0)
			{
				if (temp->index <= size / 2)
					rotate(stack_b, 'b');
				else
					reverse_rotate(stack_b, 'b');
				ft_get_index(stack_b);
				temp = *stack_b;
			}
			else
				temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

void	prepare_a(t_lst *loc, t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		size;

	temp = *stack_a;
	size = ft_lstsize_ps(*stack_a);
	while (temp != NULL)
	{
		if (loc->node_dst->num == temp->num)
		{
			ft_printf("------\n");
			if (temp->index != 0)
			{
				if (temp->index > size / 2)
					reverse_rotate_rrr(stack_a, stack_b);
				else
					rotate_rr(stack_a, stack_b);
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

static t_lst	*search_min(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*min;

	temp = *stack;
	min = temp;
	while (temp != NULL)
	{
		if (temp->num < min->num)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	node_dest_b_a(t_lst **stack_b, t_lst **stack_a)
{
	int		aux;
	t_lst	*temp_a;
	t_lst	*temp_b;

	temp_b = *stack_b;
	aux = 2147483647;
	while (temp_b != NULL)
	{
		temp_a = *stack_a;
		temp_b->node_dst = NULL;
		aux = 2147483647;
		while (temp_a != NULL)
		{
			if ((temp_b->num < temp_a->num) && (temp_a->num < aux))
			{
				aux = temp_a->num;
				temp_b->node_dst = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (!temp_b->node_dst)
			temp_b->node_dst = search_min(stack_a);
		temp_b = temp_b->next;
	}
}
