/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimbada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:06:03 by jlimbada          #+#    #+#             */
/*   Updated: 2019/06/18 10:28:46 by jlimbada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function appends a single line into our line variable. We do this by
** finding the length of the line. If at index len, the character is a newline,
** we save the string into line up to the length found. Then we readjust the
** stored data (**str) by creating a temporary string that stored the rest of
** data after the newline. We free the stored data to update it to the current
** address because we already append a line from it. This is done by freeing
** *str and setting it equal to the temporary string that stored the remaining
** data. At any point when we reach the end of the file, we free the memory
** used to track our location in *str because it is not needed anymore.
*/

static int	new_line(char **str, char **line, int fd, int rt)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (rt == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

/*
** The get_next_line function reads a file and returns the line ending with a
** newline character from a file descriptor. A static variable is used, so that
** whenever get_next_line is called, it remembers the previous function call.
** When get_next_line is first called, we check to see if our static variable
** **str is empty. If it is, we allocate memory for it using our buff string.
** In the loop, we will continue to read more of the line and join them together
** using a temporary string. This temporary string will replace the stored data
** each iteration so that we can keep track of how much is read and delete
** the previous stored data. This is needed because we are only reading so many
** n-bytes at a time decided by our BUFF_SIZE. If we read at each iteration
** without freeing memory, then we would have memory leaks. The loop breaks when
** a newline is encountered. Finally, we call output function to check what
** should be returned.
*/

int			get_next_line(const int fd, char **line)
{
	static char	*str[311];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			rt;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rt < 0)
		return (-1);
	else if ((rt == 0 && str[fd] == NULL) || str[fd][0] == '\0')
		return (0);
	return (new_line(str, line, fd, rt));
}
