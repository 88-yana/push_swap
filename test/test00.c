// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test00.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/13 16:44:18 by hyanagim          #+#    #+#             */
// /*   Updated: 2022/10/13 17:19:55 by hyanagim         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../include/main.h"

// #include <stdio.h>

// int	main(void)
// {
// 	char** yes[5] = {"123", "0", "2147483647", "-2147483648", NULL};
// 	char** no[8] = {"123a", "001", "2147483648",
// 		 "-2147483649", "akf", "11a11", "214748364719", NULL};
// 	int i;

// 	i = 0;
// 	while (yes[i] != NULL)
// 	{
// 		printf("%s, %d\n", yes[i], is_number(yes[i]));
// 		printf("%s, %d\n", yes[i], is_int(yes[i]));
// 		i++;
// 	}
// 	i = 0;
// 	while (no[i])
// 	{
// 		printf("%s, %d\n", no[i], is_number(no[i]));
// 		printf("%s, %d\n", no[i], is_int(no[i]));
// 		i++;
// 	}

// 	return (0);
// }
