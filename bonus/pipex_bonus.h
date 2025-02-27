/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:34 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/26 14:02:13 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
#include "../ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
typedef struct s_pipe 
{
	char *infile;
	char **cmd;
	char *outfile;
}		t_pipe;

//ft_strjoin
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
//check_input
int	check_arg(int ac, char **av);
void	check_env(int ac, char **av, char **env, int i);
//pipex_utils
void	close_fd(int fd_in, int fd_out);
int	check_access(char *cmd);
void	free_arr(char **arr);
void ft_perror(char *error);
#endif
