/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:05:50 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 15:13:49 by akorol           ###   ########.fr       */
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
		// ft_putchar(*point);
		// ft_putchar('%');
		customize_flags(loc, lopata);
		// ft_putchar('%');
		(*lopata) = tuner(&loc, lopata, args);							// Tunner has to process my structure, string and decide what convertion to use
		ft_putchar('|');
		ft_putstr(loc);
		ft_putchar('|');
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
	// ft_printf("%+5.3d", 4);		// CHeck this one
	// ft_printf("%  ", 22);
	
	// ft_printf("Privet%   9.4  d ", 34);
	// ft_putstr("|");
	printf("Privet%   9.4 d 67 d", 34, 24);
	// printf("%+1.2d", 1);
	// printf("%d", ft_atoi("010"));
	// printf("%8.5d", 9034);

	// printf("%0.0d ewfweg", 0);			// PAY ATTENTION TO THESE CASES
	// printf("%c ewfweg", 0);				//
	// printf("%100%");
	return (0);
}

