/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:38:50 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/06 09:08:27 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*	if BUFFER_SIZE is undefined by user
	BUFFER_SIZE is globally defined here: */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 124
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

size_t		ft_strlen_get(const char *s);
char		*ft_strchr2(const char *c, int i);
char		*ft_strjoin(char *str1, char *buffer);
char		*ft_line_get(char *str1);
char		*ft_line_new(char *str1);
char		*get_next_line(int fd);

#endif
