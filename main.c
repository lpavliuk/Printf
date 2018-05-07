/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:25:48 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/07 17:33:19 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	unsigned int n = 0;
	int base = 2200000;
	char c = 'A';
	wchar_t str_uni[4] = {2999, 945, 6500, 0};
	char *str = "Hello!";
	char *loc = setlocale(LC_ALL, "");
	uintmax_t max = 3223372036854775800;
//	printf("MB_CUR_MAX: %i\n", MB_CUR_MAX);
	// ft_putendl(ft_itoa(2147483647));

	ft_putendl("---------| MY PRINTF |---------");

	n = ft_printf("integer: %#-5.10o\n", 2500);
	printf("ft_n: %d\n", n);

	printf("-------------| ORIGINAL |-----------\n");

	n = printf("integer: %#-5.10o\n", 2500);
	printf("n: %d\n", n);

	return (0);
}