/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:48 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 17:21:01 by alexandrine      ###   ########.fr       */
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

#endif