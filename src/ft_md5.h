/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "ft_global.h"

# define F(x, y, z) ((z) ^ ((x) & ((y) ^ (z))))
# define G(x, y, z) ((y) ^ ((z) & ((x) ^ (y))))
# define H(x, y, z) (((x) ^ (y)) ^ (z))
# define H2(x, y, z) ((x) ^ ((y) ^ (z)))
# define I(x, y, z)	((y) ^ ((x) | ~(z)))

# define STEP(f, a, b, c, d, x, t, s) \
	(a) += f((b), (c), (d)) + (x) + (t); \
	(a) = (((a) << (s)) | (((a) & 0xffffffff) >> (32 - (s)))); \
	(a) += (b);

# define SET(n) \
	(ctx->block[(n)] = \
	(t_uint)ptr[(n) * 4] | \
	((t_uint)ptr[(n) * 4 + 1] << 8) | \
	((t_uint)ptr[(n) * 4 + 2] << 16) | \
	((t_uint)ptr[(n) * 4 + 3] << 24))

# define GET(n) \
	(ctx->block[(n)])

# define OUT(dst, src) \
	(dst)[0] = (t_uchar)(src); \
	(dst)[1] = (t_uchar)((src) >> 8); \
	(dst)[2] = (t_uchar)((src) >> 16); \
	(dst)[3] = (t_uchar)((src) >> 24);

typedef struct	s_md5_info
{
	t_uint	lo;
	t_uint	hi;
	t_uint	a;
	t_uint	b;
	t_uint	c;
	t_uint	d;
	t_uchar	buffer[64];
	t_uint	block[16];
}				t_md5_info;

void			md5_init_start_words(t_md5_info *md5);
void			md5_update_words(t_md5_info *md5, const void *data,\
									t_ulong size);
void			md5_final(t_uchar *result, t_md5_info *md5);

#endif
