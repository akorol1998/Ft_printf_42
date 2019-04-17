#include "ft_printf.h"

char		*zero_case_precision(t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	if (!(*nig)->dot)
	{
		tmp = ft_strnew(1);
		fill2(tmp, 1);
	}
	else
	{
		tmp = ft_strnew((*nig)->p_s);
		fill2(tmp, (*nig)->p_s);
	}
	fill_wz_zero(tmp);
	return (tmp);
}

void		zeros_combine_funciton(char *tmp, t_nigga **nig)
{
	char 	*final;

	final = NULL;
	if ((*nig)->m_s > (int)ft_strlen(tmp))
	{
		final = ft_strnew((*nig)->m_s);
		fill2(final, (*nig)->m_s);
		if (!(*nig)->minus)
			custom_strcpy(final + (*nig)->m_s - ft_strlen(tmp), tmp);
		else
			custom_strcpy(final, tmp);
		last_piece(final, nig);
	}
	else
	{
		final = ft_strdup(tmp);
		last_piece(final, nig);
	}
}

void		zero_case_function(t_nigga **nig)
{
	char	*tmp;
	char	*zeros;
	char	*trash;

	zeros = NULL;
	trash = NULL;
	tmp = ft_strdup("0x");
	trash = tmp;
	zeros = zero_case_precision(nig);	// Try to make it shorter
	tmp = ft_strjoin(tmp, zeros);
	free(trash);
	free(zeros);
	zeros_combine_funciton(tmp, nig);
	if (tmp)
		free(tmp);
}

// tmp = *(*nig)->conv == 'x' ? ft_strdup("0x") : ft_strdup("0X");
void		zero_case_pure_function(t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	tmp = zero_case_precision(nig);	// Try to make it shorter
	zeros_combine_funciton(tmp, nig);
	if (tmp)
		free(tmp);
}