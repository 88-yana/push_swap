/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:11 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/13 18:14:50 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/check.h"

static bool	is_number(char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
		{
			print_error("some arguments aren't integers");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_int(char *str)
{
	long long	ans;
	int			sign;

	if (str == NULL)
		return (false);
	ans = 0;
	sign = -1;
	if (*str == '-' || *str == '+')
		sign = *str++ - 44;
	while (ft_isdigit(*str))
	{
		if (sign * ans < (INT_MIN + (long long)(*str - '0')) / 10)
		{
			print_error("some arguments are smaller than an integers");
			return (false);
		}
		if (sign * ans > (INT_MAX - (long long)(*str - '0')) / 10)
		{
			print_error("some arguments are bigger than an integers");
			return (false);
		}
		ans = ans * 10 - (long long)(*str++ - '0');
	}
	return (true);
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit (1);
	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == false)
			exit (1);
		if (is_int(argv[i]) == false)
			exit (1);
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned long	i;
// 	char	yes[6][20] = {"123", "0", "2147483647", "-2147483648", "001", "+111"};
// 	char	no[10][20] = {"123a", "2147483648",
// 		"-2147483649", "akf", "11a11", "214748364719", "++123", "--123", "+-1", "-+1"};

// 	i = 0;
// 	while (i < sizeof(yes) / sizeof(yes[0]))
// 	{
// 		printf("[%s] is %s\n", yes[i], is_number(yes[i]) ? "num" : "no");
// 		printf("[%s] is %s\n", yes[i], is_int(yes[i]) ? "int" : "no");
// 		if (is_number(yes[i]) == true && is_int(yes[i]) == true)
// 			printf("%s\n", "yes!");
// 		else
// 			printf("%s\n", "no!");
// 		i++;
// 	}
// 	i = 0;
// 	while (i < sizeof(no) / sizeof(no[0]))
// 	{
// 		printf("[%s] is %s\n", no[i], is_number(no[i]) ? "num" : "no");
// 		printf("[%s] is %s\n", no[i], is_int(no[i]) ? "int" : "no");
// 		if (is_number(no[i])  == true && is_int(no[i]) == true )
// 			printf("%s\n", "yes!");
// 		else
// 			printf("%s\n", "no!");
// 		i++;
// 	}

// 	return (0);
// }
