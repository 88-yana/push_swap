/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:59:56 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/20 21:13:49 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shrink.h"

static void	swap(long long pos, long long next, t_vars *vars)
{
	long long	temp;

	temp = vars->twin[pos];
	vars->twin[pos] = vars->twin[next];
	vars->twin[next] = temp;
}

static void	bubble_sort(t_vars *vars)
{
	long long	i;
	long long	j;

	i = 0;
	while (i < vars->size)
	{
		j = 0;
		while (j < vars->size - 1 - i)
		{
			if (vars->twin[j] > vars->twin[j + 1])
				swap(j, j + 1, vars);
			j++;
		}
		i++;
	}
}

static void	overwrite_elements(t_vars *vars, long long an_element, long long pos)
{
	long long	index;

	index = 0;
	while (index < vars->size)
	{
		if (vars->twin[index] == an_element)
			vars->elements[pos] = index;
		index++;
	}
}

static void	update_elements(t_vars *vars)
{
	long long	pos;

	pos = 0;
	while (pos < vars->size)
	{
		overwrite_elements(vars, vars->elements[pos], pos);
		pos++;
	}
}

void	shrink_array(t_vars *vars)
{
	bubble_sort(vars);
	update_elements(vars);
	free(vars->twin);
	// long long i = 0;
	// while (i < vars->size)
	// {
	// 	ft_printf("%d ", vars->twin[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < vars->size)
	// {
	// 	ft_printf("%d ", vars->elements[i]);
	// 	i++;
	// }
}
