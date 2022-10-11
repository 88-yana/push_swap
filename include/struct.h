/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:00:14 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/11 23:31:36 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vars
{
	long			num;
	struct s_vars	*prev;
	struct s_vars	*next;
}	t_vars;

#endif
