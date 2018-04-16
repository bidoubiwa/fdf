/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_char_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:55:57 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 17:13:53 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

char	*ft_one_byte(wchar_t wc)
{
	char	*bin;

	bin = ft_itoa_base(wc + 0x80, 2);
	bin[0] = '0';
	return (bin);
}

char	*ft_four_bytes(wchar_t wc)
{
	char	*bin;
	char	*(*f)(unsigned long long, unsigned int);

	f = &ft_itoa_base_ll;
	bin = ft_strjoin_clr(f((wc >> 18) + 0xF0, 2),
			f(((wc >> 12) & 0x3f) + 0x80, 2));
	bin = ft_strjoin_clr(bin, f(((wc >> 6) & 0x3f) + 0x80, 2));
	bin = ft_strjoin_clr(bin, f((wc & 0x3F) + 0x80, 2));
	return (bin);
}

char	*ft_three_bytes(wchar_t wc)
{
	char			*bin;
	unsigned long	x;
	char			*(*f)(unsigned long long, unsigned int);

	f = &ft_itoa_base_ll;
	bin = ft_strjoin_clr(f((wc >> 12) + 0xE0, 2),
			f(((wc >> 6) & 0x3F) + 0x80, 2));
	x = (wc & 0x3F) + 0x80;
	bin = ft_strjoin_clr(bin, f(x, 2));
	return (bin);
}

char	*ft_two_bytes(wchar_t wc)
{
	char	*bin;

	bin = ft_strjoin_clr(ft_itoa_base((wc >> 6) + 0xC0, 2),
				ft_itoa_base((wc & 0x3F) + 0x80, 2));
	return (bin);
}
