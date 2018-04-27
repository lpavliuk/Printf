/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:25:48 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/27 19:26:44 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	int i = 123;
	char c = 'A';
	char *loc = setlocale(LC_ALL, "");

	ft_putendl("---------| MY PRINTF |---------");

	ft_printf("Hello #%c!\n", 'T');

	printf("-------------| ORIGINAL |-----------\n");

	printf("Hello #%c!\n", 'T');
	return (0);
}