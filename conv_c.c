/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:02:18 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 14:02:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		align_c(char *buf, t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	if ((*nig)->out)
	{
		tmp = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, buf);
		free(tmp);
	}
	else
		(*nig)->out = buf;
}

void		conversion_c(char *buf, t_nigga **nig, va_list args)
{
	int		flag;

	flag = 0;
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
		flag = 1;
	}
	align_c(buf, nig);
	if (flag)
		free(buf);
}
