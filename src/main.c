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

int printf_no_flag_error(hash_type hash_type)
{
    ft_printf ("usage: ");
    if(hash_type == md5)
        ft_printf("md5 ");
    if(hash_type == sha256)
        ft_printf("sha256 ");
    ft_printf("[-pqrtx] [-s string] [files ...]\n");
    return (1);
}

int print_error(hash_type hash_type, error_type error_type, char* filename)
{
    if(error_type == no_flag)
        return (printf_no_flag_error(hash_type));
    if(hash_type == md5)
        ft_printf("md5: ");
    if(hash_type == sha256)
        ft_printf("sha256: ");
    if(error_type == no_file)
        ft_printf("%s: No such file or directory\n", filename);
    if(error_type == error_command)
        ft_printf("Message Digest commands:\n"
                  "md5\n"
                  "sha256\n");
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

int read_hash_info(hash_info* hash_info, char* info, int file)
{
    int fd;
    char* need_to_hash;

    fd = 0;
    if (info[0] != 0 && file)
        fd = open(info, O_RDONLY);
    if (fd == - 1)
        return (print_error(hash_info->hash, no_file, info));
    if (file)
        need_to_hash = take_text_from_file(fd);
    else
        need_to_hash = info;
    return (1);
}

int parse_flags(hash_info* hash_info, char*** argv)
{
    if(ft_strcmp(**argv, "-s") == 0)
    {
        if(*(*argv + 1) == NULL)
            read_hash_info(hash_info, STDIN, 1);
        else
        {
            (*argv)++;
            return (read_hash_info(hash_info, **argv, 0));
        }
    }
    else if(ft_strcmp(**argv, "-p") == 0)
        return (read_hash_info(hash_info, STDIN, 1));
    else if (ft_strcmp(**argv, "-q") == 0)
        hash_info->q_flag = 1;
    else if (ft_strcmp(**argv, "-r") == 0)
        hash_info->r_flag = 1;
    else
        return (UNKNOWN_FLAG);
    return (1);
}

int	main(int argc, char** argv)
{
    hash_info hash_info = {};

    argv[argc] = NULL;
    if (argc == 1)
        ft_printf(USAGE_STRING);
    else
    {
        if (!(hash_info.hash = find_hash_type(argv[1])))
            return (print_error(0, error_command, *argv));
        argv = argv + 2;
        if (*argv == NULL)
        {
            return (read_hash_info(&hash_info, STDIN, 1));
        }
        while (*argv && (*argv)[0] == '-')
        {
            if (parse_flags(&hash_info, &argv) == UNKNOWN_FLAG)
                return (print_error(hash_info.hash, no_flag, *argv));
            argv++;
        }
        while (*argv)
        {
            read_hash_info(&hash_info, *argv, 1);
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
