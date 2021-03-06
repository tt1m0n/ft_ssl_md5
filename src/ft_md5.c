# include "../libft/libft.h"
#include "ft_md5.h"

void md5_round1(t_uint (*tmp)[4], t_md5_info *ctx, const t_uchar* ptr)
{
    STEP(F, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], SET(0), 0xd76aa478, 7)
    STEP(F, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], SET(1), 0xe8c7b756, 12)
    STEP(F, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], SET(2), 0x242070db, 17)
    STEP(F, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], SET(3), 0xc1bdceee, 22)
    STEP(F, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], SET(4), 0xf57c0faf, 7)
    STEP(F, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], SET(5), 0x4787c62a, 12)
    STEP(F, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], SET(6), 0xa8304613, 17)
    STEP(F, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], SET(7), 0xfd469501, 22)
    STEP(F, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], SET(8), 0x698098d8, 7)
    STEP(F, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], SET(9), 0x8b44f7af, 12)
    STEP(F, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], SET(10), 0xffff5bb1, 17)
    STEP(F, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], SET(11), 0x895cd7be, 22)
    STEP(F, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], SET(12), 0x6b901122, 7)
    STEP(F, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], SET(13), 0xfd987193, 12)
    STEP(F, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], SET(14), 0xa679438e, 17)
    STEP(F, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], SET(15), 0x49b40821, 22)
}

void md5_round2(t_uint (*tmp)[4], t_md5_info *ctx)
{
    STEP(G, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(1), 0xf61e2562, 5)
    STEP(G, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(6), 0xc040b340, 9)
    STEP(G, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(11), 0x265e5a51, 14)
    STEP(G, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(0), 0xe9b6c7aa, 20)
    STEP(G, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(5), 0xd62f105d, 5)
    STEP(G, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(10), 0x02441453, 9)
    STEP(G, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(15), 0xd8a1e681, 14)
    STEP(G, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(4), 0xe7d3fbc8, 20)
    STEP(G, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(9), 0x21e1cde6, 5)
    STEP(G, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(14), 0xc33707d6, 9)
    STEP(G, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(3), 0xf4d50d87, 14)
    STEP(G, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(8), 0x455a14ed, 20)
    STEP(G, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(13), 0xa9e3e905, 5)
    STEP(G, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(2), 0xfcefa3f8, 9)
    STEP(G, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(7), 0x676f02d9, 14)
    STEP(G, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(12), 0x8d2a4c8a, 20)
}

void md5_round3(t_uint (*tmp)[4], t_md5_info *ctx)
{
    STEP(H, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(5), 0xfffa3942, 4)
    STEP(H2, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(8), 0x8771f681, 11)
    STEP(H, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(11), 0x6d9d6122, 16)
    STEP(H2, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(14), 0xfde5380c, 23)
    STEP(H, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(1), 0xa4beea44, 4)
    STEP(H2, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(4), 0x4bdecfa9, 11)
    STEP(H, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(7), 0xf6bb4b60, 16)
    STEP(H2, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(10), 0xbebfbc70, 23)
    STEP(H, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(13), 0x289b7ec6, 4)
    STEP(H2, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(0), 0xeaa127fa, 11)
    STEP(H, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(3), 0xd4ef3085, 16)
    STEP(H2, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(6), 0x04881d05, 23)
    STEP(H, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(9), 0xd9d4d039, 4)
    STEP(H2, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(12), 0xe6db99e5, 11)
    STEP(H, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(15), 0x1fa27cf8, 16)
    STEP(H2, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(2), 0xc4ac5665, 23)
}

void md5_round4(t_uint (*tmp)[4], t_md5_info *ctx)
{
    STEP(I, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(0), 0xf4292244, 6)
    STEP(I, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(7), 0x432aff97, 10)
    STEP(I, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(14), 0xab9423a7, 15)
    STEP(I, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(5), 0xfc93a039, 21)
    STEP(I, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(12), 0x655b59c3, 6)
    STEP(I, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(3), 0x8f0ccc92, 10)
    STEP(I, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(10), 0xffeff47d, 15)
    STEP(I, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(1), 0x85845dd1, 21)
    STEP(I, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(8), 0x6fa87e4f, 6)
    STEP(I, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(15), 0xfe2ce6e0, 10)
    STEP(I, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(6), 0xa3014314, 15)
    STEP(I, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(13), 0x4e0811a1, 21)
    STEP(I, (*tmp)[0], (*tmp)[1], (*tmp)[2], (*tmp)[3], GET(4), 0xf7537e82, 6)
    STEP(I, (*tmp)[3], (*tmp)[0], (*tmp)[1], (*tmp)[2], GET(11), 0xbd3af235, 10)
    STEP(I, (*tmp)[2], (*tmp)[3], (*tmp)[0], (*tmp)[1], GET(2), 0x2ad7d2bb, 15)
    STEP(I, (*tmp)[1], (*tmp)[2], (*tmp)[3], (*tmp)[0], GET(9), 0xeb86d391, 21)
}

void md5_body_cycle(t_uint (*tmp)[4], t_md5_info *ctx, const t_uchar* ptr)
{
    t_uint saved_tmp[4];

    saved_tmp[0] = (*tmp)[0];
    saved_tmp[1] = (*tmp)[1];
    saved_tmp[2] = (*tmp)[2];
    saved_tmp[3] = (*tmp)[3];
    md5_round1(tmp, ctx, ptr);
    md5_round2(tmp, ctx);
    md5_round3(tmp, ctx);
    md5_round4(tmp, ctx);
    (*tmp)[0] += saved_tmp[0];
    (*tmp)[1] += saved_tmp[1];
    (*tmp)[2] += saved_tmp[2];
    (*tmp)[3] += saved_tmp[3];
}

static const void *body(t_md5_info *ctx, const void *data, unsigned long size)
{
    const t_uchar *ptr;
    t_uint tmp[4];

    ptr = (const t_uchar*)data;
    tmp[0] = ctx->a;
    tmp[1] = ctx->b;
    tmp[2] = ctx->c;
    tmp[3] = ctx->d;

    while(size)
    {
        md5_body_cycle(&tmp, ctx, ptr);
        ptr += 64;
        size -= 64;
    }
    ctx->a = tmp[0];
    ctx->b = tmp[1];
    ctx->c = tmp[2];
    ctx->d = tmp[3];
    return ptr;
}

void md5_update_words(t_md5_info *md5, const void *data, unsigned long size)
{
    t_uint  saved_lo;
    t_ulong used, available;

    saved_lo = md5->lo;
    if ((md5->lo = (saved_lo + size) & 0x1fffffff) < saved_lo)
        md5->hi++;
    md5->hi += size >> 29;
    used = saved_lo & 0x3f;
    if (used)
    {
        available = 64 - used;
        if (size < available)
        {
            memcpy(&md5->buffer[used], data, size);
            return;
        }
        memcpy(&md5->buffer[used], data, available);
        data = (const t_uchar*)data + available;
        size -= available;
        body(md5, md5->buffer, 64);
    }
    if (size >= 64)
    {
        data = body(md5, data, size & ~(t_ulong)0x3f);
        size &= 0x3f;
    }
    memcpy(md5->buffer, data, size);
}

void md5_final(unsigned char *result, t_md5_info *ctx)
{
    unsigned long used, available;

    used = ctx->lo & 0x3f;
    ctx->buffer[used++] = 0x80;
    available = 64 - used;
    if (available < 8)
    {
        memset(&ctx->buffer[used], 0, available);
        body(ctx, ctx->buffer, 64);
        used = 0;
        available = 64;
    }
    memset(&ctx->buffer[used], 0, available - 8);
    ctx->lo <<= 3;
    OUT(&ctx->buffer[56], ctx->lo)
    OUT(&ctx->buffer[60], ctx->hi)
    body(ctx, ctx->buffer, 64);
    OUT(&result[0], ctx->a)
    OUT(&result[4], ctx->b)
    OUT(&result[8], ctx->c)
    OUT(&result[12], ctx->d)
    memset(ctx, 0, sizeof(*ctx));
}