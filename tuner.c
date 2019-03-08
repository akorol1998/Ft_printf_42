/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:13:42 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:19:22 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tuner(char const **point, t_nigga **nig, va_list args)
{
	char	*buf;
	char	c;

	ft_putstr("\n%");
	ft_putstr(" Boo ");
	ft_putstr("%\n");
	buf = NULL;
	c = *(*nig)->conv;
	// system("leaks a.out");
	if ((*nig)->conv && ft_strlen(*point))
	{
		if (c == 'd' || c == 'i')
		{
			ft_putstr("d conversion\n");
			process_piece(*point, nig);			// Shift a little bit in the future
			conversion_d(nig, args);
		}
		else if (c == 'c')
		{
			ft_putstr("c conversion\n");
			buf = process_piece_c(*point, nig);
			conversion_c(buf, nig, args);

		}
		else if (c == 's')
		{
			ft_putstr("\n<s conversion");
			process_piece_s(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		else if (c == 'p')
		{
			ft_putstr("\n<p conversion");
			process_piece_p(*point, nig, args);
			// system("leaks a.out");
			ft_putstr("end of conversion>\n");
		}
		else if (c == 'o' || c == 'u')
		{
			process_piece(*point, nig);
			conv_u(nig, args);
				// system("leaks a.out");
		}
		else if (c == 'f')
		{
			ft_putstr("\n<f conversion");
			piece_f_shit(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		else if (c == 'x' || c == 'X')
		{
			ft_putstr("\n<x conversion");
			piece_hex_shit(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		ft_putstr("hi");
		if (buf)
			free(buf);
		ft_putstr("bye");
	}
	if (!(*nig)->conv)
	{

		ft_putstr("pocker");
		pre_tuner(point, nig);
		ft_putstr("pocker");
	}
	else
		*point = (*nig)->conv + 1;
	fill_my_nigga(&(*nig)->next);
	(*nig) = (*nig)->next;	

	// system("leaks a.out");
}
