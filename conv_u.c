
#include "ft_printf.h"

char	*open_u_conversion(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
	{
		ft_putchar('l');
		buf = mod_itoa(va_arg(args, unsigned long), nig);
	}
	else if ((*nig)->width == 'L')								//careful here with 'L'
	{
		ft_putchar('L');
		buf = mod_itoa(va_arg(args, unsigned long long), nig);
	}
	else if ((*nig)->width == 'h')
	{
		ft_putchar('h');
		buf = mod_itoa((unsigned short)va_arg(args, int), nig);
	}
	else if ((*nig)->width == 'H')
	{
		ft_putchar('H');
		buf = mod_itoa((unsigned char)va_arg(args, int), nig);
	}
	else
		buf = mod_itoa(va_arg(args, unsigned), nig);
	return (buf);
}

// char	*conv_u(t_nigga **nig, va_list args)
// {
// 	char 	*digits;
// 	char 	*del;
// 	char 	*dest;

// 	dest = buf;
// 	digits = open_u_conv(nig, args);
// 	// ft_putstr("11111111");
// 	merging_o(dest, digits, nig);
// 	// ft_putstr("|");
// 	// system("leaks a.out");
// 	// '-, '+', '#' flags
// 	free(digits);
// 	return (dest);
// }

char	*cond_part_1(t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strnew((*nig)->p_s);
	fill2(temp, (*nig)->p_s);
	fill_wz_zero(temp);
	return (temp);
}

char	*cond_part_2(t_nigga **nig)
{
	char	*trash;
	char	*temp;

	temp = ft_strnew((*nig)->m_s);
	fill2(temp, (*nig)->m_s);
	fill_wz_zero(temp);
	return (temp);
}

char	*cond_b(char *digits, t_nigga **nig)
{
	char	*temp;
	char	*trash;

	if ((*nig)->hash && *(*nig)->conv == 'o')	
		temp = ft_strjoin("0", digits);
	else
		temp = ft_strdup(digits);
	return (temp);
}

char	*cond_a(int g, int len, char *digits, t_nigga **nig)
{
	char	*temp;
	char	*box;

	if ((*nig)->p_s > len)
		temp = cond_part_1(nig);
	else if ((*nig)->zero && !(*nig)->p_s && (*nig)->minus != '-')
		temp = cond_part_2(nig);
	else
	{
		if ((*nig)->hash && *(*nig)->conv == 'o')
			temp = ft_strjoin("0", digits);
		else
			temp = ft_strdup(digits);
	}
	box = ft_strnew(g);
	fill2(box, g);
	if ((*nig)->minus)
		custom_strcpy(box, temp);
	else
		custom_strcpy(box + g - ft_strlen(temp), temp);
	return (box);
}


void	conv_u(t_nigga **nig, va_list args)
{
	char 	*digits;
	char	*buf;
	char	*transfer;
	int		g;

	if (*(*nig)->conv == 'u')
		digits = open_u_conversion(nig, args);
	else
		digits = open_o_conv(nig, args);
	g = find_greater((*nig)->m_s, (*nig)->p_s);
	if (g > ft_strlen(digits))
		transfer = cond_a(g, ft_strlen(digits), digits, nig);
	else
		transfer = cond_b(digits, nig);
	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, transfer);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(transfer);
	free(transfer);
	free(digits);
}