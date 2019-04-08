/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:06:27 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 14:02:31 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*create_buffer(int size)
{
	char	*buf;

	buf = ft_strnew(size);
	return (buf);
}

int			check_min_width_2(int count, char const *str,
	int pos, t_nigga **nig)
{
	int		i;
	char	*buf;
	t_nigga *lol;

	lol = (*nig);
	buf = ft_strsub(str, pos, count);
	i = ft_atoi(buf);
	free(buf);
	return (i);
}

void		check_min_width(char const *str, t_nigga **nig)
{
	int		i;
	int		count;
	int		pos;
	int		a;

	i = 0;
	count = 0;
	pos = 0;
	a = 0;
	str = find_width_digits(str, nig);
	while (str && str[i] && str[i] != '.' && str[i] != *(*nig)->conv)
	{
		if (ft_isdigit(str[i]))
		{

			if (!ft_isdigit(str[i - 1]))
			{
				pos = i;
				count = 0;
			}
			count++;
			a = check_min_width_2(count, str, pos, nig);
			// printf("a digit [%d]\n", a);
			// printf("STRING [%s]\n", str + i);
			if (a)
			{
				// ft_putstr("a here\n");
				(*nig)->m_s = a;
			}
		}
		i++;
	}
	// ft_putstr("==== end ====\n");
}

void		check_precision(char const *str, t_nigga **nig)
{
	int		i;
	char	*buf;
	int		flag;

	i = 0;
	flag = 0;
	str = find_precision_digits(&flag, str, nig);
	while (str && ft_isdigit(str[i]))
		i++;
	buf = ft_strsub(str, 0, i);
	if (i)
		i = ft_atoi(buf);
	else
		i = 0;
	free(buf);
	if (flag && i)
	{
		(*nig)->m_s = i;
		(*nig)->p_s = 0;
	}
	else
		(*nig)->p_s = i;
}
