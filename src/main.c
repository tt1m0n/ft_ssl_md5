# include "../libft/libft.h"
#include "ft_ssl_md5.h"
#include <stdio.h>

void init_start_words(int (*info)[8])
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

void transform_sha256_words(sha256_info *ctx)
{
	unsigned char* data = ctx->data;
	int a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

	for (i = 0, j = 0; i < 16; ++i, j += 4)
		m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
	for ( ; i < 64; ++i)
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];

	a = ctx->start_word[0];
	b = ctx->start_word[1];
	c = ctx->start_word[2];
	d = ctx->start_word[3];
	e = ctx->start_word[4];
	f = ctx->start_word[5];
	g = ctx->start_word[6];
	h = ctx->start_word[7];

	for (i = 0; i < 64; ++i) {
		t1 = h + EP1(e) + CH(e,f,g) + sha256_word[i] + m[i];
		t2 = EP0(a) + MAJ(a,b,c);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}

	ctx->start_word[0] += a;
	ctx->start_word[1] += b;
	ctx->start_word[2] += c;
	ctx->start_word[3] += d;
	ctx->start_word[4] += e;
	ctx->start_word[5] += f;
	ctx->start_word[6] += g;
	ctx->start_word[7] += h;
}

void update_sha256_words(sha256_info* sha_info, const unsigned char* data, size_t len)
{
	int i;

	i = 0;
	while((size_t)i < len)
	{
		sha_info->data[sha_info->datalen] = data[i];
		sha_info->datalen++;
		if(sha_info->datalen == 64)
		{
			transform_sha256_words(sha_info);
			sha_info->bitlen += 512;
			sha_info->datalen = 0;
		}
		i++;
	}
}

void sha256_final(sha256_info *ctx, unsigned char* hash)
{
	int i;

	i = ctx->datalen;

	// Pad whatever data is left in the buffer.
	if (ctx->datalen < 56) {
		ctx->data[i++] = 0x80;
		while (i < 56)
			ctx->data[i++] = 0x00;
	}
	else {
		ctx->data[i++] = 0x80;
		while (i < 64)
			ctx->data[i++] = 0x00;
		transform_sha256_words(ctx);
		memset(ctx->data, 0, 56);
	}

	// Append to the padding the total message's length in bits and transform.
	ctx->bitlen += ctx->datalen * 8;
	ctx->data[63] = (unsigned char)ctx->bitlen;
	ctx->data[62] = (unsigned char)(ctx->bitlen >> 8);
	ctx->data[61] = (unsigned char)(ctx->bitlen >> 16);
	ctx->data[60] = (unsigned char)(ctx->bitlen >> 24);
	ctx->data[59] = (unsigned char)(ctx->bitlen >> 32);
	ctx->data[58] = (unsigned char)(ctx->bitlen >> 40);
	ctx->data[57] = (unsigned char)(ctx->bitlen >> 48);
	ctx->data[56] = (unsigned char)(ctx->bitlen >> 56);
	transform_sha256_words(ctx);

	// Since this implementation uses little endian byte ordering and SHA uses big endian,
	// reverse all the bytes when copying the final state to the output hash.
	for (i = 0; i < 4; ++i) {
		hash[i]      = (ctx->start_word[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4]  = (ctx->start_word[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8]  = (ctx->start_word[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (ctx->start_word[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (ctx->start_word[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (ctx->start_word[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (ctx->start_word[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (ctx->start_word[7] >> (24 - i * 8)) & 0x000000ff;
	}
}


int	main(int argc, char** argv)
{
	if (argc == 2) {
		unsigned char buf[32];
		sha256_info sha = {0};

		init_start_words(&sha.start_word);
		update_sha256_words(&sha, (unsigned char *) argv[1], ft_strlen(argv[1]));
		sha256_final(&sha, buf);

		for (int i = 0; i < 32; i++)
		{
			printf("%2x ", buf[i]);
		}
	}

	return (0);
}
