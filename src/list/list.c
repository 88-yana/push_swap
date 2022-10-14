/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:01 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/14 16:18:08 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

t_lst	*lstnew(int num)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = lstlast(*lst);
		new->prev->next = new;
	}
}

void	show_list(t_lst *lst)
{
	t_lst	*nil;

	nil = lst;
	lst = lst->next;
	while (lst != nil)
	{
		ft_printf("%d ", lst->num);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	show_list_r(t_lst *lst)
{
	t_lst	*nil;

	nil = lst;
	lst = lst->prev;
	while (lst != nil)
	{
		ft_printf("%d ", lst->num);
			lst = lst->prev;
	}
	ft_printf("\n");
}

int	lstlen(t_lst *lst)
{
	int		size;
	t_lst	*nil;

	size = 0;
	nil = lst;
	lst = lst->next;
	while (lst != nil)
	{
		lst = lst->next;
		size++;
	}
}

void	lstclear(t_lst **lst, t_lst *nil)
{
	t_lst	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	while (1)
	{
		temp = (*lst)->next;
		free((*lst));
		ft_printf("1 : %d\n", 1);
		*lst = temp;
		if (temp == nil)
			break ;
	}
	*lst = NULL;
}

//下のものから都合に合わせて，上に変えた検証はしていない
// void	lstclear(t_lst **lst, t_lst *nil)
// {
// 	t_lst	*suc;

// 	if (lst == NULL || *lst == NULL)
// 		return ;
// 	while (1)
// 	{
// 		suc = (*lst)->next;
// 		free((*lst));
// 		if (suc == nil)
// 			break ;
// 		*lst = suc;
// 	}
// 	*lst = NULL;
// }