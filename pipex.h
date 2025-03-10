/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:34 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/28 18:42:09 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	*infile;
	char	**cmd;
	char	*outfile;
}			t_pipe;

// ft_strjoin
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
void		ft_putstr_fd(char *s, int fd);

int			ft_strcmp(char *s1, char *s2);
// check_input
int			check_arg(int ac, char **av);
void		check_env(int ac, char **av, char **env, int i);
char		*get_path(char **env);
// pipex_utils
void		close_fd(int fd_in, int fd_out);
int			check_access(char *cmd);
void		free_arr(char **arr);
void		ft_perror(char *error);
char		*find_path(char *cmd, char **env);
#endif
