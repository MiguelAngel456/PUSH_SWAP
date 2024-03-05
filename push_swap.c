/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:54:44 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/05 15:03:01 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_order(t_lst **head)
{
	t_lst	*temp;

	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	erros(t_lst **stack)
{
	write(2, "Error\n", 6);
	ft_free_stack(*stack);
	return (1);
}

/* void	ft_leaks(void)
{
	system("leaks push_swap > leaks.txt");
	//atexit(ft_leaks);
} */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

static int	help_normi(char **argv, t_lst *stack_a, t_lst *aux_a, int i)
{
	char	**split;

	if (ft_strlen(argv[1]) == 0)
		return (erros(&stack_a));
	split = ft_split(argv[1], ' ');
	if (!split)
		return (1);
	while (split[i] != (void *)0)
	{
		if (ft_str_is_numeric(split[i]) == 1
			&& (ft_atol(split[i]) <= FT_INT_MAX
				&& ft_atol(split[i]) >= FT_INT_MIN))
		{
			aux_a = ft_lstnew_ps(ft_atoi(split[i]));
			ft_lstadd_back_ps(&stack_a, aux_a);
			if (ft_lstcompare(&stack_a, ft_atol(split[i])) == 1)
				return (erros(&stack_a));
		}
		else
			return (erros(&stack_a));
		i++;
	}
	ft_get_index(&stack_a);
	free_split(split);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*aux_a;
	t_lst	*stack_b;
	int		i;

	if (argc >= 2)
	{
		i = 0;
		stack_a = NULL;
		aux_a = stack_a;
		if (argc == 2)
		{
			if (help_normi(argv, stack_a, aux_a, i) == 1)
				return (1);
			if (is_order(&stack_a) == 1)
				sort(&stack_a, &stack_b);
		}
		if (argc > 2)
		{
			if (help_normi_2(argv, stack_a, argc, stack_b) == 1)
				return (1);
		}
		ft_free_stack(stack_a);
	}
	return (0);
}
