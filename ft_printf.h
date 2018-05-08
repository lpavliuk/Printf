/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:48:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/08 12:43:35 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

//# include <stdio.h>

# define TYPE pf->type
# define MODF pf->modifier
# define SPACE pf->space
# define HASH pf->hash
# define MINUS pf->minus
# define ZERO pf->zero
# define DOT pf->dot
# define PREC pf->precision
# define WIDTH pf->width
# define BUFFER pf->buffer
# define N pf->n
# define N_UNI pf->n_uni

typedef struct	s_str
{
	char		type;
	char		space;
	char		minus;
	char		zero;
	char		dot;
	char		hash;
	char		modifier[3];
	int			precision;
	int			width;
	char		buffer[1024];
	int			n;
	int			symbols;
	int			n_uni;
}				t_str;

int				ft_printf(const char *format, ...);
int				check_percent(va_list ap, const char *format, t_str *pf);
int				write_type_x_p(va_list ap, t_str *pf);
int				write_type_d_i(va_list ap, t_str *pf);
int				write_type_o(va_list ap, t_str *pf);
int				write_type_u(va_list ap, t_str *pf);
int				write_type_c(va_list ap, t_str *pf);
int				write_type_s(va_list ap, t_str *pf);
void			write_symbol_s_uni(t_str *pf, wchar_t *str_uni, int n);
void			write_to_buffer(t_str *pf, int c);
void			write_space_to_buffer(t_str *pf, const char *format, int *i);
void			check_buffer(t_str *pf, int turn_off, int clean_pf);
void			ft_cpy_to_buffer(t_str *pf, unsigned char *code, int len);
void			ft_putnbr_base(intmax_t n, short int base, char big, t_str *pf);
void			ft_unputnbr_base(uintmax_t n, short int base,
											char big, t_str *pf);
uintmax_t		check_modifier_un_int(va_list ap, t_str *pf);

#endif
