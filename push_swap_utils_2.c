/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:44:00 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/22 09:43:48 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstcompare(t_lst **lst, int num_comp)
{
	t_lst	*temp;

	if (!*lst)
	{
		temp = *lst;
		temp = temp->next;
		return (0);
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			if (temp->num == num_comp)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

void	ft_get_index_f(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*temp2;
	int		aux;

	temp = *lst;
	while (temp != NULL)
	{
		aux = temp->num;
		temp2 = *lst;
		while (temp2 != NULL)
		{
			if (aux < temp2->num)
			{
				temp2->index_f++;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	ft_get_index(t_lst **lst)
{
	t_lst	*temp;
	int		aux;

	temp = *lst;
	aux = 0;
	while (temp != NULL)
	{
		temp->index = aux;
		aux++;
		temp = temp->next;
	}
}

void	ft_lstadd_front_ps(t_lst **lst, t_lst *new)
{
	if (lst || new)
	{
		new->next = *lst;
		new->next->previus = new;
		*lst = new;
	}
}

int	ft_lstsize_ps(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst != 0)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
