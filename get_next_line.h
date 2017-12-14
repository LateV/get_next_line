/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:58:51 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/20 17:58:52 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 100

typedef struct			s_getline
{
	char				*content;
	int					content_size;
	struct s_getline	*next;
	int					pos;
}						t_getline;

int						get_next_line(const int fd, char **line);

#endif
