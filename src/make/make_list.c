/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:43:35 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/13 23:38:46 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

void	make_list(t_vars *vars, t_lst *a, t_lst *b)
{
	int		i;
	t_lst	*temp;

	a = lstnew(0);
	b = lstnew(0);
	if (a == NULL || b == NULL)
	{
		print_error("malloc failed");
		// system("leaks -q push_swap");
		exit (1);
	}
	i = 0;
	while (i < vars->size)
	{
		temp = lstnew(vars->elements[i]);
		// if (i == 1)
			// temp = NULL;
		if (temp == NULL)
		{
			lstclear(&a, NULL);
			free(vars->elements);
			print_error("malloc failed");
			system("leaks -q push_swap");
			exit (1);
		}
		lstadd_back(&a, temp);
		i++;
	}
	(*a).prev = lstlast(a);
	lstlast(a)->next = a;
	(*b).prev = lstlast(b);
	lstlast(b)->next = b;
	show_list_r(a->prev, a);
}
