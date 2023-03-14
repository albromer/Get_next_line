/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albromer <albromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:21:21 by albromer          #+#    #+#             */
/*   Updated: 2023/03/14 12:35:13 by albromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_content;

	if (fd < 0)
		return (NULL);
	rest_content = read_line(fd, rest_content);
	if (!rest_content)
		return (NULL);
	line = get_line(rest_content);
	rest_content = save_rest_content(rest_content);
	return (line);
}

char	*save_rest_content(char *rest_content)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (rest_content[i] && rest_content != '\n')
		i++;
	if (!rest_content[i])
	{
		free(rest_content);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_content) - i + 1));
	if (!str)
		return (NULL);
	i++;
	x = 0;
	while (rest_content[i])
	{
		str [x++] = rest_content[i++];
	}
	str[x] = '\0';
	free(rest_content);
	return (str);
}

char	*get_line(char *rest_content)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_content[i])
		return (NULL);
	while (rest_content[i] && rest_content[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_content[i] && rest_content[i] != '\n')
	{
		str[i] = rest_content[i];
		i++;
	}
	if (rest_content[i] == '\n')
	{
		str[i] = rest_content[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *rest_content)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(BUFF_SIZE + 1) * (sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(rest_content, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		rest_content = ft_strjoin(rest_content, buffer);
	}
	free (buffer);
	return (rest_content);
}
