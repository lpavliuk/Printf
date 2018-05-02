/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:48:08 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/02 19:47:24 by opavliuk         ###   ########.fr       */
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

static void		help_check_flag(const char *format, int i, int *k, t_str *pf)
{
	int is;

	is = 0;
	if (FLAGS[*k] != '\0' && format[i] != FLAGS[*k])
	{
		while (FLAGS[is] != format[i] && is < 4)
			is++;
		if (format[i] != FLAGS[is])
			(*k)++;
		else
			return ;
	}
	FLAGS[*k] = format[i];
}

static void		check_flags(const char *format, int *i, t_str *pf)
{
	int k;
	int minus;

	minus = 0;
	k = 0;
	while ((format[*i] == '0' || !ft_isdigit(format[*i])) && k < 5)
	{
		if (format[*i] == '+' || format[*i] == '-')
		{
			if (format[*i] == '-')
				minus++;
			help_check_flag(format, *i, &k, pf);
		}
		else if (format[*i] == '#')
			help_check_flag(format, *i, &k, pf);
		else if (format[*i] == '0')
			help_check_flag(format, *i, &k, pf);
		else if (format[*i] == ' ')
			help_check_flag(format, *i, &k, pf);
		else if (format[*i] == '.' && format[*i + 1] == ' ')
			DOT = 1;
		else
			return ;
		(*i)++;
	}
}

int				check_percent(const char *format, t_str *pf)
{
	int	i;

	i = 1;
	check_flags(format, &i, pf);
	WIDTH = ft_atoi(format + i);
	write_space_to_buffer(pf, &i);
	while (separator(format[i]) && format)
	{
		if (format[i] == '.' && ++DOT && ++i)
			PREC = ft_atoi(format + (i--));
		else if (format[i] == 'h' || format[i] == 'l'
			|| format[i] == 'j' || format[i] == 'z')
		{
			i = check_modifier(format, i, pf);
			break ;
		}
		else if (!ft_isdigit(format[i]) && format[i] != ' ')
			return (i);
		if (separator(format[i]))
			i++;
	}
	if (!separator(format[i]))
		TYPE = format[i];
	return ((i == 0) ? i : i + 1);
}
