/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_from_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:07:13 by amoracho          #+#    #+#             */
/*   Updated: 2022/02/03 13:31:15 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static unsigned long	ft_atoul(const char *str)
{
	int				i;
	unsigned long	aux;

	i = 0;
	aux = 0;
	while (ft_isdigit(*(str + i)))
	{
		aux = ((aux * 10) + (*(str + i) - 48));
		if (aux > 9223372036854775808ul)
		{
			return (9223372036854775809ul);
		}
		i++;
	}
	return (aux);
}

int	ft_isspace(char c)
{
	return ((c == '\t')
		|| (c == ' ')
		|| (c == '\n')
		|| (c == '\v')
		|| (c == '\f')
		|| (c == '\r'));
}

int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	aux;
	int				s;

	i = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (ft_issign(*(str + i)) && (!ft_isdigit(*(str + i + 1))))
		return (0);
	s = ft_issign(*(str + i));
	if (ft_issign(*(str + i)))
		i++;
	aux = ft_atoul(str + i);
	if ((aux > 9223372036854775807ul) && (s == 1 || s == 0))
		return (-1);
	else if ((aux > 9223372036854775808ul) && s == -1)
	{
		return (0);
	}
	if (s != 0)
		return ((int)s * aux);
	return ((int)aux);
}
