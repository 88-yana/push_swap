/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:59:03 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:27:18 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "./struct.h"
# include "./list.h"

void	sort(t_stack *stack, t_vars *vars);
void	simple_sort(t_stack *stack, t_vars *vars);
bool	is_correspond(int num, int quaternary, int index);
void	move_cross(t_stack *stack, int quaternary[2], int index, int type);
void	move_cross_back(t_stack *stack, int quaternary, int index, int type);
t_lst	*set_lst(t_stack *stack, t_lst *lst, int type);
void	transfer_elements(t_stack *stack, int quaternary, int index, int type);
void	leave_elements(t_stack *stack, int quaternary, int index, int type);
void	move_all(t_stack *stack, int type);
int		cnt_sort(int size);

# define MAIN 0
# define SUB 1
# define FIRST 2
# define LAST 3
# define BEFORE 4
# define INDEX 0
# define TYPE 1
#endif