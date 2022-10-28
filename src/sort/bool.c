/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:45:19 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 13:52:16 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

bool	is_correspond(int num, int quaternary, int index)
{
	if (quaternary == 0)
		if (!(num & 1 << (index + 1)) && !(num & 1 << index))
			return (true);
	if (quaternary == 1)
		if (!(num & 1 << (index + 1)) && num & 1 << index)
			return (true);
	if (quaternary == 10)
		if (num & 1 << (index + 1) && !(num & 1 << index))
			return (true);
	if (quaternary == 11)
		if (num & 1 << (index + 1) && num & 1 << index)
			return (true);
	return (false);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", is_correspond(1, 0, 0));
// 	printf("%d\n", is_correspond(1, 1, 0));
// 	printf("%d\n", is_correspond(1, 10, 0));
// 	printf("%d\n", is_correspond(1, 11, 0));
// 	printf("%d\n", is_correspond(0, 0, 0));
// 	printf("%d\n", is_correspond(0, 1, 0));
// 	printf("%d\n", is_correspond(0, 10, 0));
// 	printf("%d\n", is_correspond(0, 11, 0));
// 	printf("%d\n", is_correspond(2, 0, 0));
// 	printf("%d\n", is_correspond(2, 1, 0));
// 	printf("%d\n", is_correspond(2, 10, 0));
// 	printf("%d\n", is_correspond(2, 11, 0));
// 	printf("%d\n", is_correspond(3, 0, 0));
// 	printf("%d\n", is_correspond(3, 1, 0));
// 	printf("%d\n", is_correspond(3, 10, 0));
// 	printf("%d\n", is_correspond(3, 11, 0));
// }