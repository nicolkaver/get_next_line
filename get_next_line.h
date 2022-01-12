/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboratko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:55:37 by nboratko          #+#    #+#             */
/*   Updated: 2021/12/09 12:29:51 by nboratko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_raw_line(int fd, char *tmp);
char	*get_final_line(char *tmp);
char	*get_rest(char *tmp);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif
