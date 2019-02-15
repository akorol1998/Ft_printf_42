
#include "ft_printf.h"

void	separation_vol2(char const * str, int *min, int len)
{
	int			i;
	int			j;
	char		*dig;

	dig = NULL;
	i = -1;
	ft_putstr("sep2");
	while (++i < len)
	{
		j = 0;
		while (ft_isdigit(str[i + j]) && (str[i + j] != '0' || ft_isdigit(str[i + j - 1])))
		{
			++j;
			if (!ft_isdigit(str[i + j]))
			{
				dig = ft_strsub(str, i, j);	
				*min = ft_atoi(dig);
			}
		}
		i += j;
	}
}

int 	separation(char const *str, int len)
{
	int			min;

	min = 0;
	separation_vol2(str, &min, len);
	return (min);
}

int		separation_vol3(char const *str)
{
	int			i;
	int			j;
	char		*dig;
	int			min;

	min = 0;
	dig = NULL;
	i = -1;
	// ft_putstr("sep3");
	while (str[i] && str[++i] != 'c')
	{
		j = 0;
		// ft_putstr(str);
		// ft_putnbr(i);
		while (str[i + j] && ft_isdigit(str[i + j]) && (str[i + j] != '0' || ft_isdigit(str[i + j - 1])))
		{
			++j;
			if (!ft_isdigit(str[i + j]))
			{
				if (dig)
					free(dig);
				dig = ft_strsub(str, i, j);	
				// ft_putstr(dig);
				// ft_putchar('\n');
				min = ft_atoi(dig);
			}
		}
		i += j;
	}
	if (dig)
		free(dig);
	return (min);
}

char	*fill_for_c(int size, t_nigga **nig)
{
	char	*tab;
	int		i;

	tab = ft_strnew(size);
	i = -1;
	if ((*nig)->zero && !(*nig)->minus)
	{
		while (++i < size)
			tab[i] = '0';
	}
	else
	{
		while (++i < size)
			tab[i] = ' ';
	}
	return (tab);
}

char	*process_piece_c(char const *str, t_nigga **nig)
{
	char		*buf;
	char		*p;
	int 		i;
	int			size;

	i = -1;
	p = ft_strchr(str, '.');
	size = 0;
	if (p)
	{
		if (ft_isdigit(*(p + 1)))
			size = separation(str, p - str);
		else
			size = separation_vol3(str);	
	}
	else
	{
		size = separation_vol3(str);
	}

	// printf("%d", size);
	buf = fill_for_c(size, nig);
	// ft_putstr(buf);
	return (buf);
	printf("%p", str);
}
