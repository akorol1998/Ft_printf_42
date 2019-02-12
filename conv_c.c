#include "ft_printf.h"

void	align_c(char *buf, t_nigga **nig, va_list args)
{
	char	*tmp;

	if (*buf)
	{
		if ((*nig)->minus)
		{
			printf("hello");
			buf[0] = va_arg(args, int);
		}
		else
			buf[ft_strlen(buf) - 1] = va_arg(args, int);
	}
	else
	{
		buf = ft_strnew(1);
		buf[0] = va_arg(args, int);
	}
	if ((*nig)->out)
	{
		tmp = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, buf);
		free(tmp);
	}
	else
		(*nig)->out = buf;
}

void	conversion_c(char *buf, t_nigga **nig, va_list args)
{
	align_c(buf, nig, args);
}
