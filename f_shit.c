
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

char		*tuning_f_1(double num, t_nigga **nig)
{
	long long int		i;
	long long int		buf;
	long long int		a;

	i = -1;
	buf = 0;
	while (++i < (*nig)->p_s)
	{
		buf *= 10;
		num *= 10;
		a = num;
		buf += a % 10;
	}
	a = num * 10;
	// a %= 10;
	printf("\nGeorge Orwell <%lld>", a);
	if (((a = num * 10) % 10) > 4 && (*nig)->p_s > 0)
	{
		printf("\nGeorge Orwell <%lld>", buf);
		buf++;
	}
	return (mod_itoa(buf, nig));
}

char		*tuning_f_2(double num, t_nigga **nig)
{
	long long int		value;
	long long int		var;

	var = num;
	value = num * 10;
	value %= 10;
	printf("\n my value %d", value);
	if (value > 4)
		var++;
	return (mod_itoa(var, nig));
}

void		tuning_f(t_nigga **nig, va_list args)
{
	double	num;
	char	*buf;
	char	*part_1;
	char	*part_2;

	num = casting_f(nig, args);
	part_1 = tuning_f_2(num, nig);
	part_2 = tuning_f_1(num, nig);
	buf = part_1;
	if ((*nig)->p_s)
	{
		part_1 = ft_strjoin(part_1, ".");
		free(buf);
		buf = part_1;
	}
	if (*part_2 != '0')
	{
		part_1 = ft_strjoin(part_1, part_2);
		free(buf);	
	}
	printf("\n<%s>", part_1);
	printf("\n<%s>", part_2);
}
// Try to 

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