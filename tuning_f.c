/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuning_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:21:09 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 15:21:24 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*tuning_f_3(int a, char *holder, t_nigga **nig)
{
	char		*buf;
	char		*buf_2;

	if (a == 0)
		return (holder);
	else
	{
		buf = mod_itoa(a, nig);
		buf_2 = ft_strjoin(holder, buf);
		free(holder);
		free(buf);
		return (buf_2);
	}
}

char			*tuning_f_2(double num, t_nigga **nig)
{
	char		*holder;
	long long	i;
	long long	buf;
	long long	a;

	i = -1;
	buf = 0;
	a = num;
	num = num - a;
	holder = remainder_zeros(&num, &i, nig);
	while (++i < (*nig)->p_s)
	{
		buf *= 10;
		num *= 10;
		a = num;
		buf += a % 10;
	}
	a *= a < 0 ? -1 : 1;
	num *= num < 0 ? -1 : 1;
	if (((a = num * 10) % 10) > 4 && (*nig)->p_s > 0)
		buf += buf < 0 ? -1 : 1;
	return (tuning_f_3(buf, holder, nig));
}

char			*tuning_f_1(double num, t_nigga **nig)
{
	long long	value;
	long long	var;

	var = num;
	value = num * 10;
	value %= 10;
	value *= value < 0 ? -1 : 1;
	if (value > 4 && !(*nig)->p_s)
		var += var < 0 ? -1 : 1;
	return (mod_itoa(var, nig));
}

void			tuning_f_cleaning(char *part_1,
	char *part_2, t_nigga **nig)
{
	char	*buf;

	buf = NULL;
	if ((*nig)->p_s > 0)
	{
		buf = part_1;
		part_1 = ft_strjoin(part_1, part_2);
		free(buf);
	}
	if (part_2)
		free(part_2);
	buf_tuning_f(part_1, nig);	
	if (part_1)
		free(part_1);
}

void			tuning_f(t_nigga **nig, va_list args)
{
	double		num;
	char		*buf;
	char		*part_1;
	char		*part_2;

	part_1 = NULL;
	part_2 = NULL;
	buf = NULL;
	num = casting_f(nig, args);
	if ((num != num) || (num * 89 == num && num != 0))
		nan_inf_function(num, nig);
	else
	{
		part_1 = tuning_f_1(num, nig);
		part_2 = tuning_f_2(num, nig);
		(*nig)->sign = num < 0 ? '-' : '+';
		if ((*nig)->p_s || (*nig)->hash)
		{
			buf = part_1;
			part_1 = ft_strjoin(part_1, ".");
			free(buf);
		}
		tuning_f_cleaning(part_1, part_2, nig);
	}
}
