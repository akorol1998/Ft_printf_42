/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_process_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:04:03 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 12:04:12 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"	


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
	if ((*nig)->blank && (*nig)->sign == '+' && !(*nig)->plus)
	{
		// ft_putstr(*buf);
		if (len == m || p >= m )
			{
				tmp = (*buf);
				(*buf) = ft_strjoin(" ", tmp);
				free(tmp);
				++m;
				ft_putstr("\n@");
				ft_putstr(*buf);
				ft_putstr("@\n");
			}
	}
	sign_func_2(buf, digits, len, nig);
}
void	sign_func_2(char **buf, char *digits, int len, t_nigga **nig)
{
	int		m;
	int		p;
	char	*tmp;
	int		i;

	i = -1;
	m = (*nig)->m_s;
	p = (*nig)->p_s;
	if ((*nig)->sign == '+' && (*nig)->plus == '+')
	{
		// ft_putstr("\n+");
		// ft_putstr(*buf);
		// ft_putstr("+\n");
		if (m > p && len < p)
			(*buf)[m - p - 1] = '+';
		else if (m > p && len >= p && len < m && p)
		{
			ft_putchar('b');
			(*buf)[m - len - 1] = '+';
		}
		else if (m > p && !p && (*nig)->zero)
		{
			while (!ft_isdigit((*buf)[++i]))
				;
			(*buf)[i - 1] = '+';
		}
		else if (m > p && len > p && (*nig)->zero)
		{
			ft_putstr("\n|||");
			ft_putstr(digits);
			ft_putstr("|||\n");
			(*buf)[0] = '+';
		}
		else if ((p > m) || (m > p && len > p && len >= m) || p == m)
		{
			ft_putstr("\n<<");
			ft_putstr(tmp);
			ft_putstr(">>\n");
			

			tmp = (*buf);

			(*buf) = ft_strjoin("+", tmp);
			free(tmp);
			// free(tmp);																		// Here are be problems !!!
			// ft_putstr((*buf));
		}
		else
			(*buf)[ft_strlen((*buf)) - len - 1] = '+';
	}
}

void	sign_digits_func(char *dest, char **digits, t_nigga **nig)
{
	char	*tmp;

	if ((*nig)->sign == '-')
	{
		tmp = (*digits);
		(*digits) = ft_strjoin("-", *digits);
		free(tmp);
	}
	else if ((*nig)->sign == '+' && (*nig)->blank)
	{
		tmp = *digits;
		(*digits) = ft_strjoin(" ", tmp);
		free(tmp);
	}
	if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		if ((*nig)->blank && (*nig)->sign == '+')
			(*digits)[0] = '+';
		else
		{
			ft_putstr("\nCheck");
			ft_putstr(*digits);
			ft_putstr("Check\n");
			tmp = (*digits);
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
	free(digits);
}