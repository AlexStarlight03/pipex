/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:48 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 18:17:25 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
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
void    here_doc_add(char **argv, int *p_fd);
void    here_doc(char **argv);
void    pipex(char *cmd, char **envp);
int main (int argc, char **argv, char **envp);

#endif