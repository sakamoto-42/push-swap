/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:32 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/06 17:52:49 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int		fd;
	char	*remaining;
	char	buffer[BUFFER_SIZE + 1];
}				t_file;

t_file	*ft_get_or_create_file_struct(int fd, t_file **files);
void	ft_free_file(t_file **file);
char	*ft_finalize_line(t_file **file_ptr, ssize_t bytes_read);
char	*get_next_line(int fd);
char	*ft_strcopy(const char *src, size_t size);
char	*ft_strconcat(char *dst, const char *src,
			size_t dst_len, size_t src_len);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *str);

#endif
