/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:47 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/05 16:49:46 by mfuente-         ###   ########.fr       */
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
	while (temp != NULL)
	{
		if (temp->num > max->num)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

static void	node_dest_a_b(t_lst **a, t_lst **b)
{
	t_lst	*temp_a;
	t_lst	*temp_b;
	bool	found_lowest_best;
	int		lowest_best;

	temp_a = *a;
	while (temp_a != NULL)
	{
		lowest_best = -2147483648;
		temp_b = *b;
		found_lowest_best = false;
		while (temp_b != NULL)
		{
			if (temp_a->num > temp_b->num && temp_b->num > lowest_best)
			{
				lowest_best = temp_b->num;
				temp_a->node_dst = temp_b;
				found_lowest_best = true;
			}
			temp_b = temp_b->next;
		}
		if (found_lowest_best == false)
			temp_a->node_dst = search_max(b);
		temp_a = temp_a->next;
	}
}

static void	help_normi(t_lst **stack_a, t_lst **stack_b, t_lst *temp)
{
	int	size_b;

	sort_three(stack_a);
	ft_get_index(stack_a);
	node_dest_b_a(stack_b, stack_a);
	size_b = ft_lstsize_ps(*stack_b);
	temp = *stack_b;
	while (size_b-- > 0)
	{
		fill_a(*stack_b, stack_a);
		push(stack_a, stack_b, 'a');
		ft_get_index(stack_a);
		ft_get_index(stack_b);
		node_dest_b_a(stack_b, stack_a);
	}
	lower_num_final(stack_a);
}

void	sort_final(t_lst **stack_a, t_lst **stack_b)
{
	int		size_a;
	t_lst	*temp;

	temp = *stack_a;
	if (!*stack_b && ft_lstsize_ps(*stack_a) > 4)
	{
		push(stack_b, stack_a, 'b');
		push(stack_b, stack_a, 'b');
	}
	else
		push(stack_b, stack_a, 'b');
	ft_get_index(stack_a);
	ft_get_index(stack_b);
	node_dest_a_b(stack_a, stack_b);
	cost(stack_a, stack_b);
	size_a = ft_lstsize_ps(*stack_a);
	while (size_a-- > 3)
	{
		ft_move_a_to_b(stack_a, stack_b, low_cost(stack_a));
		ft_get_index(stack_a);
		ft_get_index(stack_b);
		cost(stack_a, stack_b);
		node_dest_a_b(stack_a, stack_b);
	}
	help_normi(stack_a, stack_b, temp);
}
