/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:01:49 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 12:02:03 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion_d(char *buf, t_nigga **nig, va_list args)
{
	char 	*digits;
	char 	*dest;

	dest = buf;

	// zero_func(&buf);
	// ft_putstr(buf);
	digits = open_d_conversion(nig, args);
	ft_putstr("11111111");
	merging(dest, digits, nig);
	if ((*nig)->minus)
	{
		ft_putstr(dest);
		ft_putstr("^ ");
		minus_flag(nig);
	}
	ft_putstr("|");
	// system("leaks a.out");
	// '-, '+', '#' flags
	return (dest);
}

char	*open_d_conversion(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
	{
		ft_putchar('l');
		buf = mod_itoa(va_arg(args, long), nig);
	}
	else if ((*nig)->width == 'L')								//careful here with 'L'
	{
		ft_putchar('L');
		buf = mod_itoa(va_arg(args, long long), nig);
	}
	else if ((*nig)->width == 'h')
	{
		ft_putchar('h');
		buf = mod_itoa((short)va_arg(args, int), nig);
	}
	else if ((*nig)->width == 'H')
	{
		ft_putchar('H');
		buf = mod_itoa((signed char)va_arg(args, int), nig);
	}
	else
		buf = mod_itoa(va_arg(args, int), nig);
	return (buf);
}

void	push(char * dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void	minus_flag_2(char *dest, int *len, int *i)
{
	while (dest[*i])
	{
		if (dest[*i] == ' ')
			*len += 1;
		*i += 1;
	}
}

void	minus_flag(t_nigga **nig)
{
	char	*dest;
	int		len;
	int		i;
	int		j;
	int		f;

	i = 0;
	len = 0;
	f = 0;
	dest = (*nig)->out;
	minus_flag_2(dest, &len, &i); // Seg fault;
	j = -1;
	if ((*nig)->sign == '+' && (*nig)->blank && !(*nig)->plus)
		f = 1;
	while (++j < i)
	{
		if (dest[j] != ' ')
		{
			dest[j - len + f] = dest[j];
			if (j - len + f != j)
				dest[j] = ' ';
		}
	}
}