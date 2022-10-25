/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortorigin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:58:29 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 21:06:01 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static void	move_atob(t_lst *a, t_lst *b, int index) //正規版
{
	t_lst	*last;

	last = a->prev;
	while (1)
	{
		if (a->next->num & 1 << index)
			perform_task(ra, a, b,);
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

	last = b->prev;
	while (1)
	{
		if (b->next->num & 1 << index)
			perform_task(pa, a, b);
		else
			perform_task(rb, a, b);
		if (b->next == last)
		{
			if (b->next->num & 1 << index)
				perform_task(pa, a, b);
			else
				perform_task(rb, a, b);
			break ;
		}
	}
}

static void	move_all_btoa(t_lst *a, t_lst *b)
{
	t_lst	*last;

	last = b->prev;
	while (1)
	{
		perform_task(pa, a, b);
		if (b->next == last)
		{
			perform_task(pa, a, b);
			break ;
		}
	}
}

static int	cnt_digit(int max)
{
	int	digit;

	digit = 0;
	while (max)
	{
		max /= 2;
		digit++;
	}
	return (digit);
}

void	sort(t_stack *stack, t_vars *vars)
{
	int	index;
	int	digit;

	index = 0;
	digit = cnt_digit(vars->size);
	while (1)
	{
		move_atob(stack->a, stack->b, index);
		if (index == digit - 1)
			break ;
		move_btoa(stack->a, stack->b, index + 1);
		index++;
	}
	move_all_btoa(stack->a, stack->b);
}

// #include <stdio.h>

// static void	move_atob(t_lst *a, t_lst *b, int index)
// {
// 	t_lst	*last;
// 	bool	escape;

// 	last = a->prev;
// 	escape = false;
// 	while (1)
// 	{
// 		if (!(a->next->num & 1 << (index + 1)) && a->next->num & 1 << index)
// 			perform_task(pb, a, b);
// 		else if (!(a->next->num & 1 << (index + 1)) && !(a->next->num & 1 << index))
// 		{
// 			perform_task(pb, a, b);
// 			perform_task(rb, a, b);
// 		}
// 		else
// 			perform_task(ra, a, b);
// 		if (escape)
// 			break ;
// 		if (a->next == last)
// 			escape = true;
// 	}
// }

// static void	sieve_a(t_lst *a, t_lst *b, int index)
// {
// 	t_lst	*last;
// 	bool	escape;

// 	last = a->prev;
// 	escape = false;
// 	while (1)
// 	{
// 		if (a->next->num & 1 << index)
// 			perform_task(ra, a, b);
// 		else
// 			perform_task(pb, a, b);
// 		if (escape)
// 			break ;
// 		if (a->next == last)
// 			escape = true;
// 	}
// }

// static void	sieve_more(t_lst *a, t_lst *b, int index)
// {
// 	t_lst	*last;
// 	bool	escape;

// 	last = a->prev;
// 	escape = false;
// 	while (1)
// 	{
// 		if (a->next->num & 1 << (index + 1) && a->next->num & 1 << index)
// 			perform_task(ra, a, b);
// 		else
// 			perform_task(pb, a, b);
// 		if (escape)
// 			break ;
// 		if (a->next == last)
// 			escape = true;
// 	}
// }

// static void	scan_stack(t_lst *a, t_lst *b, int index)
// {
// 	t_lst	*last;
// 	bool	escape;

// 	last = a->prev;
// 	escape = false;
// 	while (1)
// 	{
// 		if (a->next->num & 1 << (index + 1) && a->next->num & 1 << index)
// 			perform_task(pb, a, b);
// 		else if (!(a->next->num & 1 << (index + 1)) && a->next->num & 1 << index)
// 		{
// 			perform_task(pb, a, b);
// 			perform_task(rb, a, b);
// 		}
// 		else
// 			perform_task(ra, a, b);
// 		if (escape)
// 			break ;
// 		if (a->next == last)
// 			escape = true;
// 	}
// }

// static void	sieve_onezero(t_lst *a, t_lst *b, int index)
// {
// 	t_lst	*last;
// 	bool	escape;

// 	last = a->prev;
// 	escape = false;
// 	while (1)
// 	{
// 		if (a->next->num & 1 << (index + 1) && !(a->next->num & 1 << index))
// 			perform_task(pb, a, b);
// 		else
// 			perform_task(ra, a, b);
// 		if (escape)
// 			break ;
// 		if (a->next == last)
// 			escape = true;
// 	}
// }

// static void	move_cross(t_lst *a, t_lst *b, int index)
// {
// 	while (!(a->prev->num & 1 << (index + 1)) && (a->prev->num & 1 << index))
// 	{
// 		perform_task(rra, a, b);
// 		perform_task(pb, a, b);
// 	}
// }

// // static void	move_btoa(t_lst *a, t_lst *b, int index)
// // {
// // 	t_lst	*last;

// // 	last = b->prev;
// // 	while (1)
// // 	{
// // 		if (b->next->num & 1 << index)
// // 			perform_task(pa, a, b);
// // 		else
// // 			perform_task(rb, a, b);
// // 		if (b->next == last)
// // 		{
// // 			if (b->next->num & 1 << index)
// // 				perform_task(pa, a, b);
// // 			else
// // 				perform_task(rb, a, b);
// // 			break ;
// // 		}
// // 	}
// // }

// static void	move_all_btoa(t_lst *a, t_lst *b)
// {
// 	t_lst	*last;

// 	last = b->prev;
// 	while (1)
// 	{
// 		perform_task(pa, a, b);
// 		if (b->next == last)
// 		{
// 			perform_task(pa, a, b);
// 			break ;
// 		}
// 	}
// }

// static int	cnt_digit(int max)
// {
// 	int	digit;

// 	digit = 0;
// 	while (max)
// 	{
// 		max /= 2;
// 		digit++;
// 	}
// 	return (digit);
// }

// // static void	move_all_btoa(t_lst *a, t_lst *b)
// // {
// // 	t_lst	*last;

// // 	last = b->prev;
// // 	while (1)
// // 	{
// // 		perform_task(pa, a, b);
// // 		if (b->next == last)
// // 		{
// // 			perform_task(pa, a, b);
// // 			break ;
// // 		}
// // 	}
// // }

// void	sort(t_stack *stack, t_vars *vars)
// {
// 	int	index;
// 	int	digit;

// 	index = 0;
// 	digit = cnt_digit(vars->size);
// 	move_atob(stack->a, stack->b, index);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	sieve_a(stack->a, stack->b, index);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	sieve_more(stack->a, stack->b, index + 2);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	scan_stack(stack->b, stack->a, index + 2);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	sieve_onezero(stack->b, stack->a, index + 2);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	move_cross(stack->a, stack->b, index + 2);
// 	move_all_btoa(stack->a, stack->b);
// 	// ft_printf("stack a : ");
// 	// show_list(stack->a);
// 	// ft_printf("stack b : ");
// 	// show_list(stack->b);
// 	// while (1)
// 	// {
// 	// 	move_atob(stack->a, stack->b, index);
// 	// 	if (index == digit - 1)
// 	// 		break ;
// 	// 	move_btoa(stack->a, stack->b, index + 1);
// 	// 	index++;
// 	// }
// 	// move_all_btoa(stack->a, stack->b);
// }

// static void	move_all_atob(t_lst *a, t_lst *b)
// {
// 	t_lst	*last;

// 	last = a->prev;
// 	while (1)
// 	{
// 		perform_task(pb, a, b);
// 		if (a->next == last)
// 		{
// 			perform_task(pb, a, b);
// 			break ;
// 		}
// 	}
// }
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

// void	sort(t_stack *stack, t_vars *vars)
// {
// 	int	index;
// 	int	digit;
// 	int	max;

// 	index = 0;
// 	digit = 0;
// 	max = vars->size;
// 	while (max)
// 	{
// 		max /= 2;
// 		digit++;
// 	}
// 	while (1)
// 	{
// 		move_atob(stack->a, stack->b, index);
// 		ft_printf("stack a : ");
// 			show_list(stack->a);
// 		ft_printf("stack b : ");
// 			show_list(stack->b);
// 		if (index == digit - 1)
// 			break ;
// 		move_btoa(stack->a, stack->b, index + 1);
// 		ft_printf("stack a : ");
// 			show_list(stack->a);
// 		ft_printf("stack b : ");
// 			show_list(stack->b);
// 		index++;
// 	}
// 	move_all_btoa(stack->a, stack->b);
// 	ft_printf("stack a : ");
// 		show_list(stack->a);
// 	ft_printf("stack b : ");
// 		show_list(stack->b);
// }
