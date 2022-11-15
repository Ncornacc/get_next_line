/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:46:12 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/11/15 13:41:11 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join(char *ptr, char *buffer)
{
    char    *tmp;
    tmp = ft_strjoin(ptr, buffer);
    free(ptr);
    return (tmp);
}

static char *ft_next_line(char *buff)
{
    size_t  i;
    int     k;
    char    *line;

    i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    if (!buff[i])
    {
        free(buff);
        return (0);
    }
    line = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
    i++;
    k = 0;

    while (buff[i])
        line[k++] = buff[i++];
    free(buff);
    return (line);
}

static char *ft_get_line(char *buff)
{
    char    *line;
    int     i;

    i = 0;
    if (!buff[i])
        return (0);
    while (buff[i] && buff[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (buff[i] && buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    if (buff[i] && buff[i] == '\n')
        line[i++] = '\n';
    return (line);
}


static char *file_read(int fd, char *ptr)
{
    char    *buffer;
    int     n_byte;

    if (!ptr)
        ptr = ft_calloc(1, 1);
    
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    n_byte = 1;
    while (n_byte > 0)
    {
        //while not end of file keep reading
        n_byte = read(fd, buffer, BUFFER_SIZE);
        if (n_byte == -1)
        {
            free(buffer);
            return (0);
        }
        buffer[n_byte] = 0;
        ptr = ft_join(ptr, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return (ptr);
}

char    *get_next_line(int fd)
{
    static char *buff;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        if (buff != NULL)
            buff[0] = '\0'; 
        return (0);
    }
    buff = file_read(fd, buff);
    if (!buff)
    {
        buff[0] = '\0';
        return (0);
    }
    line = ft_get_line(buff);
    buff = ft_next_line(buff);
    return (line);
}
