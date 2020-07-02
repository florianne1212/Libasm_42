/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 15:09:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libasm.h"

void		test_read(void)
{
	int		fd;
	int		ret;
	char	s1[800];

	fd = open("./test_libasm/text.txt", O_RDONLY);
	printf("\n \e[1;35m TEST READ \e[0m");
	ret = ft_read(fd, s1, 31);
	s1[ret] = '\0';
	printf("\nreal fonction read return  : %d", ret);
	printf(" and read : %s", s1);
	close(fd);
	fd = open("./test_libasm/text.txt", O_RDONLY);
	clear_s1(s1);
	ret = read(fd, s1, 31);
	s1[ret] = '\0';
	printf("\nmy fonction ft_read return : %d", ret);
	printf(" and read : %s", s1);
	close(fd);
}

void		test_error_read_2(void)
{
	char	*error;
	int		ret1;
	int		fd;
	char	s1[800];

	errno = 0;
	ret1 = 0;
	fd = open("coucou", O_RDONLY);
	error = NULL;
	clear_s1(s1);
	printf("\n 2 - read from not existent file descriptor\nreal : ");
	fflush(stdout);
	ret1 = read(fd, s1, 15);
	error = strerror(errno);
	printf("\nerrno %i \nerror %s", errno, error);
	clear_s1(s1);
	close(fd);
	fd = open("coucou", O_RDONLY);
	printf("\nmine :");
	ret1 = ft_read(fd, s1, 15);
	error = strerror(errno);
	printf("\nerrno %i \nerror %s", errno, error);
	close(fd);
}

void		test_error_read(void)
{
	char	*error;
	int		ret1;
	int		fd;
	char	s1[800];

	ret1 = 0;
	errno = 0;
	printf("\n \e[1;35m TEST ERROR READ \e[0m");
	fflush(stdout);
	fd = open("./test_libasm/text.txt", O_RDONLY);
	error = NULL;
	clear_s1(s1);
	printf("\n 1 - read with bad file negative count \nreal : ");
	fflush(stdout);
	ret1 = read(fd, s1, -15);
	error = strerror(errno);
	printf("\nerrno %i \nerror %s", errno, error);
	clear_s1(s1);
	close(fd);
	fd = open("./test_libasm/text.txt", O_RDONLY);
	printf("\nmine :");
	ret1 = ft_read(fd, s1, -15);
	error = strerror(errno);
	printf("\nerrno %i \nerror %s", errno, error);
	close(fd);
}

void		test_write(void)
{
	int		ret1;
	int		ret2;

	printf("\n \e[1;35m TEST WRITE \e[0m");
	printf("\n 1- write hello world count = size \nreal : ");
	fflush(stdout);
	ret1 = write(1, "hello world", 11);
	write(1, "\nmine : ", 8);
	ret2 = ft_write(1, "hello world", 11);
	test_int(ret1, ret2);
	printf("\n 2- write hello world count = 6 instead of 11 \nreal : ");
	fflush(stdout);
	ret1 = write(1, "hello world", 6);
	printf("\nmine : ");
	fflush(stdout);
	ret2 = ft_write(1, "hello world", 6);
	test_int(ret1, ret2);
	printf("\n 3- write hello world count = 0 \nreal : ");
	fflush(stdout);
	ret1 = write(1, "hello world", 0);
	printf("\nmine : ");
	fflush(stdout);
	ret2 = ft_write(1, "hello world", 0);
	test_int(ret1, ret2);
}

int			main(void)
{
	test_strlen();
	test_strdup();
	test_strcmp();
	test_strcpy();
	test_write();
	test_error_write();
	test_read();
	test_error_read();
	test_error_read_2();
	printf("\n \e[1;35m END\e[0m");
	return (0);
}
