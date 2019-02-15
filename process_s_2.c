#include "ft_printf.h"

void	last_piece(char	*fin, t_nigga **nig)
{
	char	*buf;

	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, fin);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(fin);
}