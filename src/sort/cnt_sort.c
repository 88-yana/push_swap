/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:25:53 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:26:36 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

int	power(int x, int exp)
{
	while (--exp)
		x *= 2;
	return (x);
}

int	cnt_sort(int size)
{
	int	exp;

	exp = 0;
	while (1)
	{
		exp++;
		if (power(2, exp) < size && size <= power(2, exp + 1))
			break ;
	}
	return (exp);
}
