/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 13:01:36 by hyanagim         ###   ########.fr       */
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

// #include "../../include/main.h"
// #include <stdio.h>

// static void	make_ring(t_lst *lst)
// {
// 	(*lst).prev = lstlast(lst);
// 	lstlast(lst)->next = lst;
// }

// int	main(void)
// {
// 	t_lst	*lst;
// 	t_lst	*temp;
// 	int		i;

// 	lst = lstnew(0);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		// if (i == 0)
// 		// 	temp = lstnew(1);
// 		// if (i == 1)
// 		// 	temp = lstnew(2);
// 		// if (i == 2)
// 		// 	temp = lstnew(3);
// 		// if (i == 3)
// 		// 	temp = lstnew(5);
// 		// if (i == 4)
// 		// 	temp = lstnew(4);
// 		if (i == 0)
// 			temp = lstnew(0);
// 		if (i == 1)
// 			temp = lstnew(5);
// 		if (i == 2)
// 			temp = lstnew(3);
// 		if (i == 3)
// 			temp = lstnew(4);
// 		if (i == 4)
// 			temp = lstnew(2);
// 		lstadd_back(&lst, temp);
// 		i++;
// 	}
// 	make_ring(lst);
// 	printf("%d\n", is_sorted(lst));
// 	return (0);
// }
