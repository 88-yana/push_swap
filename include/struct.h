/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:00:14 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 12:24:16 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_num {
	null = 0,
	sa = 1,
	sb = 2,
	ss = 3,
	pa = 4,
	pb = 5,
	ra = 6,
	rb = 7,
	rr = 8,
	rra = 9,
	rrb = 10,
	rrr = 11,
}	t_task;

typedef struct s_vars
{
	int		*elements;
	int		*twin;
	int		size;
	int		max_turn;
	t_task	task[13];
	t_task	task_sub[13];
}	t_vars;

typedef struct s_lst
{
	int		num;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
}	t_stack;

#endif
