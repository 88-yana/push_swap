/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:59:03 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:12:44 by hyanagim         ###   ########.fr       */
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

# define MAIN 0
# define SUB 1
# define FIRST 2
# define LAST 3
# define BEFORE 4
# define INDEX 0
# define TYPE 1
#endif