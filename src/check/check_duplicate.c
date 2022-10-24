/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:21:42 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/20 21:11:59 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/check.h"

static bool	is_match(t_vars *vars, long long an_element, long long i)
{
	i++;
	while (i < vars->size)
	{
		if (vars->elements[i] == an_element)
			return (true);
		i++;
	}
	return (false);
}

void	check_duplicate(t_vars *vars)
{
	long long	i;

	i = 0;
	while (i < vars->size)
	{
		if (is_match(vars, vars->elements[i], i))
		{
			print_error("some arguments are duplicated");
			// system("leaks -q push_swap");
			exit (1);
		}
		i++;
	}
}
