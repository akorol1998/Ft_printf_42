
#include "ft_printf.h"

char	*process_piece_c(char const *str, t_nigga **nig)
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
			(*nig)->m_s = separation_vol3(str);
			(*nig)->p_s = separation(str, p - str);
		}
		else
		{
			(*nig)->m_s = separation_vol3(str);	
			(*nig)->p_s = 0;
		}
	}
	else
		(*nig)->m_s = separation_vol3(str);
	
}