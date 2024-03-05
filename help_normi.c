/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_normi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:51:41 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/05 15:03:36 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_normi_2(char **argv, t_lst *stack_a, int argc, t_lst *stack_b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_str_is_numeric(argv[i]) == 1
			&& (ft_atol(argv[i]) <= FT_INT_MAX
				&& ft_atol(argv[i]) >= FT_INT_MIN))
		{
			ft_lstadd_back_ps(&stack_a, ft_lstnew_ps(ft_atoi(argv[i])));
			if (ft_lstcompare(&stack_a, ft_atol(argv[i])) == 1)
				return (erros(&stack_a));
		}
		else
			return (erros(&stack_a));
		i++;
	}
	ft_get_index(&stack_a);
	if (is_order(&stack_a) == 1)
		sort(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	return (0);
}
