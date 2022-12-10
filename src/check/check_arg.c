/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:11 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/11 08:58:56 by hyanagim         ###   ########.fr       */
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
	int	ans;
	int	sign;

	if (str == NULL)
		return (false);
	ans = 0;
	sign = -1;
	if (*str == '-' || *str == '+')
		sign = *str++ - 44;
	while (ft_isdigit(*str))
	{
		if (sign * ans < (INT_MIN + (int)(*str - '0')) / 10)
		{
			print_error("some arguments are smaller than an integers");
			return (false);
		}
		if (sign * ans > (INT_MAX - (int)(*str - '0')) / 10)
		{
			print_error("some arguments are bigger than an integers");
			return (false);
		}
		ans = ans * 10 - (int)(*str++ - '0');
	}
	return (true);
}

static void	is_valid_number(char **array, int i)
{
	while (array[i])
	{
		if (is_number(array[i]) == false)
			exit (1);
		if (is_int(array[i]) == false)
			exit (1);
		i++;
	}
}

void	check_arg(int argc, char **argv)
{
	char	**array;

	array = NULL;
	if (argc == 1)
		exit (1);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (array == NULL)
			malloc_error();
		is_valid_number(array, 0);
	}
	else
		is_valid_number(argv, 1);
	if (array != NULL)
		free_array_char(array);
}
