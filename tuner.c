/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:13:42 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:19:22 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_nigga	*tuner(char const **point, t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->conv && ft_strlen(*point))
	{
		if (*(*nig)->conv == 'd')
		{
			ft_putstr("d conversion\n");
			buf = process_piece(*point, nig);			// Shift a little bit in the future
			buf = conversion_d(buf, nig, args);
		}
		if (*(*nig)->conv == 'c')
		{
			ft_putstr("c conversion\n");
			buf = process_piece_c(*point, nig);
			conversion_c(buf, nig, args);
		}
		if (*(*nig)->conv == 's')
		{
			ft_putstr("\n<s conversion");
			process_piece_s(*point, nig);
			ft_putstr("end of conversion>\n");
		}
	}
	if (!(*nig)->conv)
	{
		ft_putstr("pocker");
		pre_tuner(point, nig);
		ft_putstr("pocker");
	}
	else
		*point = (*nig)->conv + 1;
	ft_putstr((*nig)->out);
	ft_putstr("mama");
	(*nig) = (*nig)->next;
	fill_my_nigga(nig);
	return (*nig);
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

void	sign_func_1(char **buf, char *digits, t_nigga **nig)
{
	int		m;
	int		p;
	int		len;
	char	*tmp;

	len = ft_strlen(digits);
	m = (*nig)->m_s;
	p = (*nig)->p_s;
	ft_putchar('#');
	if (m > p && len < p)
		(*buf)[m - p - 1] = '-';
	else if (m > p && len >= p && p)
	{
		ft_putchar('b');
		(*buf)[m - len - 1] = '-';
	}
	else if (m > p && len > p && (*nig)->zero)
	{
		// ft_putchar('\n');
		ft_putchar('^');
		// ft_putchar('\n');
		(*buf)[0] = '-';
	}
	else if (m > p && len >= p)
	{
		ft_putchar('a');
		(*buf)[m - len - 1] = '-';
	}
	else if ((p > m) || (m > p && len > p && len == m) || p == m)
	{
		tmp = (*buf);
		ft_putchar('b');
		(*buf) = ft_strjoin("-", (*buf));
		free(tmp);
		// ft_putstr((*buf));
	}
}

void	sign_func(char **buf, char *digits, t_nigga **nig)
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
	if ((*nig)->blank && (*nig)->sign == '+')
	{
		// ft_putstr(*buf);
		if (len == m || p >= m )
			{
				tmp = (*buf);
				(*buf) = ft_strjoin(" ", tmp);
				free(tmp);
				++m;
			}
	}
	if ((*nig)->sign == '+' && (*nig)->plus == '+')
	{
		// ft_putstr(*buf);
		if (m > p && len < p)
			(*buf)[m - p - 1] = '+';
		else if (m > p && len >= p && len < m && p)
		{
			ft_putchar('b');
			(*buf)[m - len - 1] = '+';
		}
		else if (m > p && len > p && (*nig)->zero)
		{
			// ft_putchar('\n');
			ft_putchar('^');
			// ft_putchar('\n');
			(*buf)[0] = '+';
		}
		// else if (m > p && len >= p)
		// {
		// 	ft_putchar('a');
		// 	(*buf)[m - len - 1] = '+';
		// }
		else if ((p > m) || (m > p && len > p && len >= m) || p == m)
		{
			tmp = (*buf);
			ft_putchar('b');
			(*buf) = ft_strjoin("+", (*buf));
			free(tmp);
			// ft_putstr((*buf));
		}
		else
			(*buf)[ft_strlen((*buf)) - len - 1] = '+';
	}
}

void	sign_digits_func(char *dest, char **digits, t_nigga **nig)
{
	char	*tmp;
	int		len;

	if ((*nig)->sign == '-')
	{
		tmp = *digits;
		(*digits) = ft_strjoin("-", *digits);
		free(tmp);
	}
	else if ((*nig)->sign == '+' && (*nig)->blank)
	{
		// len = ft_strlen(*digits);
		tmp = *digits;
		*digits = ft_strjoin(" ", tmp);
		free(tmp);
	}
	if ((*nig)->plus == '+')
	{
		if ((*nig)->blank && (*nig)->sign == '+')
			*digits[0] = '+';
		else
		{
			tmp = *digits;
			(*digits) = ft_strjoin("+", *digits);
			free(tmp);
		}
	}
}

void	merging(char *dest, char *digits, t_nigga **nig)
{
	int		len;
	char	*del;

	// ft_putstr(dest);
	if (dest)
		len = ft_strlen(dest) - ft_strlen(digits);
	if (dest && ft_strlen(dest) && len >= 0)
	{
		push(dest + len, digits);		// Careful, may leak!
		sign_func(&dest, digits, nig);
	}
	else
	{
		sign_digits_func(dest, &digits, nig);
		dest = digits;
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
	{
		printf("hi");
		f = 1;
	}
	while (++j < i)
	{
		if (dest[j] != ' ')
		{
			dest[j - len + f] = dest[j];
			// if (f && ((*nig)->m_s == i))
			// 	;
			if (j - len + f != j)
				dest[j] = ' ';
		}
	}
}

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
	