/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:45:52 by akorol            #+#    #+#             */
/*   Updated: 2019/02/13 18:46:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Checking wether we have a precision:
// if it`s lower than argument - we create new string from our argument
// 2. Checking again the value of new string and minimum width if it exist
// 3. Checking wether minimum width is bigger than the length of the argument, if yes - allocating new string for that 
// 4. Checking the '-' flags and adjusting our string properly

#include "ft_printf.h"

void	pick_width(char *fmt, t_nigga **nig)
{
	int		i;
	char	*

	i = 0;
	while (fmt && fmt[i] && ft_isdigit(fmt[i]))
		++i;

}

void	process_piece_s(char *fmt, t_nigga **nig)
{
	char	*buf;
	char	*p;

	buf = *fmt;
	
	p = ft_strchr(buf, '.')
	if (p)
	{
		while (buf && *buf && ft_isdigit(*buf) && *buf != '.')
			buf++;
		if (*buf == '.')
			(*nig)->m_s = 0;
		else
			pick_width(buf, nig);
		pick_precision(buf, nig);
	}
	pick_numbers(buf, nig);
}
