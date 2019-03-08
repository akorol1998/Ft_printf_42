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

char	*create_buffer(int	size)
{
	char	*buf;

	// system("leaks a.out");
	buf = ft_strnew(size);
	return (buf);
}


void		check_min_width(char const *str, t_nigga **nig)
{
	int		i;
	int		count;
	int		pos;
	char	*buf;

	i = 0;
	count = 0;
	pos = 0;
	str = find_width_digits(str, nig);

	// str = find_precision_digits(str, nig);
	// ft_putstr("\nPickachu");
	// ft_putstr(" LOOP ");
	// ft_putstr("Pickachu\n");
	ft_putnbr((*nig)->zero);
	while (str && str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]))
		{
			if (!ft_isdigit(str[i - 1]))
			{
				pos = i;
				count = 0;
			}
			count++;
		}
		i++;
		// ft_putstr("\nPickachu");
		// ft_putstr(" LOOP ");
		// ft_putstr("Pickachu\n");
	}
	ft_putnbr(pos);
	ft_putnbr(count);
	if (count)
	{
		buf = ft_strsub(str, pos, count);
		i = ft_atoi(buf);
		free(buf);
	}
	(*nig)->m_s = i;
}

// counts the number of  after "." if it exists

void		check_precision(char const *str, t_nigga **nig)
{
	int		i;
	int		num;
	char	*buf;

	i = 0;
	str = find_precision_digits(str, nig);
	// if (str && str[i] == '0')
	// {
	// 	// ft_putstr(str);
	// 	(*nig)->zero = *flag != -1? 1: 0;
	// 	// ft_putstr(str);
	// 	*flag += 1;
	// 	// ft_putstr(str);
	// }
	while (str && ft_isdigit(str[i]))
		i++;
	// ft_putstr("112");

	buf = ft_strsub(str, 0, i);


	// system("leaks a.out");
	if(i)
		i = ft_atoi(buf);
	else
		i = 0;
	free(buf);

	(*nig)->p_s = i;
}

