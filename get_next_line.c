/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:44:31 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/28 12:29:08 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *buf, char *rea, int rbuf)
{
	char	*temp;

	rea[rbuf] = 0;
	if (!buf)
		temp = ft_substr_gnl(rea, ft_strlen_gnl(rea));
	else
		temp = going_free(buf, ft_strjoin_gnl(buf, rea));
	if (!temp)
		free (rea);
	return (temp);
}

static char	*gline(char *buf)
{
	char	*line;
	char	*aux;

	if (!buf || !buf[0])
		return (NULL);
	aux = ft_strchr_gnl(buf, BREAKER);
	if (aux)
		line = ft_substr_gnl(buf, 1 + aux - buf);
	else
		line = ft_substr_gnl(buf, ft_strlen_gnl(buf));
	if (!line)
	{
		free (buf);
		buf = NULL;
	}
	return (line);
}

static char	*nline(char *buf)
{
	char	*c;

	if (!buf[0] || (buf[0] == BREAKER && !buf[1]))
	{
		free(buf);
		return (NULL);
	}
	c = ft_strchr_gnl(buf, BREAKER);
	if (c)
	{
		if (*c == BREAKER)
			c++;
		c = ft_substr_gnl(c, ft_strlen_gnl(c));
	}
	free(buf);
	return (c);
}

static char	*reader(int fd, char *buf)
{
	int		rbuf;
	char	*rfile;

	rbuf = 1;
	rfile = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	while (rbuf > 0)
	{
		rbuf = read(fd, rfile, BUFFER_SIZE);
		if (rbuf <= 0)
		{
			going_free(rfile, NULL);
			if (rbuf == 0)
				return (buf);
			free (buf);
			return (NULL);
		}
		buf = join(buf, rfile, rbuf);
		if (!buf)
			return (NULL);
		else if (ft_strchr_gnl(buf, BREAKER))
			return (going_free(rfile, buf));
	}
	free(rfile);
	rfile = NULL;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = reader(fd, buf);
	if (!buf)
		return (NULL);
	line = gline(buf);
	buf = nline(buf);
	return (line);
}
