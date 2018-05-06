/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:25:48 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/06 14:43:10 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(int argc, char **argv)
{
	int i = 123;
	int n = 0;
	char c = 'A';
	wchar_t str_uni[4] = {2999, 945, 6500, 0};
	char *str = "Hello!";
	char *loc = setlocale(LC_ALL, "");
//	printf("MB_CUR_MAX: %i\n", MB_CUR_MAX);
	ft_putendl("---------| MY PRINTF |---------");

	n = ft_printf("%-20.5S and world\n", str_uni);
	printf("ft_n: %d\n", n);

	printf("-------------| ORIGINAL |-----------\n");

	n = printf("%-20.5S and world\n", str_uni);
	printf("n: %d\n", n);

	if (argc > 1)
		ft_putnbr_base(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	return (0);
}