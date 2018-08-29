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

void sha256(char* need_hash, int flags, char* filename)
{
    if (need_hash || flags || filename)
        ;
}

void md5(char* need_hash, int flags, char* filename)
{
    unsigned char buf[16];
    MD5_CTX md5 = {};
    int i;

    i = START_VALUE;
    MD5_Init(&md5);
    MD5_Update(&md5,(void*)need_hash, ft_strlen(need_hash));
    MD5_Final(buf, &md5);

    if(flags == 0 && filename[0] != 0)
        ft_printf("MD5 (%s) = ", filename);
    if(flags == S)
        ft_printf("MD5 (\"%s\") = ", need_hash);
    while(i < 16) {
        ft_printf("%02x", buf[i++]);
    }
    ft_printf("\n");
    if(flags >> 2)
        flags &= (Q | R);
}

hash_ptr find_hash_type(char* hash)
{
    if(ft_strcmp("md5", hash) == 0)
        return md5;
    if(ft_strcmp("sha256", hash) == 0)
        return sha256;
    return (0);
}

int printf_no_flag_error(hash_ptr hash_type)
{
    ft_printf ("usage: ");
    if(hash_type == md5)
        ft_printf("md5 ");
    if(hash_type == sha256)
        ft_printf("sha256 ");
    ft_printf("[-pqrtx] [-s string] [files ...]\n");
    return (1);
}

int print_error(hash_ptr hash_type, error_type error_type, char* filename)
{
    if(error_type == no_flag)
        return (printf_no_flag_error(hash_type));
    if(hash_type == md5)
        ft_printf("md5: ");
    if(hash_type == sha256)
        ft_printf("sha256: ");
    if(error_type == no_file)
        ft_printf("%s: No such file or directory\n", filename);
    if(error_type == try_open_dir)
        ft_printf("%s: Is a directory\n", filename);
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
        need_to_hash = ft_strjoin(need_to_hash, tmp_buffer);
        free(ptr_to_free);
        ft_memset(tmp_buffer, 0, BUFFER_SIZE);
    }
    free(tmp_buffer);
    if (fd)
        close(fd);
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
        return (print_error(hash_info->hash_ptr, no_file, info));
    if (read(fd, NULL, 0) == -1)
        return (print_error(hash_info->hash_ptr, try_open_dir, info));
    if (file)
        need_to_hash = take_text_from_file(fd);
    else
        need_to_hash = info;
    hash_info->hash_ptr(need_to_hash, hash_info->flags, info);
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
            hash_info->flags |= S;
            return (read_hash_info(hash_info, **argv, 0));
        }
    }
    else if(ft_strcmp(**argv, "-p") == 0)
        return (read_hash_info(hash_info, STDIN, 1));
    else if (ft_strcmp(**argv, "-q") == 0)
    {
        if(*(*argv + 1) == NULL)
            read_hash_info(hash_info, STDIN, 1);
        hash_info->flags |= Q;
    }
    else if (ft_strcmp(**argv, "-r") == 0)
    {
        if (*(*argv + 1) == NULL)
            read_hash_info(hash_info, STDIN, 1);
        hash_info->flags |= R;
    }
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
        if (!(hash_info.hash_ptr = find_hash_type(argv[1])))
            return (print_error(0, error_command, *argv));
        argv = argv + 2;
        if (*argv == NULL)
        {
            return (read_hash_info(&hash_info, STDIN, 1));
        }
        while (*argv && (*argv)[0] == '-')
        {
            if (parse_flags(&hash_info, &argv) == UNKNOWN_FLAG)
                return (print_error(hash_info.hash_ptr, no_flag, *argv));
            argv++;
        }
        while (*argv)
        {
            read_hash_info(&hash_info, *argv, 1);
            argv++;
        }
    }


//    unsigned char abc[] = {"abc\n"};
//    unsigned char buf[32];
//    unsigned char buf1[16];
//    sha256_info sha = {};
//    MD5_CTX md5 = {};
//
//    MD5_Init(&md5);
//    MD5_Update(&md5,(void*)abc, sizeof(abc) - 1);
//    MD5_Final(buf1, &md5);
//
//    sha256_init_start_words(&sha.start_word);
//    sha256_update_words(&sha, abc, sizeof(abc) - 1);
//    sha256_final(&sha, buf);
//
//    for (int i = START_VALUE; i < 32; i++)
//    {
//        ft_printf("%2x ", buf[i]);
//    }
//    ft_printf ("\n");
//
//    for (int i = START_VALUE; i < 16; i++)
//    {
//        ft_printf("%2x", buf1[i]);
//    }

 //   ft_printf ("\n");
    return (0);
}

