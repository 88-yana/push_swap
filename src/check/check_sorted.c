/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/13 21:54:37 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/check.h"

void	check_sorted(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->size - 1)
	{
		if (vars->elements[i] > vars->elements[i + 1])
			return ;
		i++;
	}
	// system("leaks -q push_swap");
	exit (0);
}
