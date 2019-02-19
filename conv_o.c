/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:04:38 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 13:06:52 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_o_conv(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
	{
		ft_putchar('l');
		buf = ft_itoa_base(va_arg(args, long), 8);
	}
	else if ((*nig)->width == 'L')								//careful here with 'L'
	{
		ft_putchar('L');
		buf = ft_itoa_base(va_arg(args, long long), 8);
	}
	else if ((*nig)->width == 'h')
	{
		ft_putchar('h');
		buf = ft_itoa_base((short)va_arg(args, int), 8);
	}
	else if ((*nig)->width == 'H')
	{
		ft_putchar('H');
		buf = ft_itoa_base((signed char)va_arg(args, int), 8);
	}
	else
		buf = ft_itoa_base(va_arg(args, int), 8);
	return (buf);
}

char	*conv_o(char *buf, t_nigga **nig, va_list args)
{
	char 	*digits;
	char 	*del;
	char 	*dest;

	dest = buf;
	digits = open_o_conv(nig, args);
	if ((*nig)->hash)
	{
		del = digits;
		digits = ft_strjoin("0", digits);
		free(del);
	}
	ft_putstr("11111111");
	merging_o(dest, digits, nig);
	ft_putstr("|");
	// system("leaks a.out");
	// '-, '+', '#' flags
	return (dest);
}

void	sign_func_o(char **buf, char *digits, t_nigga **nig)
{
	int		m;
	int		p;
	int		len;
	char	*tmp;

	len = ft_strlen(digits);
	m = (*nig)->m_s;
	p = (*nig)->p_s;
	if ((*nig)->sign == '-')
	{
		sign_func_1(buf, digits, nig);
	}
}

void	merging_o(char *dest, char *digits, t_nigga **nig)
{
	int		len;
	char	*del;

	ft_putstr("\n#");
	ft_putstr(dest);
	ft_putstr("#\n");
	if (dest)
		len = ft_strlen(dest) - ft_strlen(digits);
	if (dest && ft_strlen(dest) && len >= 0)
	{
		push(dest + len, digits);		// Careful, may leak!
		ft_putstr("\n#");
		ft_putstr(dest);
		ft_putstr("#\n");
		sign_func_o(&dest, digits, nig);
	}
	else
		dest = digits;
	// sign_digits_func(dest, &digits, nig);
	if ((*nig)->minus)
	{
		ft_putstr(dest);
		ft_putstr("^ ");
		minus_flag(dest, nig);
	}
	if ((*nig)->out)
	{
		del = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, dest);	
		free(del);
	}
	else
		(*nig)->out = dest;	
	// ft_putstr(dest);
}