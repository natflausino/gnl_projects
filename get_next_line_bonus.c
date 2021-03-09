/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:19:28 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/08 23:25:19 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;

	if (!s)
		return (0);
	size = ft_strlen(s) + 1;
	if (start > size)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str_copy(str, (s + start), len + 1);
	str[len] = '\0';
	return (str);
}

char			*do_line(char *str_temp, int n, char **line)
{
	char		*str_extra;
	int			i;

	i = 0;
	while ((*(str_temp + i) != '\n') && (*(str_temp + i) != '\0'))
		i++;
	if ((str_temp)[i] == '\n')
	{
		*line = ft_substr(str_temp, 0, i);
		str_extra = ft_strdup(&((str_temp)[i + 1]));
		free(str_temp);
	}
	else
	{
		*line = t_strdup(temp);
		free(temp);
	}
	if (n != 0)
		if (!str_extra)
			return (NULL);
	return (str_extra);
}

int				do_read(int fd, char *buffer, char **str_temp, int *n)
{
	char		*other_temp;

	while (*n && (!(ft_strchr(*str_temp, '\n'))))
	{
		*n = read(fd, buffer, BUFFER_SIZE);
		if (*n < 0 || *n > BUFFER_SIZE)
		{
			free(buffer);
			return (0);
		}
		*(buffer + *n) = '\0';
		*other_temp = ft_strjoin(*str_temp, buffer);
		free(*str_temp);
		*str_temp = other_temp;
	}
	free(buffer);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*str_temp[OPEN_MAX];
	char		*buffer;
	int			n;

	n = 1;
	if (!line || fd < 0 || fd > LIMITED || BUFFER_SIZE <= 0)
		return (-1);
	if (!str_temp[fd])
		str_temp[fd] = ft_strdup("");
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(do_read(fd, buffer, &str_temp[fd], &n)))
		return (-1);
	str_temp[fd] = do_line(str_temp[fd], n, line);
	if (!n)
		return (0);
	return (1);
}
