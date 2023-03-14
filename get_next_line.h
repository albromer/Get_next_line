/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albromer <albromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:21:42 by albromer          #+#    #+#             */
/*   Updated: 2023/03/14 11:38:40 by albromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*save_rest_content(char *rest_content);

char	*get_line(char *rest_content);

char	*read_line(int fd, char *rest_content);

size_t	ft_strlen(char *str);

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *s1, char *s2);

#endif
