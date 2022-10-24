/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:20:42 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/20 22:52:40 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "struct.h"

void	print_error(char *message);
void	check_arg(long long argc, char **argv);
void	check_duplicate(t_vars *vars);
void	check_sorted(t_vars *vars);
void	malloc_error(void);
bool	is_sorted(t_lst *lst);
// bool	is_sorted(t_lst *lst);
#endif