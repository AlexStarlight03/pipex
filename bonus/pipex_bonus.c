/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:05:42 by alexandrine       #+#    #+#             */
/*   Updated: 2023/09/03 17:19:47 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    exec(char *cmd, char **envp)
{
    char    **lst_cmd;
    char    *path;

    lst_cmd = ft_split(cmd, ' ');
    path = find_path(lst_cmd[0], envp);
    if (execve(path, lst_cmd, envp) == -1)
    {
        ft_putstr_fd("pipex: no command found\n", 2);
        ft_putendl_fd(lst_cmd[0], 2);
        free_tab(lst_cmd);
        exit(0);
    }
}

void    here_doc_add(char **argv, int *p_fd)
{
    char    *ret;

    close(p_fd[0]);
    while (1)
    {
        ret = get_next_line(0);
        if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0)
        {
            free(ret);
            exit(0);
        }
        ft_putstr_fd(ret, p_fd[1]);
        free(ret);
    }
}

void    here_doc(char **argv)
{
    pid_t   pid;
    int     p_fd[2];

    if (pipe(p_fd) == -1)
        exit(0);
    pid = fork();
    if (pid == -1)
        exit(0);
    if (!pid)
        here_doc_add(argv, p_fd);
    else
    {
        close(p_fd[1]);
        dup2(p_fd[0], 0);
        wait(NULL);
    }
}

void    pipex(char *cmd, char **envp)
{
    pid_t   pid;
    int     p_fd[2];

    if (pipe(p_fd) == -1)
        exit(0);
    pid = fork();
    if (pid == -1)
        exit(0);
    if (!pid)
    {
        close(p_fd[0]);
        dup2(p_fd[1], 1);
        exec(cmd, envp);
    }
    else
    {
        close(p_fd[1]);
        dup2(p_fd[0], 0);
    }
}

int main (int argc, char **argv, char **envp)
{
    int i;
    int fd_in;
    int fd_out;

    if (argc < 5)
        end_exit(1);
    if (ft_strcmp(argv[1], "here_doc") == 0)
    {
        if (argc < 6)
            end_exit(1);
        i = 3;
        fd_out = open_file(argv[argc - 1], 2);
        here_doc(argv);
    }
    else
    {
        i = 2;
        fd_in = open(argv[1], 0);
        fd_out = open_file(argv[argc - 1], 1);
        dup2(fd_in, 0);
    }
    while (i < argc - 2)
        pipex(argv[i++], envp);
    dup2(fd_out, 1);
    exec(argv[argc - 2], envp);
}