
#include "ft_printf.h"
long double	casting_f(t_nigga **nig, va_list args)
{
	double	buf;

	if ((*nig)->width == 'l')
	{
		ft_putchar('l');
		buf = va_arg(args, double);
	}
	else if ((*nig)->width == 'L')								//careful here with 'L'
	{
		ft_putchar('L');
		buf = va_arg(args, long double);
	}
	else
		buf = va_arg(args, double);
	return (buf);
}

void		tuning_f(t_nigga **nig, va_list args)
{
	double	num;
	char	*arr;
	int		a;
	int		b;
	int		i;

	i = 0;
	num = casting_f(nig, args);
	arr = ft_strnew((*nig)->p_s);
	b = num;
	while (i < (*nig)->p_s)
	{
		num *= 10;
		a = num;
		a %= 10;
		arr[i] = a + '0';
		++i;
	}
	if (((a = num * 10) % 10) > 4)
		arr[i - 1]++;
	printf("\n<%s>", arr);
}

char		*piece_f_shit(char const *str, t_nigga **nig, va_list args)
{
	char		*buf;
	char		*p;
	int 		i;
	int			size;

	i = -1;
	p = ft_strchr(str, '.');
	(*nig)->p_s = 6;
	if (p)
	{
		if (ft_isdigit(*(p + 1)))
		{
			(*nig)->p_s = separation_vol3(p, nig);
			(*nig)->m_s = separation(str, p - str);
		}
		else
		{
			(*nig)->m_s = separation_vol3(str, nig);	
			(*nig)->p_s = 0;
		}
	}
	else
		(*nig)->m_s = separation_vol3(str, nig);
	tuning_f(nig, args);

	printf("\nm_s %d\np_s%d", (*nig)->m_s, (*nig)->p_s);
}

// double = 5.567;
// int	= d * 10;