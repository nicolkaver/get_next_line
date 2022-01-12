/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:36:20 by nboratko          #+#    #+#             */
/*   Updated: 2021/12/09 12:31:29 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char *tmp)
{
	char	*buf;
	ssize_t	nbytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(tmp, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(buf), NULL);
		if (!tmp)
			tmp = ft_strdup("");
		buf[nbytes] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_final_line(char *tmp)
{
	char	*str;
	int		i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_rest(char *tmp)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
		return (free(tmp), NULL);
	len = ft_strlen(tmp);
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (tmp[i])
		str[j++] = tmp[i++];
	str[j] = '\0';
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*tmp[MAX_FD + 1];

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = get_raw_line(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	ret = get_final_line(tmp[fd]);
	tmp[fd] = get_rest(tmp[fd]);
	return (ret);
}
