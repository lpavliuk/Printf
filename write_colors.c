/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:49:43 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/10 21:35:50 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_colors(char *colors, t_str *pf)
{
	if (!ft_strcmp(colors, "eoc"))
		ft_cpy_to_buffer(pf, (unsigned char *)EOC, 4);
	else if (!ft_strcmp(colors,"red"))
		ft_cpy_to_buffer(pf, (unsigned char *)RED, 4);
	else if (!ft_strcmp(colors, "green"))
		ft_cpy_to_buffer(pf, (unsigned char *)GREEN, 4);
	else if (!ft_strcmp(colors, "yellow"))
		ft_cpy_to_buffer(pf, (unsigned char *)YELLOW, 4);
	else if (!ft_strcmp(colors, "blue"))
		ft_cpy_to_buffer(pf, (unsigned char *)BLUE, 4);
	else if (!ft_strcmp(colors, "pink"))
		ft_cpy_to_buffer(pf, (unsigned char *)PINK, 4);
	else if (!ft_strcmp(colors, "white"))
		ft_cpy_to_buffer(pf, (unsigned char *)WHITE, 4);
	else
		return (0);
	return (1);
}

int		write_colors(const char *format, int i, t_str *pf)
{
	short int	n;
	char		colors[7];

	n = 0;
	ft_bzero(colors, 7);
	while (format[i] != '\0')
	{
		if (format[i] == '}')
		{
			if (check_colors(colors, pf))
				return (i);
			break ;
		}
		colors[n] = format[i];
		i++;
		n++;
	}
	return (0);
}