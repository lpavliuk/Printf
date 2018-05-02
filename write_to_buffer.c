/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:00:43 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/02 13:22:51 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cpy_to_buffer(t_str *pf, unsigned char *code)
{
	int i;

	i = 0;
	while (code[i] != '\0')
	{
		if (N > 1023)
			check_buffer(pf, 0, 0);
		BUFFER[N] = code[i];
		i++;
		N++;
	}
}

void		write_to_buffer(t_str *pf, int c)
{
	unsigned char	code[5];

	ft_bzero(code, 5);
	if (c <= 127)
		code[0] = (char)c;
	else if (c <= 2047)
	{
		code[0] = 192 | ((c >> 6) & 31);
		code[1] = 128 | (c & 63);
	}
	else if (c <= 65535)
	{
		code[0] = 224 | ((c >> 12) & 15);
		code[1] = 128 | ((c >> 6) & 63);
		code[2] = 128 | (c & 63);
	}
	else if (c <= 1114111)
	{
		code[0] = 240 | ((c >> 18) & 7);
		code[1] = 128 | ((c >> 12) & 63);
		code[2] = 128 | ((c >> 6) & 63);
		code[3] = 128 | (c & 63);
	}
	ft_cpy_to_buffer(pf, code);
}

void		write_space_to_buffer(t_str *pf, int *i)
{
	int n;
	int x;

	n = 0;
	x = 0;
	if (WIDTH)
	{
		n = N;
		x = WIDTH;
		while (x-- > 1)
			write_to_buffer(pf, ' ');
		N = n;
		*(i) += ft_count(WIDTH);
	}
}