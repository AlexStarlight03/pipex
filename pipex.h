/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:27 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 18:46:12 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void    end_exit(int info_exit);
int	    open_file(char *file, int in_or_out);
void    free_tab(char **tab);
char    *get_envp(char *name, char **envp);
char    *find_path(char *cmd, char **envp);
void    exec(char *cmd, char **envp);
void    child(char **argv, int *p_fd, char **envp);
void    parent(char **argv, int *p_fd, char **envp);
int main (int argc, char **argv, char **envp);

#endif