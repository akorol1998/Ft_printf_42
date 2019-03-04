/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:45:52 by akorol            #+#    #+#             */
/*   Updated: 2019/02/13 18:46:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Checking wether we have a precision:
// if it`s lower than argument - we create new string from our argument
// 2. Checking again the value of new string and minimum width if it exist
// 3. Checking wether minimum width is bigger than the length of the argument, if yes - allocating new string for that 
// 4. Checking the '-' flags and adjusting our string properly

#include "ft_printf.h"

void	pick_width(char *fmt, t_nigga **nig)
{
	int		i;
	int		res;
	char	*buf;

	i = 0;
	while (fmt && fmt[i] && ft_isdigit(fmt[i]))
		++i;
	buf = ft_strsub(fmt, 0, i);
	(*nig)->m_s = ft_atoi(buf);
	free(buf);
}

void	pick_precision(char *fmt, t_nigga **nig)
{
	int		i;
	int		res;
	char	*buf;

	i = 0;
	while (fmt && fmt[i] && ft_isdigit(fmt[i]))
		++i;
	buf = ft_strsub(fmt, 0, i);
	(*nig)->p_s = ft_atoi(buf);
	free(buf);
}

void    custom_strcpy(char *str1, char *str2)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(str2);
	i = 0;
	while (i < j)
	{
		str1[i] = str2[i];
		i++;
	}
	ft_putstr(str1);
}

void	length_comparator(t_nigga **nig, va_list args)
{
	char	*str;
	char	*tmp;
	char	*final;
	int		flag;

	str = va_arg(args, char *);
	flag = 0;
	if ((*nig)->p_s < ft_strlen(str) && (*nig)->dot)
	{
		flag = 1;
		tmp = ft_strsub(str, 0, (*nig)->p_s);
	}
	else
		tmp = str;
	if ((*nig)->m_s > ft_strlen(tmp))
	{
		final = ft_strnew((*nig)->m_s);
		fill2(final, (*nig)->m_s);
		if (!(*nig)->minus)
			custom_strcpy(final + (*nig)->m_s - ft_strlen(tmp), tmp);
		else
			custom_strcpy(final, tmp);
		concatenate(final, nig);
		free(final);
		if (flag)
			free(tmp);
	}
	else
	{
		final = tmp;
		concatenate(final, nig);
		if (flag)
			free(final);
	}
}

void	process_piece_s(char const *fmt, t_nigga **nig, va_list args)
{
	char	*buf;
	char	*p;

	buf = (char *)fmt;
	p = ft_strchr(buf, '.');
	if (p)
	{
		(*nig)->dot = 1;
		pick_precision(++p, nig);
	}
	while (buf && *buf && !ft_isdigit(*buf) && *buf != '.')
			buf++;
	if (*buf == '.')
		(*nig)->m_s = 0;
	pick_width(buf, nig);
	ft_putnbr((*nig)->plus);
	length_comparator(nig, args);
	// system("leaks a.out");
}
