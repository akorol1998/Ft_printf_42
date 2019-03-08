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

void	process_piece(char const *str, t_nigga **nig)
{
	char	*p;

	if ((p = ft_strchr(str, '.')))
	{
		check_min_width(str, nig);
		check_precision(p, nig);
	}
	else
	{
		check_min_width(str, nig);
		(*nig)->p_s = 0;
		// (*nig)->m_s = (*nig)->p_s;
		
		// if (((*nig)->m_s))				//Write unique  function that will search for digits only ( swap p_s and m_s)
		// {
		// 	ft_putchar('2');
		// 	buf = create_buffer((*nig)->m_s);
		// 	if ((*nig)->zero && !(*nig)->minus)
		// 	{
		// 		// ft_putchar('1');
		// 		// ft_putchar('\n');
		// 		fill_zero(buf, (*nig)->m_s, (*nig)->m_s);
		// 		// ft_putstr(buf);
		// 	}
		// 	else
		// 		fill_zero(buf, (*nig)->m_s, (*nig)->p_s);
		// }
	}
			// ft_putstr("yeeee");
			// printf("min: %d \nprecision: %d\n", (*nig)->m_s, (*nig)->p_s);
			// fill_zero(buf, find_greater((*nig)->p_s, (*nig)->m_s), (*nig)->p_s);
			// printf("%s len = %lu\n", (buf), ft_strlen(buf));
}