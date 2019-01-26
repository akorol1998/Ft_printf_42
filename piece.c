/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:51:26 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:23:03 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*take_piece(char *point)
{
	char	*pos;

	pos = ft_strchr(point, '%');
	return (pos);
}

char	*process_piece(char const *str, t_nigga **nig)
{
	char	*p;
	char	*buf;
	int		flag;

	buf = NULL;
	flag = 0;
	if ((p = ft_strchr(str, '.')))
	{
		// ft_putstr("hhhhh\n");
		// ft_putstr(str);
		buf = check_for_size(str, p + 1, nig);
	}
	else
	{
		// Problem here!
		check_precision(str, nig);
		(*nig)->m_s = (*nig)->p_s;
		(*nig)->p_s = 0;
		// ft_putchar('\n');
		// ft_putstr("| ");
		// ft_putnbr((*nig)->m_s);
		// ft_putstr(" |");
		if (((*nig)->m_s))				//Write unique  function that will search for digits only ( try p_s instead of m_s)
		{
			ft_putchar('2');
			buf = create_buffer((*nig)->m_s);
			if ((*nig)->zero && !(*nig)->minus)
			{
				// ft_putchar('1');
				// ft_putchar('\n');
				// ft_putstr("| ");
				// ft_putnbr((*nig)->m_s);
				// ft_putstr(" |");
				fill_zero(buf, (*nig)->m_s, (*nig)->m_s);
				// ft_putstr(buf);
			}
			else
				fill_zero(buf, (*nig)->m_s, (*nig)->p_s);
		}
	}
	if (p)	// Add (*nig)->p_s || (*nig)->m_s
	{
			// ft_putstr("yeeee");
			// printf("min: %d \nprecision: %d\n", (*nig)->m_s, (*nig)->p_s);
			fill_zero(buf, find_greater((*nig)->p_s, (*nig)->m_s), (*nig)->p_s);
			// printf("%s len = %lu\n", (buf), ft_strlen(buf));
	}
	if (!buf)
		ft_putstr("Jjjwwwqqqqqqqqq");
	// ft_putstr(buf);
	return (buf);
}
