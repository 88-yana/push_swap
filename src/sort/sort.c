/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:58:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/14 16:16:06 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static void	move_atob(t_lst *a, t_lst *b, int index)
{
	t_lst	*last;

	last = a->prev;
	while (1)
	{
		if (a->next->num & 1 << index)
			perform_task(ra, a, b);
		else
			perform_task(pb, a, b);
		if (a->next == last)
		{
			if (a->next->num & 1 << index)
				perform_task(ra, a, b);
			else
				perform_task(pb, a, b);
			break ;
		}
	}
}

static void	move_btoa(t_lst *a, t_lst *b, int index)
{
	t_lst	*last;

	last = a->prev;
	while (1)
	{
		if (a->next->num & 1 << index)
			perform_task(pb, a, b);
		else
			perform_task(ra, a, b);
		if (a->next == last)
		{
			if (a->next->num & << index)
				perform_task(pb, a, b);
			else
				perform_task(ra, a, b);
			break ;
		}
	}
}

// static void	move_atob(t_lst *a, t_lst *b)
// {
// 	t_lst	*last;

// 	last = a->prev;
// 	while (1)
// 	{
// 		if (a->next->num & 1)
// 		{
// 			perform_task(ra, a, b);
// 			ft_printf("stack a : ");
// 			show_list(a);
// 			ft_printf("stack b : ");
// 			show_list(b);
// 		}
// 		else
// 		{
// 			perform_task(pb, a, b);
// 			ft_printf("stack a : ");
// 			show_list(a);
// 			ft_printf("stack b : ");
// 			show_list(b);
// 		}
// 		ft_printf("\n");
// 		if (a->next == last)
// 		{
// 			if (a->next->num & 1)
// 		{
// 			perform_task(ra, a, b);
// 			ft_printf("stack a : ");
// 			show_list(a);
// 			ft_printf("stack b : ");
// 			show_list(b);
// 		}
// 		else
// 		{
// 			perform_task(pb, a, b);
// 			ft_printf("stack a : ");
// 			show_list(a);
// 			ft_printf("stack b : ");
// 			show_list(b);
// 		}
// 			break ;
// 		}
// 	}
// }

void	sort(t_stack *stack)
{
	int	index;

	index = 0;
	while (1)
	{
		move_atob(stack->a, stack->b, index);
		move_btoa(stack->b, stack->a, index + 1);
		if (vars->size == lstlen(stack->a) && is_sorted(stack->a))
			return ;
		index++;
	}
}
