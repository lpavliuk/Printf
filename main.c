/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:25:48 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/20 15:32:33 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int i = 123;
	char c = 'A';

	ft_putendl("---------| MY PRINTF |---------");

	ft_printf("Hello #%-15c!\n", c);

	printf("-------------| ORIGINAL |-----------\n");

	printf("Hello #%-15c!\n", c);
	return (0);
}