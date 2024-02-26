/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:54:12 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/26 09:44:08 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*low_cost(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*final;

	temp = *stack;
	final = temp;
	while(temp != NULL)
	{
		if(temp->cost < final->cost)
			final = temp;
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
				if (temp->index <= size/2)
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

void	prepare_a(t_lst *loc, t_lst **stack_a)
{
	t_lst	*temp;
	int		size;

	temp = *stack_a;
	size = ft_lstsize_ps(*stack_a);
	while (temp != NULL)
	{
		if (loc->node_dst->num == temp->num)
		{
			if (temp->index != 0)
			{
				if (temp->index > size/2)
					reverse_rotate(stack_a, 'b');
				else
					rotate(stack_a, 'b');
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

static void	node_dest_b_a(t_lst **stack_a, t_lst **stack_b)
{
 	int		max;
	int		num_a;
	t_lst	*temp;
	t_lst	*temp2;

 	temp = *stack_b;
	num_a = temp->num;
	temp2 = *stack_a;
	while(temp != NULL)
	{
		
		num_a = temp->num;
		temp2 = *stack_a;
		while(temp2 != NULL)
		{	
			if(num_a < temp2->num)
			{
				if(temp->num < max)
				{
					temp->node_dst = temp2;
					max = temp->node_dst->num;
				}
			}			
			temp2 = temp2->next;			
		}
		if(!temp->node_dst)
			temp->node_dst = search_max(stack_a);
		temp = temp->next;
	}
}
