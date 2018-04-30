/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:48:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/19 20:01:36 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

# define FLAGS pf->flags
# define TYPE pf->type
# define MODF pf->modifier
# define PREC pf->precision
# define WIDTH pf->width

typedef struct	s_str
{
	char	type;
	char	flags[4]; 
	char	modifier[3];
	int		precision;
	int		width;
	char	buffer[1024];
}				t_str;

int		ft_printf(const char *format, ...);
int		check_percent(const char *format, t_str *pf);
int		write_type_c(va_list ap, t_str *pf);

#endif