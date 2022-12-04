/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:01 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 08:58:53 by hyanagim         ###   ########.fr       */
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

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }
int		is_base(char *base);
void	reput(int nbr, char *base, int size);

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	if (!is_base(base))
		return ;
	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	if (nbr == -2147483648)
	{
		nbr += i;
		nbr *= -1;
		ft_putchar('-');
		reput(nbr / i + 1, base, i);
		ft_putchar(base[nbr % i]);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		reput(nbr, base, i);
	}
	else
		reput(nbr, base, i);
}

void	reput(int nbr, char *base, int size)
{
	int	x;

	if (nbr >= size)
		reput(nbr / size, base, size);
	x = nbr % size;
	ft_putchar(base[x]);
}

int	is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	show_list(t_lst *lst)
{
	t_lst	*nil;

	nil = lst;
	lst = lst->next;
	while (lst != nil)
	{
		ft_putnbr_base(lst->num, "0123456789");
		ft_putchar(' ');
		lst = lst->next;
	}
	ft_printf("\n");
}

// void	show_list_r(t_lst *lst)
// {
// 	t_lst	*nil;

// 	nil = lst;
// 	lst = lst->prev;
// 	while (lst != nil)
// 	{
// 		ft_printf("%d ", lst->num);
// 			lst = lst->prev;
// 	}
// 	ft_printf("\n");
// }

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
	return (size);
}

// void	lstclear(t_lst **lst, t_lst *nil)
// {
// 	t_lst	*temp;

// 	if (lst == NULL || *lst == NULL)
// 		return ;
// 	while (1)
// 	{
// 		temp = (*lst)->next;
// 		free((*lst));
// 		ft_printf("1 : %d\n", 1);
// 		*lst = temp;
// 		if (temp == nil)
// 			break ;
// 	}
// 	*lst = NULL;
// }

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


// #include "../../include/main.h"
// #include <stdio.h>

// static void	make_ring(t_lst *lst)
// {
// 	(*lst).prev = lstlast(lst);
// 	lstlast(lst)->next = lst;
// }

// int	main(void)
// {
// 	t_lst	*lst;
// 	t_lst	*temp;
// 	int		i;

// 	lst = lstnew(0);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		// if (i == 0)
// 		// 	temp = lstnew(1);
// 		// if (i == 1)
// 		// 	temp = lstnew(2);
// 		// if (i == 2)
// 		// 	temp = lstnew(3);
// 		// if (i == 3)
// 		// 	temp = lstnew(5);
// 		// if (i == 4)
// 		// 	temp = lstnew(4);
// 		if (i == 0)
// 			temp = lstnew(0);
// 		if (i == 1)
// 			temp = lstnew(5);
// 		if (i == 2)
// 			temp = lstnew(3);
// 		if (i == 3)
// 			temp = lstnew(4);
// 		if (i == 4)
// 			temp = lstnew(2);
// 		lstadd_back(&lst, temp);
// 		i++;
// 	}
// 	make_ring(lst);
// 	printf("%d\n", lstlen(lst));
// 	return (0);
// }