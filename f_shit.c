
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

char		*tuning_f_2(double num, t_nigga **nig)
{
	char	*holder;
	int		i;
	int		buf;
	int		a;

	
	// ft_putstr("3___3");
	i = -1;
	buf = 0;
	a = num;
	num = num - a;
	// ft_putstr("4___4");
	holder = remainder_zeros(&num, &i, nig);
	// ft_putstr("5___5");
	// printf("\nPrivet alahakbar%f", num);
	while (++i < (*nig)->p_s)
	{
		buf *= 10;
		num *= 10;
		a = num;
		buf += a % 10;
	}
	// a = num * 10;
	a *= a < 0 ? -1 : 1;
	num *= num < 0 ? -1 : 1;
	// printf("\nGeorge Orwell <%d>", buf);
	if (((a = num * 10) % 10) > 4 && (*nig)->p_s > 0)
	{
		// printf("\nGeorge Orwell <%d>", buf);
		buf += buf < 0 ? -1 : 1;
	}
	if (buf == 0)
		return (holder);
	else
		return (ft_strjoin(holder, mod_itoa(buf, nig)));
}

char		*tuning_f_1(double num, t_nigga **nig)
{
	int		value;
	int		var;

	var = num;
	value = num * 10;
	value %= 10;
	value *= value < 0 ? -1 : 1;
	// var *= var < 0 ? -1 : 1;
	// printf("\n my value %d and another one %d", value, var);
	if (value > 4 && !(*nig)->p_s)
	{
		var += var < 0 ? -1 : 1;
	}
	return (mod_itoa(var, nig));
}

void		tuning_f(t_nigga **nig, va_list args)
{
	double	num;
	char	*buf;
	char	*part_1;
	char	*part_2;

	num = casting_f(nig, args);
	part_1 = tuning_f_1(num, nig);
	part_2 = tuning_f_2(num, nig);
	(*nig)->sign = num < 0  ? '-' : '+';
	buf = part_1;
	if ((*nig)->p_s || (*nig)->hash)
	{
		part_1 = ft_strjoin(part_1, ".");
		free(buf);
		buf = part_1;
	}
	if ((*nig)->p_s > 0)
	{
		part_1 = ft_strjoin(part_1, part_2);
		free(buf);
	}
	buf_tuning_f(part_1, nig);
	printf("\n<%s>", (*nig)->out);
}
// Try to 

void		piece_f_shit(char const *str, t_nigga **nig, va_list args)
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
}
