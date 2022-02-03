/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:04:22 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 18:35:33 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nums[2];
	int	o;
	int	i;

	if (comprobar(argc, argv) < 0)
		exit(-1);
	asignar_memoria(&nums, argc, argv);
	i = 1;
	o = 0;
	while (i < argc)
	{
		numberize(argv, &(nums[0]), &i, &o);
		i++;
	}
	i = 0;
	while (i < contar_args(argc, argv))
	{
		nums[1][i] = simplificate(nums[0][i], nums[0], contar_args(argc, argv));
		i++;
	}
	o = order(argc - 1);
	free(nums[0]);
	push_swap(contar_args(argc, argv), nums[1], o);
	free(nums[1]);
	return (0);
}

void	asignar_memoria(int *(*numbers)[], int argc, char **argv)
{
	int	o;

	o = contar_args(argc, argv);
	(*numbers)[0] = malloc(o * sizeof(int));
	(*numbers)[1] = malloc(o * sizeof(int));
}

void	numberize(char **argv, int **numbers, int *i, int *tot)
{
	char	**splited;
	int		o;

	if (varios(argv[*i]))
	{
		splited = ft_split(argv[*i], ' ');
		o = 0;
		while (splited[o] != NULL)
		{
			numbers[0][*tot] = ft_atoi(splited[o]);
			(*tot)++;
			o++;
		}
	}
	else
	{
		numbers[0][*i -1] = ft_atoi(argv[*i]);
		*tot = *tot + 1;
	}
}

int	contar_args(int argc, char **argv)
{
	int	c;
	int	i;

	c = 0;
	i = 1;
	while (i < argc)
	{
		if (!varios(argv[i]))
				c++;
		else
				c = c + varios(argv[i]);
		i++;
	}
	return (c);
}

int	comprobar(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (comprobar_arg(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
