/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:48:08 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/06 18:00:00 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		separator(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd'
		&& c != 'D' && c != 'i' && c != 'o' &&
		c != 'O' && c != 'u' && c != 'U' && c != '%' &&
		c != 'x' && c != 'X' && c != 'c' && c != 'C')
		return (1);
	else
		return (0);
}

static int		check_modifier(const char *format, int i, t_str *pf)
{
	int		k;

	k = 0;
	MODF[k] = format[i];
	k++;
	i++;
	if ((format[i] == 'l' && format[i - 1] == 'l')
		|| (format[i] == 'h' && format[i - 1] == 'h'))
	{
		MODF[k] = format[i];
		k++;
		i++;
	}
	if (!separator(format[i]))
		return (i);
	else
	{
		ft_strclr(MODF);
		return (0);
	}
}

static void		check_flags(const char *format, int *i, t_str *pf)
{
	int k;

	k = 0;
	while ((format[*i] == '0' || !ft_isdigit(format[*i])) && k < 5)
	{
		if (format[*i] == '+' || format[*i] == '-')
		{
			if (format[*i] == '-')
				MINUS++;
		}
		else if (format[*i] == '#')
			HASH++;
		else if (format[*i] == '0')
			ZERO++;
		else if (format[*i] == ' ')
			SPACE++;
		else if (format[*i] == '.' && format[*i + 1] == ' ')
			DOT = 1;
		else
			return ;
		(*i)++;
	}
}

static void		check_star(va_list ap, const char *format, t_str *pf, int *i)
{
	int n;

	n = *i;
	if (format[*i] == '*')
	{
		WIDTH = va_arg(ap, int);
		while (format[n] != '.' && !ft_isalpha(format[n]))
		{
			if (format[n] == '0' && !ZERO)
				ZERO++;
			n++;
		}
	}
	else if (format[*i] == '.' && format[*i + 1] == '*')
	{
		PREC = va_arg(ap, int);
		if (PREC >= 0)
			(*i)++;
	}
	else if (format[*i] == '.' && ++(*i))
		PREC = ft_atoi(format + (*i)--);
	else
		WIDTH = ft_atoi(format + *i);
	if (PREC < 0 && ++(*i) && (DOT * 0))
		PREC = 0;
}

int				check_percent(va_list ap, const char *format, t_str *pf)
{
	int	i;

	i = 1;
	check_flags(format, &i, pf);
	check_star(ap, format, pf, &i);
	write_space_to_buffer(pf, format, &i);
	while (separator(format[i]) && format)
	{
		if (format[i] == '.' && ++DOT)
			check_star(ap, format, pf, &i);
		else if (format[i] == 'h' || format[i] == 'l'
			|| format[i] == 'j' || format[i] == 'z')
		{
			i = check_modifier(format, i, pf);
			break ;
		}
		else if (!ft_isdigit(format[i]) && format[i] != ' ')
			break ;
		if (separator(format[i]))
			i++;
	}
	TYPE = format[i];
	return ((i == 0) ? i : i + 1);
}
