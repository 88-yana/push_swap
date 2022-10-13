/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:21:42 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/13 21:55:05 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/check.h"

static bool	is_match(t_vars *vars, int an_element, int i)
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
	int	i;

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
