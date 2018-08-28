/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:59:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/08/25 15:59:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_global.h"

hash_type find_hash_type(char* hash)
{
    if(ft_strcmp("md5", hash) == 0)
        return md5;
    if(ft_strcmp("sha256", hash) == 0)
        return sha256;
    return (0);
}

int print_error_command(void)
{
    ft_printf("Message Digest commands:\n"
              "md5\n"
              "sha256\n");
    return (1);
}

int print_error_no_file(hash_type type, char* filename)
{
    if(type == md5)
        ft_printf("md5: ");
    if(type == sha256)
        ft_printf("sha256: ");
    ft_printf("%s: No such file or directory", filename);
    return (1);
}

char* take_text_from_file(int fd)
{
    char* need_to_hash;
    char* tmp_buffer;
    char* ptr_to_free;

    need_to_hash = ft_memalloc(1);
    tmp_buffer = ft_memalloc(BUFFER_SIZE);
    while (read(fd, tmp_buffer, BUFFER_SIZE - 1))
    {
        ptr_to_free = need_to_hash;
        need_to_hash = ft_strjoin(tmp_buffer, need_to_hash);
        free(ptr_to_free);
        ft_memset(tmp_buffer, 0, BUFFER_SIZE);
    }
    free(tmp_buffer);
    return (need_to_hash);
}

int read_output_from_file(hash_type hash, char* filename)
{
    int fd;
    char* need_to_hash;

    fd = 0;
    if (filename[0] != 0)
        fd = open(filename, O_RDONLY);
    if (fd == - 1)
        return (print_error_no_file(hash, filename));
    need_to_hash = take_text_from_file(fd);
    ft_printf("%s\n", need_to_hash);
    return (1);
}

int	main(int argc, char** argv)
{
    int hash_function;
    argv[argc] = NULL;
    if (argc == 1)
        ft_printf(USAGE_STRING);
    else
    {
        if (!(hash_function = find_hash_type(argv[1])))
            return (print_error_command());
        argv = argv + 2;
        if (*argv == NULL)
        {
            return (read_output_from_file(hash_function, STDIN));
        }
        while (*argv)
        {
            argv++;
        }

    }

    unsigned char abc[] = {"abc\n"};
    unsigned char buf[32];
    unsigned char buf1[16];
    sha256_info sha = {};
    MD5_CTX md5 = {};

    MD5_Init(&md5);
    MD5_Update(&md5,(void*)abc, sizeof(abc) - 1);
    MD5_Final(buf1, &md5);

    sha256_init_start_words(&sha.start_word);
    sha256_update_words(&sha, abc, sizeof(abc) - 1);
    sha256_final(&sha, buf);

    for (int i = START_VALUE; i < 32; i++)
    {
        ft_printf("%2x ", buf[i]);
    }
    ft_printf ("\n");

    for (int i = START_VALUE; i < 16; i++)
    {
        ft_printf("%2x", buf1[i]);
    }

    ft_printf ("\n");
    return (0);
}
