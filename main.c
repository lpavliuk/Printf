/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:25:48 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:39:57 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	int i = 123;
	int n = 0;
	char c = 'A';
	wchar_t str_uni[4] = {2999, 945, 120, 0};
	char *str = "Hello!";
	char *loc = setlocale(LC_ALL, "");
//	printf("MB_CUR_MAX: %i\n", MB_CUR_MAX);
	ft_putendl("---------| MY PRINTF |---------");

	n = ft_printf("%-10.3ls and %-10c world\n", str_uni, 69);
	printf("ft_n: %d\n", n);

	printf("-------------| ORIGINAL |-----------\n");

	n = printf("%-10.3ls and %-10c world\n", str_uni, 69);
	printf("n: %d\n", n);
	return (0);
}