/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:04:27 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 14:08:05 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int **a, int **b, int (*tops)[])
{
	write(STDOUT_FILENO, "pa\n", 3);
	(*a)[(*tops)[0] - 1] = (*b)[(*tops)[1]];
	(*b)[(*tops)[1]] = -1;
	(*tops)[0] = (*tops)[0] - 1;
	(*tops)[1] = (*tops)[1] + 1;
}

void	ra(int (*tops)[2])
{
	write(STDOUT_FILENO, "ra\n", 3);
	**tops = **tops + 1;
}

void	pb(int **a, int **b, int j, int (*tops)[])
{
	write(STDOUT_FILENO, "pb\n", 3);
	(*b)[(*tops)[1]] = (*a)[j];
	(*a)[j] = -1;
	(*tops)[1] = (*tops)[1] - 1;
	(*tops)[0] = (*tops)[0] + 1;
}
