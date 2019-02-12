
#include "ft_printf.h"

int		take_number(char **str)
{
	int		i;
	int		res;
	char	*buf;

	i = 0;
	while (ft_isdigit((*str)[i]))
		++i;
	buf = ft_strsub(*str, 0, i);
	res = ft_atoi(buf);
	(*str) += i;
	ft_putnbr(res);
	return (res);

}

char	*take_string(char *str)
{
	int		i;
	char	*buf;

	i = 0;
	while (str[i] && str[i] != '%')
		++i;
	buf = ft_strsub(str, 0, i);
	return (buf);
}
char	*skip_part(char **tab, t_nigga **nig)
{
	int		i;
	int		res;
	char	*copy;
	char	*str;

	copy = *tab;
	i = 0;
	ft_putstr(copy);										// Work here, find a mistake - you can do it
	while (copy && ((*copy) > 'z' || (*copy) < 'A'))
	{
		ft_putstr(copy);
		copy++;
	}
	if ((copy) && ft_isdigit(*copy))
	{
		res = take_number(&copy);
	}
	// ft_putnbr(res);
	// (*nig)->m_s = res;
	// i = 0;
	// while (copy && *copy == ' ')
	// 	copy++;
	// if (copy && *copy)
	// 	str = take_string(copy);
	// return (str);
}

void	fit_in(char *block, char *str, t_nigga **nig)
{
	int	len;
	int	len2;
	int res;
	int	i;

	i = 1;

	fill2(block, (*nig)->m_s);
	len2 = ft_strlen(str);
	len = ft_strlen(block);
	res = len - len2;
	while (--len != res)
	{
		if (i == len2 && (*nig)->minus)				// Don`t know how it will work out, think about it
			block[0] = str[0];
		else
			block[len] = str[len2 - i];
		++i;
	}
}

void	pre_tuner(char const **str, t_nigga **nig)
{
	char	*copy;
	char	*block;

	copy = skip_part((char **)str, nig);		// Skipping all the spaces and counting width
	// if ((*nig)->m_s >= ft_strlen(copy))
	// {
	// 	(*nig)->m_s += 1;
	// 	block = ft_strnew((*nig)->m_s);
	// }
	// else
	// {
	// 	(*nig)->m_s = ft_strlen(copy);			// Checking wether string is bigger than a minimum width
	// 	block = copy;
	// }
	// fit_in(block, copy, nig);					// filling array with a string
	// ft_putstr(block);
}