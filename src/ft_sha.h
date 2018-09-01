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

#define ROTATE_RIGHT_32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define ROTATE_RIGHT_64(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
#define SHIFT_RIGHT(x, n) ((x) >> (n))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIGMA0(x, n) (((n) == 0) ? \
	(ROTATE_RIGHT_32(x, 2) ^ ROTATE_RIGHT_32(x, 13) ^ ROTATE_RIGHT_32(x, 22)) \
	: \
	(ROTATE_RIGHT_64(x, 28) ^ ROTATE_RIGHT_64(x, 34) ^ ROTATE_RIGHT_64(x, 39)))

#define SIGMA1(x, n) (((n) == 0) ? \
	 (ROTATE_RIGHT_32(x, 6) ^ ROTATE_RIGHT_32(x, 11) ^ ROTATE_RIGHT_32(x, 25)) \
	: \
	(ROTATE_RIGHT_64(x, 14) ^ ROTATE_RIGHT_64(x, 18) ^ ROTATE_RIGHT_64(x, 41)))

#define DELTA0(x, n) (((n) == 0) ? \
	(ROTATE_RIGHT_32(x, 7) ^ ROTATE_RIGHT_32(x, 18) ^ SHIFT_RIGHT(x, 3)) \
	: \
	(ROTATE_RIGHT_64(x, 1) ^ ROTATE_RIGHT_64(x, 8) ^ SHIFT_RIGHT(x, 7)))

#define DELTA1(x, n) (((n) == 0) ? \
	(ROTATE_RIGHT_32(x, 17) ^ ROTATE_RIGHT_32(x, 19) ^ SHIFT_RIGHT(x, 10)) \
	: \
	(ROTATE_RIGHT_64(x, 19) ^ ROTATE_RIGHT_64(x, 61) ^ SHIFT_RIGHT(x, 6)))

#define ZERO_BIT 			0x00
#define START_PADDING 		0x80
#define NUM_OF_START_WORDS 	8
#define MAX_SIZE_OF_WORD 	64
#define MAX_SIZE_OF_WORD_1 	128
#define SYMBOL_SIZE		    8
#define MAX_SHIFT           24
#define MAX_SHIFT_1         56
#define INT_STEP            4
#define LONG_STEP			8
#define MESSAGE_BYTE_SIZE   56
#define MESSAGE_BYTE_SIZE_1 112

typedef struct
{
	t_uchar	data[MAX_SIZE_OF_WORD];
	t_uint	datalen;
	t_ulong	bitlen;
	t_uint	start_word[NUM_OF_START_WORDS];
} sha_224_256;

typedef struct
{
	t_uchar	data[MAX_SIZE_OF_WORD_1];
	t_uint	datalen;
	t_ulong	bitlen;
	t_ulong	start_word[NUM_OF_START_WORDS];
} sha_384_512;


// init start words
void sha256_init_start_words(t_uint (*info)[NUM_OF_START_WORDS]);
void sha224_init_start_words(t_uint (*info)[NUM_OF_START_WORDS]);
void sha384_init_start_words(t_ulong (*info)[NUM_OF_START_WORDS]);
void sha512_init_start_words(t_ulong (*info)[NUM_OF_START_WORDS]);

// update words
void sha_update_words(sha_224_256 *sha_info, const unsigned char *data, size_t len);
void sha_update_words_1(sha_384_512 *sha_info, const unsigned char *data, size_t len);
void sha_transform_words(sha_224_256 *sha);
void sha_transform_words_1(sha_384_512 *sha);
void sha_data_transformation(sha_224_256 *sha, t_uint (*new_data)[MAX_SIZE_OF_WORD]);
void sha_data_transformation_1(sha_384_512 *sha, t_ulong (*new_data)[80]);
void sha_compression_cycle(t_uint (*tmp)[NUM_OF_START_WORDS],
						   t_uint (*new_data)[MAX_SIZE_OF_WORD]);
void sha_compression_cycle_1(t_ulong (*tmp)[NUM_OF_START_WORDS],
						   t_ulong (*new_data)[80]);

// final
void sha_final(sha_224_256 *sha, unsigned char *hash, t_sha_type type);
void sha_final_1(sha_384_512 *sha, unsigned char *hash, t_sha_type type);

void append_length_to_padding(sha_224_256* sha);
void append_length_to_padding_1(sha_384_512* sha);

void little_endian_to_big(sha_224_256 *sha, unsigned char* hash, t_sha_type);
void little_endian_to_big_1(sha_384_512 *sha, unsigned char* hash, t_sha_type);

#endif