/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_GLOBAL_H
#define FT_SSL_MD5_GLOBAL_H

#include <fcntl.h>

#define USAGE_STRING "usage: ft_ssl command [command opts] [command args]\n"
#define STDIN ""
#define BUFFER_SIZE 512

typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long ULONG;

typedef enum
{
    md5 = 1,
    sha256
} hash_type;

extern const UINT sha256_word[64];

#endif //FT_SSL_MD5_GLOBAL_H
