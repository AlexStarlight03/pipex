/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:19 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 18:59:02 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec(char *cmd, char **envp)
{
    char    **lst_cmd;
    char    *path;

    lst_cmd = ft_split(cmd, ' ');
    path = find_path(lst_cmd[0], envp);
    if (execve(path, lst_cmd, envp) == -1)
    {
        ft_putstr_fd("pipex: not command found: ", 2);
        ft_putendl_fd(lst_cmd[0], 2);
        free_tab(lst_cmd);
        exit(0);
    }
}

void    child(char **argv, int *p_fd, char **envp)
{
    int     fd;

    fd = open_file(argv[1], 0);
    dup2(fd, 0);
    dup2(p_fd[1], 1);
    close(p_fd[0]);
    exec(argv[2], envp);
}

void    parent(char **argv, int *p_fd, char **envp)
{
    int     fd;

    fd = open_file(argv[4], 1);
    dup2(fd, 1);
    dup2(p_fd[0], 0);
    close(p_fd[1]);
    exec(argv[3], envp);
}

int main (int argc, char **argv, char **envp)
{
    int p_fd[2];
    pid_t   pid;

    if (argc != 5)
        end_exit(1);
    if (pipe(p_fd) == -1)
        exit(-1);
    pid = fork();
    if (pid == -1)
        exit(-1);
    if (!pid)
        child(argv, p_fd, envp);
    parent(argv, p_fd, envp);
}