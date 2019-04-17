/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:31:24 by akorol            #+#    #+#             */
/*   Updated: 2019/04/08 16:31:56 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#define CNV "p"
#define A "this is tEEEEst!"

int main()
{
	int nmb = 0;
	// char * str = "a\0a";
	// printf("|%#5"CNV"|\n", nmb);

	// printf("\n{%5.2"CNV"|\n", nmb);
	// ft_printf("\n|%5.2"CNV"}\n", nmb);
	
	// printf("\n{%4.8"CNV"|\n", nmb);
	// ft_printf("\n|%4.8"CNV"}\n", nmb);
	
	// printf("\n{%0.8"CNV"|\n", nmb);
	// ft_printf("\n|%0.8"CNV"}\n", nmb);
	
	// printf("\n{%4."CNV"|\n", nmb);
	// ft_printf("\n|%4."CNV"}\n", nmb);

	// printf("\n{% 0.0"CNV"|\n", nmb);
	// ft_printf("\n|% 0.0"CNV"}\n", nmb);

	// printf("%d", printf("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|", 0,0,0,0,0,0,0,0,0));
	// printf("%d", printf("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t", 0,0,0,0,0,0,0));
	ft_printf("|%0 16.10f|\n", 9.324);
	printf("|%0 16.10f|\n", 9.324);
	// system("leaks a.out");
	// printf("%d", printf("|%3c|\n", 0));
	// printf("%d", printf("|%c|\n", 0));
	// printf("%d", printf("|%-03c|\n", 0));
	// printf("%d", printf("|%03c|\n", 0));
	// printf("%d", printf("|%.c|\n", 0));
	// printf("%d", printf("|%.5c|\n", 0));
	// system("leaks a.out");
	// system("leaks a.out");
	return (0);
}

// 									Zero case
//
// If width is present, then it is the size of the buffer and only zero is present
// if we got dot precision = then tis number of zeros we are creating buffer of 'zeros'
// if  we got dot or precision is zero - then only spaces are being outputted
//
// p conversion with 0 width and 0 precision still prints 0x