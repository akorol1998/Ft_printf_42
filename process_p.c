/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:17:26 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 11:17:49 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		converter_p(t_nigga **nig, va_list args)
{
	unsigned long	buf;
	char			*tmp;
	char			*final;

	if (*(*nig)->conv == 'p')
		tmp = ft_itoa_base(va_arg(args, unsigned long), 16);
	if ((*nig)->m_s > ft_strlen(tmp))
	{
		final = ft_strnew((*nig)->m_s);
		fill2(final, (*nig)->m_s);
		if (!(*nig)->minus)
			custom_strcpy(final + (*nig)->m_s - ft_strlen(tmp), tmp);
		else
			custom_strcpy(final, tmp);
	}
	else
		final = tmp;
	last_piece(final, nig);
}

void		process_piece_p(char const *fmt, t_nigga **nig, va_list args)
{
	char	*buf;
	char	*p;

	buf = (char *)fmt;
	while (buf && *buf && !ft_isdigit(*buf))
		buf++;
	pick_width(buf, nig);
	ft_putnbr((*nig)->plus);
	converter_p(nig, args);
	// ft_putstr("\n<");
	// ft_putnbr((*nig)->m_s);
	// ft_putstr(">\n");
	// ft_putstr("\n<");
	// ft_putnbr((*nig)->p_s);
	// ft_putstr(">\n");
	// ft_putstr("\n<");
	// ft_putstr((*nig)->out);
	// ft_putstr(">\n");
}