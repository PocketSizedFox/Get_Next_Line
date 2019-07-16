/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klees <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:52:50 by klees             #+#    #+#             */
/*   Updated: 2019/07/16 14:31:44 by klees            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ft_new_line Declared - **s = the buffer - **line = given line - fd = file descriptor -
ret = return value from GNL */
int		ft_new_line(char **s, char **line, int fd, int ret)
{
	/* *temp is temporary storage for the address of s[fd] + len + 1 */
	char	*temp;
	/* len is used to get the length of the string. */
	int		len;
	
	len = 0;
	/* while the string (s[fd]) is not equal to '\n' and NUll, len with increment. */
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
		/* if the string is equal to '\n' */
	if (s[fd][len] == '\n')
	{
		/* creates a new string from s[fd] starting at position 0 until len,
		and adding it to *line */
		*line = ft_strsub(s[fd], 0, len);
		/* duplicating the string s[fd] + len + 1 into temp */
		temp = ft_strdup(s[fd] + len + 1);
		/* clearing the memory in the string s[fd] */
		free(s[fd]);
		/* setting the value of s[fd] to temp */
		s[fd] = temp;
		/* if s[fd] at position 0 is equal to NULL */
		if (s[fd][0] == '\0')
		/* deletes the address of s[fd] */
			ft_strdel(&s[fd]);
	}
	/* if the string and the length of the string is equal to NULL */
	else if (s[fd][len] == '\0')
	{
		/* if GNL's return value is equal to the BUFF_SIZE */
		if (ret == BUFF_SIZE)
		/* return GNL and its parameters */
			return (get_next_line(fd, line));
			/* duplicate s[fd] into *line */		
		*line = ft_strdup(s[fd]);
		/* delete the address of s[fd] */
		ft_strdel(&s[fd]);
	}
	/* return 1 if it's succesful */
	return (1);
}
/*Get_Next_Line Declared - takes fd (file descriptor) and **line (given line)*/
int		get_next_line(const int fd, char **line)
{
	/* *store keeps track of the line read in so far. */
	static char		*store[256];
	/* A buffer is an area of memory, set aside for temporary storage of data.
	Buf is used to store the content read from fd, given a BUFF_SIZE + 1 for the NUll terminator. */
	char			buf[BUFF_SIZE + 1];
	/* *temp temporarily stores a string */
	char			*temp;
	/* ret is the return value of how many bytes read has read. */
	int				ret;
	/* if fd or line does not exist (equal NULL) GNL will return -1 */
	if (fd < 0 || line == NULL)
		return (-1);
		/* ret(return value) is set equal to the number of bytes
		read in by the read function,
		which reads from fd and stores what its read in buf. */
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		/* buf(buffer) at point ret (currently at the last char)
		is being set as NULL */
		buf[ret] = '\0';
		/* if string does not exist, make a new string (strnew) */
		if (store[fd] == NULL)
		                /* ft_strnew allocates memory for 1 char "(1)" */
			store[fd] = ft_strnew(1);
			/* buf gets added to the end of the string at position fd in store (using function strjoin).
			The Result gets stored in temp and then only set to store after
			store has been freed. */
		temp = ft_strjoin(store[fd], buf);
		/* clears memory in store at position fd before adding the result in temp */
		free(store[fd]);
		/* setting the result in temp to store at position fd. */
		store[fd] = temp;
		/* uses strchr to find a '\n' character in buf, when found the if statement breaks. */
		if (ft_strchr(buf, '\n'))
		break ;
	}
	/* if ret is less than 0, return -1. */
	if (ret < 0)
		return (-1);
		/* if ret, store[fd], strore[fd][0] is equal to 0/NULL, return 0. */
	else if (ret == 0 && (store[fd] == NULL || store[fd][0] == '\0'))
		return (0);
		/* returns GNL to the function ft_new_line,
		and passes it store, line, fd and ret as parameters. */
	return (ft_new_line(store, line, fd, ret));
}

































































