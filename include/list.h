/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:23:22 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/14 16:18:21 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "struct.h"
# include "check.h"

void	perform_s(t_lst *nil);
void	perform_p(t_lst *a, t_lst *b);
void	perform_r(t_lst *nil);
void	perform_rr(t_lst *nil);
void	perform_task(t_task task, t_lst *a, t_lst *b);
t_lst	*lstnew(int num);
t_lst	*lstlast(t_lst *lst);
void	lstadd_back(t_lst **lst, t_lst *new);
void	show_list_r(t_lst *lst);
void	lstclear(t_lst **lst, t_lst *nil);
t_stack	*make_list(t_vars *vars);
void	show_list(t_lst *lst);
int	lstlen(t_lst *lst);
#endif