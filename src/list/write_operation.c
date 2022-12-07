/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:25:32 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 10:35:04 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

static t_task	change_write_task(t_task task)
{
	if (task == pa)
		return (pb);
	if (task == pb)
		return (pa);
	if (task == ra)
		return (rb);
	if (task == rb)
		return (ra);
	if (task == rra)
		return (rrb);
	if (task == rrb)
		return (rra);
	if (task == sa)
		return (sb);
	if (task == sb)
		return (sa);
	return (task);
}

void	print_operation(t_task task)
{
	if (task == pa)
		ft_printf("pa\n");
	if (task == pb)
		ft_printf("pb\n");
	if (task == ra)
		ft_printf("ra\n");
	if (task == rb)
		ft_printf("rb\n");
	if (task == rr)
		ft_printf("rr\n");
	if (task == rra)
		ft_printf("rra\n");
	if (task == rrb)
		ft_printf("rrb\n");
	if (task == rrr)
		ft_printf("rrr\n");
	if (task == sa)
		ft_printf("sa\n");
	if (task == sb)
		ft_printf("sb\n");
	if (task == ss)
		ft_printf("ss\n");
}

void	write_operation(t_task task, int type)
{
	if (type == NOWRITE)
		return ;
	if (type == BTOA)
		task = change_write_task(task);
	print_operation(task);
}

// int	main(void)
// {
// 	write_operation(sa, ATOB);
// 	write_operation(sa, BTOA);
// 	write_operation(sa, NOWRITE);
// 	write_operation(pa, ATOB);
// 	write_operation(pa, BTOA);
// 	write_operation(pa, NOWRITE);
// }
