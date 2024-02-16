/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:48:37 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/15 16:07:01 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_numeric(char *str)
{
	int	cont;

	cont = 0;
	if(str[0] == '-')
		cont++;
	if (str[0] == '\0')
	{
		return (1);
	}
	else
	{
		while (str[cont] != '\0')
		{
			if (str[cont] >= '0' && str[cont] <= '9')
			{
			}
			else
			{
				return (0);
			}
			cont++;
		}
		return (1);
	}
}

/*int main(void)
{
	char str[] = "0D23";
	int a = ft_str_is_numeric(str);
	printf("%d", a);
	return (300);

}*/
