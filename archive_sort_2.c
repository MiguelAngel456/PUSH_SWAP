/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:47 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/27 15:26:12 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;
	int		index;
	int		size_a;
	int		size_b;

 	temp = *stack_a;
	index = temp->index;
	size_a = ft_lstsize_ps(*stack_a);
	size_b = ft_lstsize_ps(*stack_b);
	while (temp != NULL)
	{
 		temp->cost = temp->index;
		if (temp->index > (size_a / 2))
			temp->cost = size_a - temp->index;
		if (temp->node_dst->index <= (size_b / 2))
		{
			temp->cost += temp->node_dst->index;
		}
		else
			temp->cost += size_b - temp->node_dst->index;
		temp = temp->next;
	}
}

static t_lst	*search_max(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*max;

 	temp = *stack;
	max = temp;
	while(temp != NULL)
	{
		if(temp->num > max->num)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

static void	node_dest_a_b(t_lst **stack_a, t_lst **stack_b)
{
 	int		aux;
	t_lst	*temp;
	t_lst	*temp2;

 	temp = *stack_a;
	temp2 = *stack_b;
	aux = 2147483647;
	while(temp != NULL)
	{
		
		aux = 2147483647;		
		temp2 = *stack_b;
		while(temp2 != NULL)
		{	
			if((temp->num > temp2->num))
			{
				aux = temp->num - temp2->num;
				temp->node_dst = temp2;
			}
			temp2 = temp2->next;			
		}
		if(!temp->node_dst)
			temp->node_dst = search_max(stack_b);
		temp = temp->next;
	}
}
void printList2(t_lst* head) {
    t_lst* temp = head;
	while(temp != NULL) {
		printf("NUM:%d---INDEX:%i---DESTINO FINAL:%i\n", temp->num, temp->index, temp->node_dst->num);
		temp = temp->next;
	}
}
void	sort_final(t_lst **stack_a, t_lst **stack_b)
{
	int		size_a;
	int		size_b;
	t_lst	*temp;
	t_lst	*loc;

	temp = *stack_a;
	if(!*stack_b && ft_lstsize_ps(*stack_a) > 4)
	{
		push(stack_b, stack_a, 'b');
		push(stack_b, stack_a, 'b');
	}
	else
	{
		push(stack_b, stack_a, 'b');
	}
	ft_get_index(stack_a);
	ft_get_index(stack_b);
	node_dest_a_b(stack_a, stack_b);
	cost(stack_a, stack_b);
	size_a = ft_lstsize_ps(*stack_a);
 	while (size_a != 3)
	{
		loc = low_cost(stack_a);
		prepare_b(loc, stack_b);
		prepare_a(loc, stack_a);
		push(stack_b, stack_a, 'b');

		ft_get_index(stack_a);
		ft_get_index(stack_b);
		size_a = ft_lstsize_ps(*stack_a);
		cost(stack_a, stack_b);
		node_dest_a_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	ft_get_index(stack_a);
	node_dest_b_a(stack_b, stack_a);
	node_dest_a_b(stack_a, stack_b);
	size_b = ft_lstsize_ps(*stack_b);
	temp = *stack_b;
 	while(size_b > 0)
	{
		fill_a(*stack_b, stack_a);
		push(stack_a, stack_b, 'a');
		ft_get_index(stack_a);
		ft_get_index(stack_b);
		node_dest_b_a(stack_b, stack_a);
		size_b--;
	}

	lower_num_final(stack_a);
	printf("*******************************\n");
	printList2(*stack_a);
}
