/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:59:13 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 16:17:14 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_aux1(const char *s, char c)
{
	int	i;

	i = 0;
	if (*s != c && *s)
	{
		s++;
		i++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				i++;
		}
		s++;
	}
	return (i);
}

static int	ft_aux2(const char *str, char c)
{
	int	cu;

	cu = 0;
	while (*str != c && *str)
	{
		cu++;
		str++;
	}
	return (cu);
}

static void	*ft_aux3(char **ar)
{
	int		i;

	i = 0;
	while (ar[i])
	{
		free(ar[i++]);
	}
	free(ar);
	return (NULL);
}

void	init(int *j, int *i, int jn, int in)
{
	*j = jn;
	*i = in;
}

char	**ft_split(char const *s, char c)
{
	int			j;
	int			i;
	char		**ar;

	init(&j, &i, 0, 0);
	ar = (char **)malloc(sizeof(char *) * (ft_aux1(s, c) + 1));
	if (!s || (!ar))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			ar[j] = (char *)malloc(sizeof(char) * (ft_aux2(s, c) + 1));
			if (!ar)
				return (ft_aux3(ar));
			while (*s && *s != c)
				ar[j][i++] = (char)*s++;
			ar[j][i] = '\0';
			init(&j, &i, j + 1, 0);
		}
	}
	ar[j] = NULL;
	return (ar);
}
