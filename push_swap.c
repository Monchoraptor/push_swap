/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:01:31 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 18:29:50 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	inicializar_tops(int (*tops)[], int n)
{
	(*tops)[0] = 0;
	(*tops)[1] = n - 1;
}

void	call_pb(int **a, int **b, int (*tops)[], int j, int n)
{
	if ((*tops)[1] == n)
		(*tops)[1]--;
	pb(a, b, j, tops);
}

void	extra_job(int **a, int **b, int (*tops)[], int n)
{
	reorder(a, n);
	calculate_tops(a, b, tops, n);
	paa(a, b, tops, n);
}

void	push_swap(int n, int a[n], int o)
{
	int	tops[2];
	int	i;
	int	j;
	int	*b;

	inicializar_tops(&tops, n);
	inicializar_b(&b, n);
	i = -1;
	while (++i < o)
	{
		if (i != 0)
			calculate_tops(&a, &b, &tops, n);
		j = 0;
		while (j < n)
		{
			if ((a[j] >> i) & 1)
				ra(&tops);
			else
				call_pb(&a, &b, &tops, j, n);
			j++;
		}
		extra_job(&a, &b, &tops, n);
	}
	free(b);
}

void	inicializar_b(int **b, int n)
{
	int	i;

	*b = malloc(n * sizeof(int));
	i = 0;
	while (i < n)
		(*b)[i++] = -1;
}
