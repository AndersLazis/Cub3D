/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:18:19 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 15:32:40 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readline(int fd, char *str1)
{
	int		i;
	char	*temp;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 1;
	while (!ft_strchr2(str1, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[i] = '\0';
		str1 = ft_strjoin(str1, temp);
	}
	free(temp);
	return (str1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str1 = ft_readline(fd, str1);
	if (!str1)
	{
		free(str1);
		return (NULL);
	}
	line = ft_line_get(str1);
	str1 = ft_line_new(str1);
	return (line);
}

/* #include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("/Users/tstrassb/Documents/42/Projects/so_long/map_files/simple.ber", O_RDONLY);
    if (fd == -1) {
        perror("Error opening read_error.txt");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
} */