/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:03:34 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 18:22:49 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
int		ft_issign(char c);
int		ft_isspace(char c);
int		order(int i);
int		simplificate(int x, int numbers[], int n);
int		ft_atoi(const char *str);
void	push_swap(int n, int a[n], int o);
void	pb(int **a, int **b, int j, int (*tops)[]);
void	reorder(int *a[], int n);
void	paa(int **a, int **b, int (*tops)[], int n);
void	pa(int **a, int **b, int (*tops)[]);
void	ra(int (*tops)[2]);
void	calculate_tops(int **a, int **b, int (*tops)[], int n);
void	inicializar_b(int **b, int n);
int		comprobar(int argc, char **argv);
int		comprobar_arg(char *s);
int		varios(char *s);
char	**ft_split(char const *s, char c);
int		contar_args(int argc, char **argv);
void	numberize(char **argv, int **numbers, int *i, int *tot);
void	asignar_memoria(int *(*numbers)[], int argc, char **argv);

#endif