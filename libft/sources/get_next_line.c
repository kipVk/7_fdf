/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:36:08 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:48 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		handle_line(char **line, char **file)
{
	ssize_t		i;
	char		*tmp;

	i = 0;
	while ((*file)[i] != '\n' && (*file)[i] != '\0')
		i++;
	if ((*file)[i] == '\n')
	{
		*line = ft_strsub(*file, 0, i);
		tmp = ft_strdup(&((*file)[i + 1]));
		if (!line || !tmp)
			return (-1);
		free(*file);
		*file = tmp;
		if ((*file)[0] == '\0')
			ft_strdel(file);
	}
	else if ((*file)[i] == '\0')
	{
		*line = ft_strdup(*file);
		if (!line)
			return (-1);
		ft_strdel(file);
	}
	return (1);
}

static int		handle_return(char **line, int i, char **files, int fd)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && files[fd] == NULL)
		return (0);
	else
		return (handle_line(line, &files[fd]));
}

int				get_next_line(const int fd, char **line)
{
	ssize_t			i;
	static char		*files[FD_LIMIT];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || FD_LIMIT < 1)
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (files[fd])
		{
			if (!(tmp = ft_strjoin(files[fd], buff)))
				return (-1);
			free(files[fd]);
			files[fd] = tmp;
		}
		else if (!files[fd])
			if (!(files[fd] = ft_strdup(buff)))
				return (-1);
		if (ft_strchr(files[fd], '\n'))
			break ;
	}
	return (handle_return(line, i, files, fd));
}
