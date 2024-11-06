/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:47:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/16 18:22:43 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef PATH
#  define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/."
# endif

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h>

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
void	free_list(char **paths);
char	**ft_spliter(char *str);
char	**join_comand(char **str1, char *str2);
char	*ft_strrchr(const char *s, int c);
int		quote_is_after(char *str);
void	error(char *comand);
char	*delete_slash(char *str);
void	exec(char *path, char **comand, char **paths, char **env);
#endif