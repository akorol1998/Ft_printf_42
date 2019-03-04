
#include "ft_printf.h"

char	*open_u_conv(t_nigga **nig, va_list args)
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

char	*conv_u(char *buf, t_nigga **nig, va_list args)
{
	char 	*digits;
	char 	*del;
	char 	*dest;

	dest = buf;
	digits = open_u_conv(nig, args);
	// ft_putstr("11111111");
	merging_o(dest, digits, nig);
	// ft_putstr("|");
	// system("leaks a.out");
	// '-, '+', '#' flags
	free(digits);
	return (dest);
}