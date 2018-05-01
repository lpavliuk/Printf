/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:48:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/01 17:32:39 by opavliuk         ###   ########.fr       */
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
# define BUFFER pf->buffer
# define N pf->n

typedef struct	s_str
{
	char	type;
	char	flags[4];
	char	modifier[3];
	int		precision;
	int		width;
	char	buffer[1024];
	int		n;
	int		symbols;
}				t_str;

int				ft_printf(const char *format, ...);
int				check_percent(const char *format, t_str *pf);
int				write_type_c(va_list ap, t_str *pf);
void			write_to_buffer(t_str *pf, int c);
void			write_space_to_buffer(t_str *pf, int *i);

#endif
