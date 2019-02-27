/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_processing0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:41:30 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:20:52 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char const	*customize_string(char const *str, t_nigga **lopata)
{
	int		i;
	char	*del;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		i++;
		ft_putstr("\nhere");
		ft_putstr(" O_o ");
		ft_putstr("here\n");
		if (str[i] == '%')
			(*lopata)->arg = 1;
	}
	if (i)
	{
		if (!(*lopata)->out)
		{
			(*lopata)->out = ft_strsub(str, 0, i);			// Need one more condition for strjoin of lopata and str
			ft_putstr((*lopata)->out);
		}
		else
		{
			del = (*lopata)->out;
			(*lopata)->out = ft_strjoin((*lopata)->out, ft_strsub(str, 0, i));
			ft_putstr((*lopata)->out);
			free(del);
		}
	}
	return (str + i);
}

char const	*double_percent_sign(char const *fmt, t_nigga **nig)
{
	char	*buf;

	while (fmt && *(fmt + 1) == '%')
	{
		if (!(*nig)->out)
			(*nig)->out = ft_strsub(fmt, 0, 1);
		else
		{
			buf = (*nig)->out;
			(*nig)->out = ft_strjoin((*nig)->out, ft_strsub(fmt, 0, 1));
			free(buf);
		}
		fmt = customize_string(fmt + 2, nig);
	}
	return (++fmt);
}

void	custom_width(char const *s, t_nigga **nig)
{
	// ft_putstr("\n<W");
	// ft_putchar(*s);
	// ft_putstr("W>\n");
	if (*s != *(s + 1))
		(*nig)->width = *s;
	else
		(*nig)->width = (*s - 32);
}

void	customize_flags_2(char const *s, int i, t_nigga **lopata)
{
	if ((s[i] == 'l' || s[i] == 'h' || s[i] == 'L') && !(*lopata)->width)
			custom_width((s), lopata);
		if (s[i] == '-')
			(*lopata)->minus = s[i];
		if (s[i] == '+')
			(*lopata)->plus = s[i];
		if (s[i] == '#')
			(*lopata)->hash = s[i];
		if (s[i] == ' ')
			(*lopata)->blank = s[i];
		if (!(*lopata)->zero && s[i] == '0' &&
			!ft_isdigit(s[i - 1]) && s[i - 1] != '.')
			(*lopata)->zero = 1;
		if (s[i] != '-' && s[i] != '+' && s[i] != ' ' && s[i] != '#')
			(*lopata)->invalid = 1;
}

void	customize_flags(char const *s, t_nigga **lopata)
{
	int			i;

	i = 0;
	while (s[i] && (s[i] != 'c' && s[i] != 's' && s[i] != 'p' &&
		s[i] != 'd' && s[i] != 'i' && s[i] != 'o' &&
		 s[i] != 'u' && s[i] != 'x' && s[i] != 'f' && s[i] != 'X'))
	{
		customize_flags_2(s, i, lopata);
		i++;
	}
	// ft_putchar(s[i]);
	// ft_putstr("flags @\n");
	// ft_putstr("999");
	// ft_putnbr(i);
	// ft_putstr("flags @\n");
	if (s[i] && (s[i] == 'c' || s[i] == 's' || s[i] == 'p' ||
		s[i] == 'd' || s[i] == 'i' || s[i] == 'o' ||
		 s[i] == 'u' || s[i] == 'x' || s[i] == 'f' || s[i] == 'X'))
	{
		// ft_putstr("***");
		(*lopata)->conv = s + i;
	}
}