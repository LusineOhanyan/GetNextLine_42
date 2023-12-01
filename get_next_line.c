/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.C                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:33:11 by lohanyan          #+#    #+#             */
/*   Updated: 2022/06/05 13:41:31 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

int	count(char *tmp)
{
	int	count;

	count = 0;
	while (tmp[count] != '\0')
	{
		if (tmp[count] == '\n')
			return (count + 1);
		count++;
	}
	return (count);
}

void	trim(char **tmp, int count)
{
	int		i;
	char	*stat;

	i = 0;
	stat = *tmp;
	while (stat[count + i] != '\0')
	{
		i++;
	}
	*tmp = ft_substr(*tmp, count, i);
	free (stat);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tmp;
	int			i;
	int			len;
	char		*str;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i > 0 && ft_strchr(buf, '\n') == NULL)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || (tmp == NULL && i == 0))
			return (NULL);
		buf[i] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(tmp, buf);
	}
	len = count(tmp);
	str = ft_substr(tmp, 0, len);
	trim(&tmp, len);
	return (str);
}
