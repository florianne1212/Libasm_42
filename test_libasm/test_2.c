/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 15:09:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libasm.h"

void		test_strlen(void)
{
	printf("\e[1;35m TEST STRLEN \e[0m");
	printf("\n 1- strlen of hello_world");
	test_int(strlen("hello_world"), ft_strlen("hello_world"));
	printf("\n 2- strlen of empty string");
	test_int(strlen(""), ft_strlen(""));
	printf("\n 3- strlen of alphabet");
	test_int(strlen("abcdefghijklmnopqrstuvwxyz"),
	ft_strlen("abcdefghijklmnopqrstuvwxyz"));
}

void		test_strdup(void)
{
	printf("\n \e[1;35m TEST STRDUP \e[0m");
	printf("\n 1- strdup of hello_world");
	cmp_char_free(strdup("hello_world"), ft_strdup("hello_world"));
	printf("\n 2- strdup of alphabet");
	cmp_char_free(strdup("abcdefghijklmnopqrstuvwxyz"),
	ft_strdup("abcdefghijklmnopqrstuvwxyz"));
	printf("\n 3- strdup of empty string");
	cmp_char_free(strdup(""), ft_strdup(""));
}

void		test_strcmp(void)
{
	printf("\n \e[1;35m TEST STRCMP \e[0m");
	printf("\n 1- str1 = hello str2 = hello");
	test_sign(strcmp("hello", "hello"), ft_strcmp("hello", "hello"));
	printf("\n 2- str1 = hello str2 = helli");
	test_sign(strcmp("hello", "helli"), ft_strcmp("hello", "helli"));
	printf("\n 3- str1 = hello str2 = he");
	test_sign(strcmp("hello", "he"), ft_strcmp("hello", "he"));
	printf("\n 4- str1 = he str2 = hello");
	test_sign(strcmp("he", "hello"), ft_strcmp("he", "hello"));
	printf("\n 5- both are empty string");
	test_sign(strcmp("", ""), ft_strcmp("", ""));
	printf("\n 6- str1 is empty str2 = hello");
	test_sign(strcmp("", "hello"), ft_strcmp("", "hello"));
}

void		test_strcpy(void)
{
	char	src1[100];
	char	src2[100];

	printf("\n \e[1;35m TEST STRCPY \e[0m");
	printf("\n 1- strcpy of hello_world");
	cmp_char(strcpy(src1, "hello_world"), ft_strcpy(src2, "hello_world"));
	printf("\n 2- strcpy of alphabet");
	cmp_char(strcpy(src1, "abcdefghijklmnopqrstuvwxyz"),
	ft_strcpy(src2, "abcdefghijklmnopqrstuvwxyz"));
	printf("\n 3- strcpy of empty string");
	cmp_char(strcpy(src1, ""), ft_strcpy(src2, ""));
}

void		test_error_write(void)
{
	char	*error;
	int		ret1;

	ret1 = 0;
	errno = 0;
	error = NULL;
	printf("\n \e[1;35m TEST ERROR WRITE \e[0m");
	printf("\nwrite hello world with bad file descriptor \nreal : ");
	fflush(stdout);
	ret1 = write(31, "hello world", 6);
	printf("\nerrno %i", errno);
	error = strerror(errno);
	printf("\nerror %s", error);
	printf("\nmine :");
	ret1 = ft_write(31, "hello world", 6);
	printf("\nerrno %i", errno);
	error = strerror(errno);
	printf("\nerror %s", error);
}
