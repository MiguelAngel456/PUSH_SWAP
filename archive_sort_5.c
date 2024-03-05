/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_sort_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:58:26 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/04 14:32:37 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//-----------------CON LA AYUDA DE JUAN---------------

void	check_correct_heads(t_lst **head, t_lst *cheapest_node,
		char type_of_stack)
{
	int	size;

	size = ft_lstsize_ps(*head);
	while (*head != cheapest_node)
	{
		if (type_of_stack == 'a')
		{
			if (cheapest_node->index <= (size / 2))
				rotate(head, 'a');
			else
				reverse_rotate(head, 'a');
		}
		else if (type_of_stack == 'b')
		{
			if (cheapest_node->index <= (size / 2))
			{
				rotate(head, 'b');
			}
			else
				reverse_rotate(head, 'b');
		}
	}
}

static void	rotate_cheapest_on_top(t_lst **a, t_lst **b,
		t_lst *loc)
{
	while (*a != loc && *b != loc->node_dst)
		rotate_rr(a, b);
	ft_get_index(a);
	ft_get_index(b);
}

static void	reverse_rotate_cheapest_on_top(t_lst **a, t_lst **b,
		t_lst *loc)
{
	while (*a != loc && *b != loc->node_dst)
		reverse_rotate_rrr(a, b);
	ft_get_index(a);
	ft_get_index(b);
}

void	ft_move_a_to_b(t_lst **a, t_lst **b, t_lst *loc)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	if (loc->index <= size_a / 2
		&& loc->node_dst->index <= size_b / 2)
		rotate_cheapest_on_top(a, b, loc);
	else if (loc->index > size_a / 2
		&& loc->node_dst->index > size_b / 2)
		reverse_rotate_cheapest_on_top(a, b, loc);
	if (loc->index != 0)
		check_correct_heads(a, loc, 'a');
	if (loc->node_dst->index != 0)
		check_correct_heads(b, loc->node_dst, 'b');
	push(b, a, 'b');
}
