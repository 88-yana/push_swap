/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/11 08:45:03 by hyanagim         ###   ########.fr       */
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
	exit (0);
}

bool	is_sorted(t_lst *lst)
{
	t_lst	*nil;

	nil = lst->prev;
	lst = lst->next;
	while (lst != nil)
	{
		if (lst->num > lst->next->num)
			return (false);
		lst = lst->next;
	}
	return (true);
}
