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

t_nigga	*tuner(char const **point, t_nigga **nig, va_list args)
{
	char	*buf;

	ft_putstr("\n<");
	ft_putstr((*nig)->conv);
	ft_putstr((*nig)->out);
	ft_putstr(">\n");
	if ((*nig)->conv && ft_strlen(*point))
	{
		if (*(*nig)->conv == 'd' || *(*nig)->conv == 'i')
		{
			ft_putstr("d conversion\n");
			buf = process_piece(*point, nig);			// Shift a little bit in the future
			buf = conversion_d(buf, nig, args);
		}
		else if (*(*nig)->conv == 'c')
		{
			ft_putstr("c conversion\n");
			buf = process_piece_c(*point, nig);
			conversion_c(buf, nig, args);
		}
		else if (*(*nig)->conv == 's')
		{
			ft_putstr("\n<s conversion");
			process_piece_s(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		else if (*(*nig)->conv == 'p')
		{
			ft_putstr("\n<p conversion");
			process_piece_p(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		else if (*(*nig)->conv == 'o' || *(*nig)->conv == 'u')
		{
			ft_putstr("\n<o conversion");
			buf = process_piece(*point, nig);
			if (*(*nig)->conv == 'u')
				buf = conv_u(buf, nig, args);
			else
				buf = conv_o(buf, nig, args);
			// process_piece_p(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
		else if (*(nig)->conv == 'f')
		{
			ft_putstr("\n<p conversion");
			piece_f_shit(*point, nig, args);
			ft_putstr("end of conversion>\n");
		}
	}
	if (!(*nig)->conv)
	{
		ft_putstr("pocker");
		pre_tuner(point, nig);
		ft_putstr("pocker");
	}
	else
		*point = (*nig)->conv + 1;
	ft_putstr((*nig)->out);
	ft_putstr("\n");
	(*nig) = (*nig)->next;
	fill_my_nigga(nig);
	return (*nig);
}
