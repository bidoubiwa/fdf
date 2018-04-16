/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:03:47 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 18:47:04 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HPRINTF_H
# define HPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# define UIL unsigned long
# include "libft.h"

typedef	struct		s_flag
{
	int				left;
	int				blank;
	int				plus;
	int				zero;
	int				apos;
	int				hash;
}					t_flag;

typedef struct		s_chain
{
	t_flag			*flag;
	int				just_show;
	size_t			width;
	size_t			nbr_carac;
	size_t			nbr_byte;
	int				give_p;
	size_t			prec;
	char			len;
	char			conv;
	int				maj;
	int				error;
	char			cnull;
	int				(*f)(struct s_chain *, va_list ap);
	char			*show;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_len
{
	char			c;
	char			*len;
	int				i;
}					t_len;

typedef	struct		s_conv
{
	char			conv;
	int				(*f)(t_chain *, va_list ap);
}					t_conv;

int					ft_printf(const char *restrict format, ...);
const char			*ft_parser(const char *format,
		t_chain *elem, t_chain **chain);
/*
** PARSER FUNCTIONS
*/
int					ft_find_flag(char c, t_chain *elem);
const char			*ft_find_width(const char *format, t_chain *elem);
const char			*ft_find_precision(const char *format, t_chain *elem);
const char			*ft_find_length(const char *format, t_chain *elem);
int					ft_is_conv(char c, t_chain *elem);
/*
** HANDLER FUNCTIONS
*/
int					ft_handler(va_list ap, t_chain *chain);
int					ft_int_handler(t_chain *elem, va_list ap);
int					ft_error_handler(t_chain *elem, va_list ap);
int					ft_uint_handler(t_chain *elem, va_list ap);
int					ft_str_handler(t_chain *elem, va_list ap);
int					ft_str_w_handler(t_chain *elem, va_list ap);
char				*ft_one_byte(wchar_t wc);
char				*ft_two_bytes(wchar_t wc);
char				*ft_three_bytes(wchar_t wc);
char				*ft_four_bytes(wchar_t wc);
int					ft_percent_handler(t_chain *elem, va_list ap);
int					ft_null_w_char(t_chain *elem);
char				*ft_prec_on_w(t_chain *elem);
int					ft_show_all(t_chain *elem);
int					ft_show_error(t_chain *elem, t_chain *begin);
t_chain				*ft_lstfree(t_chain *current);
/*
** FLAG FUNCTIONS
*/
char				*ft_plus(t_chain *elem, char c);
char				*ft_precision(t_chain *elem);
char				*ft_width(t_chain *elem, t_flag *flag);
char				*ft_maj(t_chain *elem);
char				*ft_0x_hexa(char *show, char c, t_chain *elem);
char				*ft_0_octal(char *show);
char				*ft_hash(t_chain *elem);
int					ft_str_modifier(t_chain *elem, t_flag *flag);
/*
** CHAINED LIST FUNCTIONS
*/
t_chain				*ft_create_elem(void);
void				ft_setup_chain_info(t_chain *elem, t_flag *flag);
void				ft_lstadd_after(t_chain *elem, t_chain **chain);
int					ft_show_only_parser(const char *format,
		size_t len, t_chain **chain);
t_chain				*ft_get_dollar_order(t_chain *chain);
/*
** UTILITY FUNCTIONS
*/
int					ft_is_decimal(char b);
int					ft_is_integer(char b);
char				*ft_start_digit(char *str, t_chain *elem);
int					ft_get_base(char c);
int					ft_need_toupper(char c);
int					ft_is_w_char(t_chain *elem);
static	t_len		g_len[] =
{
	{'H', "hh*", 2},
	{'h', "h*", 1},
	{'m', "ll*", 2},
	{'l', "l*", 1},
	{'L', "L*", 1},
	{'j', "j*", 1},
	{'z', "z*", 1},
	{'\0', NULL, 0}
};

static t_conv	g_conv[] =
{
	{'d', &ft_int_handler},
	{'D', &ft_int_handler},
	{'i', &ft_int_handler},
	{'u', &ft_uint_handler},
	{'U', &ft_uint_handler},
	{'o', &ft_uint_handler},
	{'O', &ft_uint_handler},
	{'x', &ft_uint_handler},
	{'X', &ft_uint_handler},
	{'s', &ft_str_handler},
	{'S', &ft_str_w_handler},
	{'c', &ft_str_handler},
	{'C', &ft_str_w_handler},
	{'p', &ft_uint_handler},
	{'%', &ft_percent_handler},
	{0, NULL}
};
#endif
