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

// Seperate When min is bigger and when argument is bigger
//if (p_s > len) >> fill_wz_zero + if (plus) >> strjoin("+")
// if (zero && !p_s && !=minus) >> fill_wz_zero + if (plus) >> buf[0] = '+'
// When min is bigger than actual size - 'space' doesn`t work
// 2Spaces are more  than 1zeros, but 3plus sign is more than spaces

char	*condition_a_part_1(t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strnew((*nig)->p_s);
	fill2(temp, (*nig)->p_s);
	fill_wz_zero(temp);
	ft_putstr("\nhey");
	ft_putstr("\nhey");
	ft_putstr("\nhey");
	if ((*nig)->blank && (*nig)->plus != '+' && (*nig)->sign != '-')
	{
		ft_putstr("\na");
		trash = temp;
		temp = ft_strjoin(" ", trash);
		free(trash);
	}
	else if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		ft_putstr("\nb");
		trash = temp;
		temp = ft_strjoin("+", trash);
		free(trash);
	}
	else if ((*nig)->sign == '-')
	{
		ft_putstr("\n");
		
		trash = temp;
		temp = ft_strjoin("-", trash);
		ft_putstr(temp);
		free(trash);	
	}
	return (temp);
}

char	*condition_a_part_2(t_nigga **nig)
{
	char	*trash;
	char	*temp;

	temp = ft_strnew((*nig)->m_s);
	fill2(temp, (*nig)->m_s);
	fill_wz_zero(temp);
	if ((*nig)->blank)
		temp[0] = ' ';
	else if ((*nig)->plus == '+' && (*nig)->sign == '+')
		temp[0] = '+';
	else if ((*nig)->sign == '-')
		temp[0] = '-';
	return (temp);
}

char	*condition_a_part_3(char *digits, t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strdup(digits);
	if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		trash = temp;
		temp = ft_strjoin("+", trash);
		free(trash);
	}
	else if ((*nig)->sign == '-')
	{
		trash = temp;
		temp = ft_strjoin("-", trash);
		free(trash);	
	}
	return (temp);
}

char	*condition_b(char *digits, t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strdup(digits);
	if ((*nig)->blank && (*nig)->plus != '+' && (*nig)->sign != '-')
	{
		trash = temp;
		temp = ft_strjoin(" ", trash);
		free(trash);
	}
	else if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		trash = temp;
		temp = ft_strjoin("+", trash);
		free(trash);
	}
	else if ((*nig)->sign == '-')
	{
		trash = temp;
		temp = ft_strjoin("-", trash);
		free(trash);	
	}
	return (temp);
}

char	*condition_a(int g, int len, char *digits, t_nigga **nig)
{
	char	*temp;
	char	*box;

	if ((*nig)->p_s > len)
	{
		temp = condition_a_part_1(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
		ft_putstr(temp);
	}
	else if ((*nig)->zero && !(*nig)->p_s && (*nig)->minus != '-')
	{
		temp = condition_a_part_2(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
	}
	else
		temp = condition_a_part_3(digits, nig);
	g = ft_strlen(temp) > g ? ft_strlen(temp) : g;
	box = ft_strnew(g);
	fill2(box, g);
	if ((*nig)->minus)
		custom_strcpy(box, temp);
	else
		custom_strcpy(box + g - ft_strlen(temp), temp);
	return (box);

}

void	conversion_d(t_nigga **nig, va_list args)
{
	char 	*digits;
	char	*buf;
	char	*transfer;
	int		g;
	int		len;

	digits = open_d_conversion(nig, args);
	g = find_greater((*nig)->m_s, (*nig)->p_s);
	len = ft_strlen(digits);
	if (g > len)
		transfer = condition_a(g, len, digits, nig);
	else
		transfer = condition_b(digits, nig);
	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, transfer);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(transfer);
	free(transfer);
	// merging(buf, &digits, nig);
	// if (digits)
	free(digits);

	
	// ft_putstr("\n<");
	// ft_putstr((*nig)->out);
	// ft_putstr(">\n");
	// ft_putstr("|");
	// free(digits);
	
	// system("leaks a.out");
	// '-, '+', '#' flags
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
		// ft_putnbr(va_arg(args, long long));
		// ft_putchar('L');
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

void	minus_flag(char *str, t_nigga **nig)
{
	char	*dest;
	int		len;
	int		i;
	int		j;
	int		f;

	i = 0;
	len = 0;
	f = 0;
	dest = str;
	minus_flag_2(dest, &len, &i); // Seg fault;
	j = -1;
	if ((*nig)->sign == '+' && (*nig)->blank && !(*nig)->plus && *(*nig)->conv != 'o')		// Made changes here
	{
		// ft_putstr("\npokemon");
		f = 1;
	}
	// ft_putstr("\npokemon");
	// ft_putstr(dest);
	// ft_putstr("pokemon\n");
	while (++j < i)
	{
		if (dest[j] != ' ')
		{

			// ft_putnbr(j - len + f);
			// ft_putchar('\n');
			dest[j - len + f] = dest[j];
			if (j - len + f != j)
				dest[j] = ' ';
		}
	}
}