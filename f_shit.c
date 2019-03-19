/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_shit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:49:10 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 14:49:14 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	casting_f(t_nigga **nig, va_list args)
{
	double	box;

	if ((*nig)->width == 'L')
		box = (long double)va_arg(args, double);
	else
		box = va_arg(args, double);
	return (box);
}

void		piece_f_shit(char const *str, t_nigga **nig, va_list args)
{
	char	*buf;
	char	*p;
	int		i;
	int		size;

	i = -1;
	p = ft_strchr(str, '.');
	(*nig)->p_s = 6;
	if (p)
	{
		if (ft_isdigit(*(p + 1)))
		{
			(*nig)->p_s = separation_vol3(p, nig);
			(*nig)->m_s = separation(str, p - str);
		}
		else
		{
			(*nig)->m_s = separation_vol3(str, nig);
			(*nig)->p_s = 0;
		}
	}
	else
		(*nig)->m_s = separation_vol3(str, nig);
	tuning_f(nig, args);
}
