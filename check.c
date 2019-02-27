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

char		*check_for_size(char const *str, char *p, t_nigga **nig)
{
	char	*buf;
	int		a;

	check_min_width(str, nig);
	ft_putchar('$');
	check_precision(p, nig);
	// system("leaks a.out");
	ft_putchar('&');
	if ((*nig)->m_s > (*nig)->p_s)
	{
		buf = create_buffer((*nig)->m_s);
		// system("leaks a.out");
	}
	else
	{
		buf = create_buffer((*nig)->p_s);
		// system("leaks a.out");
	}
	return (buf);
}

void		check_min_width(char const *str, t_nigga **nig)
{
	int		i;
	char	*buf;

	i = 0;
	str = find_width_digits(str, nig);
	// str = find_precision_digits(str, nig);
	ft_putstr(str);
	while (str && str[i] != '.')
	{
		// ft_putchar('^');
		if (ft_isdigit(str[i]))
			i++;
	}
	if (i)
	{
		buf = ft_strsub(str, 0, i);
		i = ft_atoi(buf);
	}
	free(buf);
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
	num = ft_atoi(buf);
	// system("leaks a.out");
	if(i)
		i = num;
	else
		i = 0;
	free(buf);
	// ft_putnbr(i);								// output here
	(*nig)->p_s = i;
}

