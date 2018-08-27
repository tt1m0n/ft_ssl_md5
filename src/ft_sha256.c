#include "ft_sha256.h"

void sha256_init_start_words(UINT (*info)[NUM_OF_START_WORDS])
{
	(*info)[0] = 0x6a09e667;
	(*info)[1] = 0xbb67ae85;
	(*info)[2] = 0x3c6ef372;
	(*info)[3] = 0xa54ff53a;
	(*info)[4] = 0x510e527f;
	(*info)[5] = 0x9b05688c;
	(*info)[6] = 0x1f83d9ab;
	(*info)[7] = 0x5be0cd19;
}

void sha256_data_transformation(sha256_info *sha, UINT (*new_data)[MAX_SIZE_OF_WORD])
{
	UCHAR* data;
	UINT i;
	UINT j;

	data = sha->data;
	i = START_VALUE;
	j = START_VALUE;
	while(i < 16)
	{
		(*new_data)[i] = (data[j] << SYMBOL_SIZE * 3) | \
						 (data[j + 1] << SYMBOL_SIZE * 2) | \
						 (data[j + 2] << SYMBOL_SIZE) | \
						 (data[j + 3]);
		i++;
		j += 4;
	}
	while (i < MAX_SIZE_OF_WORD)
	{
		(*new_data)[i] = SIG1((*new_data)[i - 2]) + \
		(*new_data)[i - 7] + SIG0((*new_data)[i - 15]) + \
		(*new_data)[i - 16];
		i++;
	}
}

void sha256_compression_cycle(UINT (*tmp)[NUM_OF_START_WORDS],
        UINT (*new_data)[MAX_SIZE_OF_WORD])
{
    UINT i;
    UINT helpers1;
    UINT helpers2;

    i = START_VALUE;
    while (i < MAX_SIZE_OF_WORD)
    {
        helpers1 = (*tmp)[7] + EP1((*tmp)[4]) + \
                CH((*tmp)[4], (*tmp)[5], (*tmp)[6]) + \
                sha256_word[i] + (*new_data)[i];
        helpers2 = EP0((*tmp)[0]) + MAJ((*tmp)[0], (*tmp)[1], (*tmp)[2]);
        (*tmp)[7] = (*tmp)[6];
        (*tmp)[6] = (*tmp)[5];
        (*tmp)[5] = (*tmp)[4];
        (*tmp)[4] = (*tmp)[3] + helpers1;
        (*tmp)[3] = (*tmp)[2];
        (*tmp)[2] = (*tmp)[1];
        (*tmp)[1] = (*tmp)[0];
        (*tmp)[0] = helpers1 + helpers2;
        i++;
    }
}

void sha256_transform_words(sha256_info* sha)
{
    UINT i;
	UINT tmp[NUM_OF_START_WORDS];
	UINT new_data[MAX_SIZE_OF_WORD];

	sha256_data_transformation(sha, &new_data);

    i = START_VALUE;
	while(i < NUM_OF_START_WORDS)
	{
		tmp[i] = sha->start_word[i];
		i++;
	}

	sha256_compression_cycle(&tmp, &new_data);

	i = START_VALUE;
	while (i < NUM_OF_START_WORDS)
	{
		sha->start_word[i] += tmp[i];
		i++;
	}
}

void sha256_update_words(sha256_info* sha_info, const unsigned char* data, size_t len)
{
	UINT i;

	i = START_VALUE;
	while((size_t)i < len)
	{
		sha_info->data[sha_info->datalen] = data[i];
		sha_info->datalen++;
		if(sha_info->datalen == MAX_SIZE_OF_WORD)
		{
			sha256_transform_words(sha_info);
			sha_info->bitlen += MAX_SIZE_OF_WORD * SYMBOL_SIZE;
			sha_info->datalen = START_VALUE;
		}
		i++;
	}
}

void sha256_final(sha256_info *sha, unsigned char* hash)
{
	UINT i;

	i = sha->datalen;

	// Pad whatever data is left in the buffer.
	if (sha->datalen < MESSAGE_BYTE_SIZE)
	{
		sha->data[i++] = START_PADDING;
		while (i < MESSAGE_BYTE_SIZE)
			sha->data[i++] = ZERO_BIT;
	}
	else
	{
		sha->data[i++] = START_PADDING;
		while (i < MAX_SIZE_OF_WORD)
			sha->data[i++] = ZERO_BIT;
		sha256_transform_words(sha);
		ft_memset(sha->data, ZERO_BIT, MESSAGE_BYTE_SIZE);
	}

	// Append to the padding the total message's length in bits and transform.
	sha->bitlen += sha->datalen * SYMBOL_SIZE;
	sha->data[63] = (UCHAR)sha->bitlen;
	sha->data[62] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 1);
	sha->data[61] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 2);
	sha->data[60] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 3);
	sha->data[59] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 4);
	sha->data[58] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 5);
	sha->data[57] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 6);
	sha->data[56] = (UCHAR)(sha->bitlen >> SYMBOL_SIZE * 7);
	sha256_transform_words(sha);

	// Since this implementation uses little endian byte ordering and SHA uses big endian,
	// reverse all the bytes when copying the final state to the output hash.
	for (i = START_VALUE; i < 4; ++i)
	{
		hash[i] = (UCHAR)(sha->start_word[0] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 1] = (UCHAR)(sha->start_word[1] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 2] = (UCHAR)(sha->start_word[2] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 3] = (UCHAR)(sha->start_word[3] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 4] = (UCHAR)(sha->start_word[4] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 5] = (UCHAR)(sha->start_word[5] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 6] = (UCHAR)(sha->start_word[6] >> (MAX_SHIFT - i * SYMBOL_SIZE));
		hash[i + INT_STEP * 7] = (UCHAR)(sha->start_word[7] >> (MAX_SHIFT - i * SYMBOL_SIZE));
	}
}
