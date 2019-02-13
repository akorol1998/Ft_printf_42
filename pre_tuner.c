#include "ft_printf.h" 

void	pre_tuner(char const **str, t_nigga **nig)
{
	int	i;

	i = 0;

	while (*str && (*str)[i] && (*str)[i] != '%')
	{
		++i;
	}
	(*str) += i;
	(*nig)->conv = (*str);
}























































































// int		take_number(char **str)
// {
// 	int		i;
// 	int		res;
// 	char	*buf;

// 	i = 0;
// 	while (ft_isdigit((*str)[i]))
// 		++i;
// 	buf = ft_strsub(*str, 0, i);
// 	res = ft_atoi(buf);
// 	(*str) += i;
// 	return (res);

// }

// char	*take_string(char *str)
// {
// 	int		i;
// 	char	*buf;

// 	i = 0;
// 	while (str[i] && str[i] != '%')
// 		++i;
// 	buf = ft_strsub(str, 0, i);
// 	return (buf);
// }
// char	*skip_part(char **tab, t_nigga **nig)
// {
// 	int		i;
// 	int		res;
// 	char	*copy;
// 	char	*str;

// 	copy = *tab;
// 	i = 0;
// 	ft_putstr("\n<");
// 	ft_putstr(copy);										// Work here, find a mistake - you can do it
// 	ft_putstr(">\n");
// 	while (copy && !ft_isdigit(*copy))
// 	{
// 		copy++;
// 	}
// 	if ((copy) && ft_isdigit(*copy))
// 	{
// 		res = take_number(&copy);
// 	}
// 	ft_putnbr(res);
// 	(*nig)->m_s = res;
// 	i = 0;
// 	while (copy && (ft_isdigit(*copy) || *copy == '.'))
// 		copy++;
// 	if (copy && *copy)
// 		str = take_string(copy);
// 	ft_putstr("\n<");
// 	ft_putstr(str);
// 	ft_putstr(">\n");
// 	return (str);
// }

// void	fit_in(char *block, char *str, t_nigga **nig)
// {
// 	int	len;
// 	int	len2;
// 	int res;
// 	int	i;

// 	i = 1;

// 	fill2(block, (*nig)->m_s);
// 	len2 = ft_strlen(str);
// 	len = ft_strlen(block);
// 	ft_putstr("\n%");
// 	ft_putnbr(len);
// 	ft_putstr("%\n");
// 	ft_putstr("\n%");
// 	ft_putnbr(len2);
// 	ft_putstr("%\n");
// 	res = len - len2;
// 	while (--len != res)
// 	{
// 		if (i == len2 && (*nig)->minus)				// Don`t know how it will work out, think about it
// 			block[0] = str[0];
// 		else
// 			block[len] = str[len2 - i];
// 		++i;
// 	}
// }