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

int	main()
{
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
