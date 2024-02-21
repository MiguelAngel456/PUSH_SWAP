/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:07:27 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/21 12:47:28 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew_ps(int content)
{
	t_lst	*nodo;

	nodo = malloc(sizeof(t_lst));
	if (!nodo)
		return (0);
	nodo->num = content;
	nodo->next = 0;
	return (nodo);
}

void	ft_lstadd_back_ps(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		temp->next->previus = temp;
	}
}

void	ft_free_stack(t_lst *lst)
{
	t_lst	*current;
	t_lst	*aux;

	current = lst;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		free(aux);
	}
}

static int	ignorar_espacios(int cont, char *str)
{
	while (str[cont] == '\t' || str[cont] == '\n'
		|| str[cont] == '\v' || str[cont] == '\f'
		|| str[cont] == '\r' || str[cont] == ' ')
		cont++;
	return (cont);
}

long	ft_atol(const char *str)
{
	int			cont;
	long		num_final;
	char		*original;
	char		signo;

	cont = 0;
	num_final = 0;
	original = (char *)str;
	cont = ignorar_espacios(cont, original);
	signo = str[cont];
	if ((signo != '+' && signo != '-') && (signo < '0' && signo > '9'))
		return (0);
	if ((signo == '+' || signo == '-'))
		cont++;
	while (str[cont] != '\0' && (str[cont] >= '0' && str[cont] <= '9'))
	{
		num_final = num_final * 10 + (str[cont] - '0');
		cont++;
	}
	if (signo == '-')
		num_final = num_final * -1;
	return (num_final);
}
