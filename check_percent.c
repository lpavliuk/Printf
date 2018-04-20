/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:48:08 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/20 11:27:16 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		separator(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd'
		&& c != 'D' && c != 'i' && c != 'o' &&
		c != 'O' && c != 'u' && c != 'U' &&
		c != 'x' && c != 'X' && c != 'c' && c != 'C')
		return (1);
	else
		return (0);
}

int		check_modifier(const char *format, int i, t_str *pf)
{
	int		k;

	k = 0;
	pf->modifier[k] = format[i];
	k++;
	i++;
	if ((format[i] == 'l' && format[i - 1] == 'l')
		|| (format[i] == 'h' && format[i - 1] == 'h'))
	{
		pf->modifier[k] = format[i];
		k++;
		i++;
	}
	if (!separator(format[i]))
		return (i);
	else
	{
		ft_strclr(pf->modifier);
		return (0);
	}
}

void	check_flags(const char *format, int *i, t_str *pf)
{
	int k;

	k = 0;
	if (format[*i] == '+' || format[*i] == '-')
	{
		pf->flags[k] = format[*i];
		k++;
		(*i)++;
	}
	if (format[*i] == '#')
	{
		pf->flags[k] = format[*i];
		(*i)++;
		k++;
	}
	if (format[*i] == '0' && format[*i - k] != '-')
		pf->flags[k] = format[*i];
}

int		check_percent(const char *format, t_str *pf)
{
	int	i;

	i = 1;
	check_flags(format, &i, pf);
	pf->width = ft_atoi(format + i);
	while (separator(format[i]) && format)
	{
		if (format[i] == '.')
			pf->precision = ft_atoi(format + (++i));
		else if (format[i] == 'h' || format[i] == 'l'
			|| format[i] == 'j' || format[i] == 'z')
		{
			if ((i = check_modifier(format, i, pf)) != 0)
				break ;
			else
				return (0);
		}
		else if (!ft_isdigit(format[i]))
			return (0);
		i++;
	}
	if (!separator(format[i]))
		pf->type = format[i];
	return (i + 1);
}
