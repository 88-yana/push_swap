/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:30:08 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 11:08:55 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

void	perform_s(t_lst *nil)
{
	t_lst	*temp;

	if (nil->next == nil->prev)
		return ;
	nil->next->next->next->prev = nil->next;
	nil->next->next->prev = nil;
	temp = nil->next->next->next;
	nil->next->next->next = nil->next;
	nil->next->prev = nil->next->next;
	nil->next->next = temp;
	nil->next = nil->next->prev;
}

void	perform_p(t_lst *a, t_lst *b)
{
	t_lst	*temp;

	if (lstlen(a) == 0)
		return ;
	temp = a->next;
	a->next->next->prev = a;
	a->next = a->next->next;
	temp->next = b->next;
	temp->prev = b;
	b->next->prev = temp;
	b->next = temp;
}

// void	perform_p(t_lst *a, t_lst *b)
// {
// 	t_lst	*temp;

// 	if (a->next == a->prev) //検討せずに消した。全部移すため。
// 		return ;
// 	temp = a->next;
// 	a->next->next->prev = a;
// 	a->next = a->next->next;
// 	temp->next = b->next;
// 	temp->prev = b;
// 	b->next->prev = temp;
// 	b->next = temp;
// }

void	perform_r(t_lst *nil)
{
	t_lst	*temp;

	if (nil->next == nil->prev)
		return ;
	nil->prev->next = nil->next;
	nil->next->next->prev = nil;
	nil->next->prev = nil->prev;
	temp = nil->next->next;
	nil->next->next = nil;
	nil->prev = nil->next;
	nil->next = temp;
}

void	perform_rr(t_lst *nil)
{
	t_lst	*temp;

	if (nil->next == nil->prev)
		return ;
	nil->prev->prev->next = nil;
	nil->next->prev = nil->prev;
	temp = nil->prev->prev;
	nil->prev->prev = nil;
	nil->prev->next = nil->next;
	nil->next = nil->prev;
	nil->prev = temp;
}
