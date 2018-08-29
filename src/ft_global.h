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
#define UNKNOWN_FLAG 2

typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long ULONG;

#define Q 1
#define R 2
#define S 4
#define P 8

typedef enum
{
    no_file = 0,
    no_flag,
    error_command,
    try_open_dir
} error_type;

typedef void (*hash_ptr)(char*, int* flags, char* filename);

typedef struct
{
    hash_ptr    hash_ptr;
    int         flags;
} hash_info;

extern const UINT sha256_word[64];

#endif //FT_SSL_MD5_GLOBAL_H
