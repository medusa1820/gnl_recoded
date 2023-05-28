/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:06:05 by musenov           #+#    #+#             */
/*   Updated: 2023/05/27 16:06:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// int main(void)
// {
// 	char	*line;

// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("%s", line);
// 	free(line);
// 	system("leaks stud > studleak 2>&1");
// 	return(0);
// }

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("text0.txt", O_RDONLY);
	result = get_next_line(fd);
	while (result)
	{
		printf("%s", result);
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
	// system("leaks gnl");
	system("leaks gnl > gnlleak 2>&1");
	return (0);
}
