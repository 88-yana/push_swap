/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:45:19 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/11 08:46:16 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

bool	is_correspond(int num, int quaternary, int index)
{
	if (quaternary == 0)
		if (!(num & 1 << (index + 1)) && !(num & 1 << index))
			return (true);
	if (quaternary == 1)
		if (!(num & 1 << (index + 1)) && num & 1 << index)
			return (true);
	if (quaternary == 10)
		if (num & 1 << (index + 1) && !(num & 1 << index))
			return (true);
	if (quaternary == 11)
		if (num & 1 << (index + 1) && num & 1 << index)
			return (true);
	return (false);
}
