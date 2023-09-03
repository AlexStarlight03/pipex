/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:32 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 17:08:39 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    end_exit(int info_exit)
{
    if (info_exit == 1)
        ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
    exit(0);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

void    free_tab(char **tab)
{
    size_t  i;

    i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char    *get_envp(char *name, char **envp)
{
    int     i;
    int     j;
    char    *sub;

    i = 0;
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] && envp[i][j] != '=')
            j++;
        sub = ft_substr(envp[i], 0 , j);
        if (ft_strcmp(sub, name) == 0)
        {
            free(sub);
            return (envp[i] + j + 1);
        }
        free(sub);
        i++;
    }
    return (NULL);
}

char    *find_path(char *cmd, char **envp)
{
    int     i;
    char    *exec;
    char    **allpaths;
    char    *mypaths;
    char    **lst_cmd;

    i = -1;
    allpaths = ft_split(get_envp("PATH", envp), ':');
    lst_cmd = ft_split(cmd, ' ');
    while (allpaths[++i])
    {
        mypaths = ft_strjoin(allpaths[i], "/");
        exec = ft_strjoin(mypaths, lst_cmd[0]);
        free(mypaths);
        if (access(exec, F_OK | X_OK) == 0)
        {
            free_tab(lst_cmd);
            return (exec);
        }
        free(exec);
    }
    free_tab(allpaths);
    free_tab(lst_cmd);
    return (cmd);
}