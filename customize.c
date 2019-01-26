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
		// ft_putstr("lol");
		i++;
	}
	// ft_putstr("norm string $\n");
	// ft_putnbr(i);
	// ft_putstr("norm string $\n");
	// ft_putnbr((*lopata)->percent);
	i += (*lopata)->percent;
	// ft_putstr(str);	
	if (i)
	{
		if (!(*lopata)->out)
		{
			// ft_putstr("fooooooof");
			(*lopata)->out = ft_strsub(str, 0, i);			// Need one more condition for strjoin of lopata and str
		}
		else
		{
			// ft_putstr("pooooop");
			del = (*lopata)->out;
			(*lopata)->out = ft_strjoin((*lopata)->out, ft_strsub(str, 0, i));
			free(del);
		}
	}
	return (str + i);
}

char const	*double_percent_sign(char const *fmt, t_nigga **nig)
{
	// ft_putstr("percent &\n");
	// ft_putstr(fmt);
	// ft_putstr("percent &\n");
	while (*fmt && *fmt == '%')
	{
		(*nig)->percent++;
		fmt = customize_string(fmt++, nig);
	}
	return (fmt);
}

void	custom_width(char const *s, t_nigga **nig)
{
	ft_putchar(*s);
	ft_putchar((*s + 1));
	if (*s != *(s + 1))
		(*nig)->width = *s;
	else
		(*nig)->width = (*s - 32);
}

void	customize_flags(char const *s, t_nigga **lopata)
{
	int			i;

	i = 0;
	while (s[i] && (s[i] != 'c' && s[i] != 's' && s[i] != 'p' &&
		s[i] != 'd' && s[i] != 'i' && s[i] != 'o' &&
		 s[i] != 'u' && s[i] != 'x' && s[i] != 'f' && s[i] != 'X'))
	{
		if ((s[i] == 'l' || s[i] == 'h' || s[i] == 'L') && !(*lopata)->width)
			custom_width((s + i), lopata);
		if (s[i] == '-')
			(*lopata)->minus = s[i];
		if (s[i] == '+')
			(*lopata)->plus = s[i];
		if (s[i] == '#')
			(*lopata)->hash = s[i];
		if (s[i] == ' ')
			(*lopata)->blank = s[i];
		if (!(*lopata)->zero && s[i] == '0' && !ft_isdigit(s[i - 1]))
			(*lopata)->zero = 1;
		if (s[i] != '-' && s[i] != '+' && s[i] != ' ' && s[i] != '#')
			(*lopata)->invalid = 1;
		i++;
	}
	// ft_putchar(s[i]);
	// ft_putstr("flags @\n");
	// ft_putnbr(i);
	// ft_putstr("flags @\n");
	(*lopata)->conv = s + i;		
}
