/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:48:54 by musenov           #+#    #+#             */
/*   Updated: 2023/05/28 11:37:08 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*

# define BUFF_SIZE 0 -> this will not work as we have to 
first check if BUFF_SIZE was defined before, e.g. among 
others in compilatin flags:

gcc -Wall -Wextra -Werror -D BUFF_SIZE=42 bonus2.c

*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

// get_next_line.c
char	*ft_strjoin(char *remains, char *buffer);
char	*push_line(char *remains);
char	*cut_next_line(char *remains);
char	*get_next_line(int fd);

// get_next_line_utils.c
int		ft_strlen(char *str);
bool	ft_strchr(char *line);

#endif
