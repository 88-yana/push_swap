/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:59:03 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 13:52:26 by hyanagim         ###   ########.fr       */
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
#endif