/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:05:50 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 14:02:48 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Extracts the string with format flags and somehow processes it
 
void	pick_up_args(va_list args, char const *fmt, t_nigga **lopata)
{
	char const	*point;
	char const	*loc;
	t_nigga		*head;

	point = ft_strdup(fmt);
	loc = point;
	head = (*lopata);
	while (*loc)
	{
		// ft_putchar('b');
		// ft_putstr(loc);
		// ft_putchar('b');
		loc = customize_string(loc, lopata);
		ft_putchar('s');
		ft_putstr(loc);
		ft_putchar('s');
		if (*loc)
		{
			loc = double_percent_sign(loc, lopata);			// Handle pointer
		}
		// ft_putchar('%');
		// ft_putchar(loc);
		// ft_putchar('%');
		ft_putstr("\n|>");
		ft_putnbr((*lopata)->zero);
		ft_putstr("|>\n");
		customize_flags(loc, lopata);
		// ft_putchar('%');
		(*lopata) = tuner(&loc, lopata, args);							// Tunner has to process my structure, string and decide what convertion to use
	}

	// printf("%c", *(point));
}

int	ft_printf(const char *restrict fmt, ...)
{
	va_list	args;
	t_nigga	*nig;

	nig = NULL;
	fill_my_nigga(&nig);
	// ft_putnbr(nig->percent);
	va_start(args, fmt);
	pick_up_args(args, fmt, &nig);
	return (0);
}

int	main()
{
	// ft_printf("%+04d", 4);
	
	// ft_printf("%  ", 22);
	
	// ft_printf("Privet%   9.4  d ", 34);
	// ft_putstr("|");
	// ft_printf("%% -8.5d", 34);
	char	*str = "kick-ass";
	int		i = -94;
	double  d = 16.0042695;

	// unsigned long p = c;
	// ft_printf("lock%-15d", i); // Some problems here !!
	// ft_printf("lock%+-5.3d", i);		// CHeck this one
	// printf("%0.0d ewfweg", 0);			// PAY ATTENTION TO THESE CASES
	// ft_printf("lock%# 10.o", i);

	ft_printf("% +0-14f", d);
	printf("\n<% +0-14f>", d);
	// printf("lock%%% 6f", d);
	// printf("% #5.4o", i);
	// printf("<%s>", i);
	// printf("%+1.2d", 1);
	// printf("%d", ft_atoi("010"));
	// printf("%8.5d", 9034);

	
	// printf("%c ewfweg", 0);				//
	// printf("%100%");
	return (0);
}

// 1. "f" flag the processing is prettyr the same as of the "d" flag can use part of it
// 2. Precision and width are again searched for 
// 3. Precision by default outputs 6 digits after point
// 4. Have to manage precision 0, in which case we output only the first part of the number
// 5. Need to compare width and how big is the argument, basically if the width <= "argument`s length" - then we 
//  gonna strjoin any " ", "-", "+", buf if the width is bigger then the argument`s length we gonna just put inside those signs

// '0' is ignored when '-' and ' ' is ignored when '+'

// So firstly - we convert our argument to the double, then to the a string
// 2. Taking it`s length and comparing with the given one
// 3. Creating buffer of a needed size
// 4. Adding flags
// 5. Enjoy


// if zeros and have to put sign put it into the '0' index otherwise