/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

#include "../libft/libft.h"
#include "ft_global.h"

#define SHA256_OUTPUT_SIZE 32

#define ROTATE_RIGHT(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHIFT_RIGHT(x, n) ((x) >> (n))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define EP1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))
#define SIG0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ SHIFT_RIGHT(x, 3))
#define SIG1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ SHIFT_RIGHT(x, 10))

#define ZERO_BIT 			0x00
#define START_PADDING 		0x80
#define NUM_OF_START_WORDS 	8
#define MAX_SIZE_OF_WORD 	64
#define SYMBOL_SIZE		    8
#define MAX_SHIFT           24
#define INT_STEP            4
#define START_VALUE         0
#define MESSAGE_BYTE_SIZE   56

typedef struct
{
	UCHAR	data[MAX_SIZE_OF_WORD];
	UINT	datalen;
	ULONG	bitlen;
	UINT	start_word[NUM_OF_START_WORDS];
} sha256_info;

// init start words
void sha256_init_start_words(UINT (*info)[NUM_OF_START_WORDS]);

// update words
void sha256_update_words(sha256_info* sha_info, const unsigned char* data, size_t len);
void sha256_transform_words(sha256_info* sha);
void sha256_data_transformation(sha256_info *sha, UINT (*new_data)[MAX_SIZE_OF_WORD]);
void sha256_compression_cycle(UINT (*tmp)[NUM_OF_START_WORDS],
							  UINT (*new_data)[MAX_SIZE_OF_WORD]);

// final
void sha256_final(sha256_info *sha, unsigned char* hash);
void append_length_to_padding(sha256_info* sha);
void little_endian_to_big(sha256_info *sha, unsigned char* hash);

#endif