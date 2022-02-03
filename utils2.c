/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:01 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 18:27:17 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	varios(char *s)
{
	int	c;
	int	i;
	int	n;

	i = 0;
	n = 0;
	c = 0;
	while (s[i] != 0)
	{
		if ((n == 2) && (ft_isdigit(s[i])))
		{
			c++;
			n = 1;
		}
		if ((n == 1) && (!ft_isdigit(s[i])))
			n = 2;
		if ((n == 0) && (ft_isdigit(s[i])))
		{
			c++;
			n = 1;
		}
		i++;
	}
	return (c);
}

int	comprobar_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if ((!ft_isdigit(s[i]))
			&& !((ft_issign(s[i])) && ft_isdigit((s[i + 1])))
			&& (!ft_isspace(s[i])))
		{
			write(STDOUT_FILENO, "Error en la entrada\n", 20);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	order(int i)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		i = i >> 1;
		j++;
	}
	return (j);
}

int	simplificate(int x, int numbers[], int n)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (i < n)
	{
		if (numbers[i] < x)
			cont++;
		i++;
	}
	return (cont);
}
