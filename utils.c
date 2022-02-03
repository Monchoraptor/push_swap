/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:04:15 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 14:08:19 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_tops(int **a, int **b, int (*tops)[], int n)
{
	int	i;

	i = 0;
	while (((*a)[i] == -1) && i < n)
		i++;
	(*tops)[0] = i;
	i = 0;
	while ((*b)[i] == -1)
		i++;
	(*tops)[1] = i;
}

void	paa(int **a, int **b, int (*tops)[], int n)
{
	int	i;

	i = (*tops)[1];
	while (i < n)
	{
		pa(a, b, tops);
		i++;
	}
}

void	reorder(int *a[], int n)
{
	int	i;
	int	j;

	i = n - 1;
	j = -1;
	while (i >= 0)
	{
		if (((*a)[i] == -1) && (j == -1))
			j = i;
		if (((*a)[i] != -1) && (j != -1))
		{
			(*a)[j] = (*a)[i];
			(*a)[i] = -1;
			i = j;
			j = -1;
		}
		i--;
	}
}
