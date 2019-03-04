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

void		pure_nigga(t_nigga *nig)
{
	t_nigga *node;

	while (nig)
	{
		node = nig;
		nig = nig->next;
		free(node);
	}
}

int			concatenating(t_nigga *nig, va_list args)
{
	char	*main;
	char	*trash;
	t_nigga	*node;
	int		i;

	node = nig;
	main = NULL;
	while (node)
	{
		if (main && node->out)
		{
			trash = main;
			main = ft_strjoin(main, node->out);
			free(trash);
		}
		else if (node->out)
			main = ft_strdup(node->out);
		free(node->out);
		node = node->next;
	}
	ft_putstr(main);
	pure_nigga(nig);
	va_end(args);
	free(main);
	return (ft_strlen(main));
}


int			pick_up_args(va_list args, char const *fmt, t_nigga **lopata)
{
	char const	*point;
	char const	*loc;
	t_nigga		*head;
	t_nigga		*del;
	int			i;

	point = ft_strdup(fmt);
	loc = point;
	head = (*lopata);
	while (*loc)
	{
		loc = customize_string(loc, lopata);
		// ft_putchar('s');
		// ft_putstr(loc);
		// ft_putchar('s');
		if (*loc)
			loc = double_percent_sign(loc, lopata);			// Handle pointer
		// system("leaks a.out");
		// ft_putstr("\n|>");
		// ft_putnbr((*lopata)->zero);
		// ft_putstr("|>\n");
		customize_flags(loc, lopata);
		del = *lopata;
		if ((*lopata)->conv)
			tuner(&loc, lopata, args);
		// system("leaks a.out");
		// ft_putstr("\nb");
		// ft_putstr(loc);
		// ft_putstr("b\n");
	}
	free((void *)point);
	return (concatenating(head, args));
}

int			ft_printf(const char *restrict fmt, ...)
{
	va_list	args;
	t_nigga	*nig;

	nig = NULL;
	fill_my_nigga(&nig);
	// ft_putnbr(nig->percent);
	va_start(args, fmt);
	return (pick_up_args(args, fmt, &nig));
}

int	main()
{
	// ft_printf("%+04d", 4);
	
	// ft_printf("%  ", 22);
	
	// ft_printf("Privet%   9.4  d ", 34);
	// ft_putstr("|");
	// ft_printf("%% -8.5d", 34);
	char	*str = "kick-ass";
	unsigned int i = 9265;
	double  d = 544434;
	char	c = 76;

	// unsigned long p = c;
	// printf("%0.0d ewfweg", 0);			// PAY ATTENTION TO THESE CASES
	// ft_printf("lock%# 10.o", i);
	// ft_printf("%1.5f", -0.0000); 	//Not working right
	// printf("123%#233.5c%  we rt ery% regre %o ef", i, str);

	// ft_printf("%p", str);
	ft_printf("\n[%0+10.23i%% regre %c ef", i, c);	// This one passes the tests
	printf("\n[%0+10.23i%% regre %c ef", i, c);
	system("leaks a.out");
	


	// 	ft_putstr("\n<");
	// ft_putstr("LEAK");
	// ft_putstr(">\n");

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



