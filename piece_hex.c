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

void		hex_capital(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] = buf[i] - 32;
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

void		zero_tunage(char **tmp, t_nigga **nig)
{
	char	*arr1;
	char	*trash;
	int		len;

	len = ft_strlen(*tmp);
	if ((*nig)->p_s > len)
	{
		arr1 = ft_strnew((*nig)->p_s);
		fill2(arr1, (*nig)->p_s);
		fill_wz_zero(arr1);
		custom_strcpy(arr1 + (*nig)->p_s - len, *tmp);
		free(*tmp);
		(*tmp) = arr1;
		ft_putstr("\n$");
		ft_putstr(*tmp);
		ft_putstr("$\n");
	}
	else if (!(*nig)->p_s && (*nig)->zero && !(*nig)->minus)
	{
		arr1 = ft_strnew((*nig)->m_s);
		fill2(arr1, (*nig)->m_s);
		fill_wz_zero(arr1);
		custom_strcpy(arr1 + (*nig)->m_s - len, *tmp);
		free(*tmp);
		(*tmp) = arr1;
		if ((*nig)->hash)
			(*tmp)[1] = 'x';
	}
	if (((*nig)->hash && (*nig)->p_s > len) ||
		((*tmp)[0] != '0' && (*tmp)[1] != 'x' && (*nig)->hash))
	{
		ft_putstr("\n(");
		ft_putstr(*tmp);
		ft_putstr(")\n");
		trash = *tmp;
		*tmp = ft_strjoin("0x", trash);
		free(trash);
	}
	if ((*tmp)[1] != 'x' && (*nig)->hash)
	{
		(*tmp)[0] = '0';
		(*tmp)[1] = 'x';
	}
}

// Creating out BUFFER

char		*string_hex_tuning(int len, char *buf, char *tmp, t_nigga **nig)
{
	int			min;
	char		*trash;

	buf	= ft_strnew(len);
	fill2(buf, len);
	zero_tunage(&tmp, nig);
	if ((*nig)->minus)
		custom_strcpy(buf, tmp);
	else
		custom_strcpy(buf + ft_strlen(buf) - ft_strlen(tmp), tmp);
	free(tmp);
	return (buf);
}


//  PLaying with WIDTH and RECISION
 
char		*hex_setup(char *tmp, t_nigga **nig)
{
	char		*buf;
	int			len;

	buf = NULL;
	len = ft_strlen(tmp);
	if ((*nig)->hash)
	{
		if (((*nig)->m_s > len || (*nig)->p_s > len))
		{	
			if ((*nig)->p_s + 2 < (*nig)->m_s)
			{
				if ((*nig)->m_s - len < 2)
					(*nig)->m_s++;
				buf = string_hex_tuning((*nig)->m_s, buf, tmp, nig);
			}
			else
				buf = string_hex_tuning((*nig)->p_s + 2, buf, tmp, nig);
		}
		else
			buf = ft_strjoin("0x", tmp);
	}
	else
	{
		if ((*nig)->m_s > len || (*nig)->p_s > len)
			buf = string_hex_tuning(ft_max((*nig)->m_s, (*nig)->p_s), buf, tmp, nig);
		else
			buf = tmp;
	}
	return (buf);
}

void		tuning_hex(t_nigga **nig, va_list args)
{
	char 	*tmp;
	char	*result;

	tmp = hex_converter(nig, args);
	result = hex_setup(tmp, nig);
	if (*(*nig)->conv == 'X')
		hex_capital(result);
	if ((*nig)->out)
	{
		tmp = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, result);
		free(tmp);
	}
	else
	{
		(*nig)->out = ft_strdup(result);
		free(result);
	}
	// system("leaks a.out");
	ft_putstr("\n<");
	ft_putstr(result);
	ft_putstr(">\n");

	// useful_function(&tmp, nig);

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
