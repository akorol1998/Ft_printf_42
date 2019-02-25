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

void		useful_function(char **tmp, t_nigga **nig)
{
	char	*trash;
	char	c;
	int		i;

	i = -1;
	c = *(*nig)->conv;
	trash = *tmp;
	if (c == 'p' || ((*nig)->hash && (c == 'x' || c == 'X')))
	{
		*tmp = ft_strjoin("0x", *tmp);
		free(trash);
	}
	if (c == 'X')
	{
		while ((*tmp)[++i])
		{
			if (ft_islower((*tmp)[i]))
				(*tmp)[i] = (*tmp)[i] - 32;
		}
	}
}

char		*hex_converter(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
	{
		ft_putchar('l');
		buf = ft_itoa_base(va_arg(args, unsigned long), 16);
	}
	else if ((*nig)->width == 'L')								//careful here with 'L'
	{
		ft_putchar('L');
		buf = ft_itoa_base(va_arg(args, unsigned long long), 16);
	}
	else if ((*nig)->width == 'h')
	{
		ft_putchar('h');
		buf = ft_itoa_base((unsigned short)va_arg(args, int), 16);
	}
	else if ((*nig)->width == 'H')
	{
		ft_putchar('H');
		buf = ft_itoa_base((unsigned char)va_arg(args, int), 16);
	}
	else
		buf = ft_itoa_base(va_arg(args, unsigned), 16);
	return (buf);	
}

void		converter_p(t_nigga **nig, va_list args)
{
	unsigned long	buf;
	char			*tmp;
	char			*final;

	if (*(*nig)->conv == 'p')
		tmp = ft_itoa_base(va_arg(args, unsigned long), 16);
	else
	{
		ft_putstr("Privet bitch");
		tmp = hex_converter(nig, args);
	}
	useful_function(&tmp, nig);
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