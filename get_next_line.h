/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klees <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:54:14 by klees             #+#    #+#             */
/*   Updated: 2019/07/16 11:54:22 by klees            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "fcntl.h"
# include "libft/libft.h"

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(const int fd, char **line);

#endif
