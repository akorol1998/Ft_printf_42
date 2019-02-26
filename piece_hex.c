/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:41:32 by akorol            #+#    #+#             */
/*   Updated: 2019/02/26 14:41:34 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Two cases: Argument > actual m_s and m_s > argument`s length
// If Precision is bigger than the minimum width, then we do create the array of p_s size
// Filling with zeros only after we have a solid array with allocated memory
// If we got hash and argument`s length is bigger or equals the precision - we still create array but of the max of (m_s and p_s) and join 0x
// if precision is lower than arg`s length we just concatenate the 0x
// Firstly we decide what array to create (of argument`s length or m_s value)


#include "ft_printf.h"

void		hex_zeros(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == ' ' || buf[i] == 'x')
			buf[i] = '0';
	}
}

void		hex_add(int	min, char *buf, t_nigga **nig)
{
	int		i;
	char	*trash;
	int		space;

	i = -1;
	if (min == (*nig)->p_s && min == ft_strlen(buf))
	{
		trash = buf;
		buf = ft_strjoin("0x", buf);
		free(trash);
	}
	else if ((*nig)->p_s < min)
	{
		space = 0;
		while (buf[++i])
			space += buf[i] == ' ' ? 1 : 0;
		if (space < 2)
			;
	}
}

char		*string_hex_tuning(char *buf, char *tmp, t_nigga **nig)
{
	int			min;
	char		*trash;

	min = (*nig)->m_s > (*nig)->p_s ? (*nig)->m_s : (*nig)->p_s;
	buf	= ft_strnew(min);
	fill2(buf, min);
	if ((*nig)->hash && min - ft_strlen(tmp) < 2)
	{
		trash = buf;
		buf = ft_strjoin(" ", buf);
		free(trash);
	}
	if ((*nig)->minus)
	{
		if ((*nig)->hash)
			custom_strcpy(buf + 2, tmp);
		else
			custom_strcpy(buf + 2, tmp);
	}
	else
		custom_strcpy(buf + ft_strlen(buf) - ft_strlen(tmp), tmp);
	if ((*nig)->zero && (*nig)->minus)
		hex_zeros(buf);
	else if (((*nig)->p_s > (*nig)->m_s || (*nig)->zero) && !(*nig)->minus)
		hex_zeros(buf + ft_strlen(buf) - (*nig)->p_s);
	if ((*nig)->hash)
	{
		if ((*nig)->minus)
			buf[1] = 'x';
		else
			hex_add(min, buf, nig);
	}
}

void		hex_setup(char *tmp, t_nigga **nig)
{
	char		*buf;

	buf = NULL;
	
	if ((*nig)->m_s > ft_strlen(tmp) || (*nig)->p_s > ft_strlen(tmp))
		buf = string_hex_tuning(buf, tmp, nig);
}

void		tuning_hex(t_nigga **nig, va_list args)
{
	char 	*tmp;

	tmp = hex_converter(nig, args);
	hex_setup(tmp, nig);
	useful_function(&tmp, nig);

}

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

void		piece_hex_shit(char const *str, t_nigga **nig, va_list args)
{
	char		*buf;
	char		*p;
	int 		i;
	int			size;

	i = -1;
	p = ft_strchr(str, '.');
	if (p)
	{
		if (ft_isdigit(*(p + 1)))
		{
			(*nig)->p_s = separation_vol3(p, nig);
			(*nig)->m_s = separation(str, p - str);
		}
		else
			(*nig)->m_s = separation_vol3(str, nig);
	}
	else
		(*nig)->m_s = separation_vol3(str, nig);
	tuning_hex(nig, args);
}
