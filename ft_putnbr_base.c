/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:03:23 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/06 14:11:16 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int n, short int base, char big)
{
	char *bases;

	if (big)
		bases = "0123456789ABCDEF";
	else
		bases = "0123456789abcdef";
	if (n < 0)
		n = n * (-1);
	if (n >= base)
	{
		ft_putnbr_base((n / base), base, big);
		ft_putnbr_base((n % base), base, big);
	}
	else if (n < base)
		ft_putchar(bases[n]);
}
