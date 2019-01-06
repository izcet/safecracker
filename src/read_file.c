#include "safecracker.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int     bad_file(char *filename, int line_num, t_layer *temp)
{
    ft_putstr("Bad file: ");
    ft_putendl(filename);
    ft_putstr("At line number: ");
    ft_putnbr(line_num);
    ft_putendl(" (first line in the file is 1)");

    cleanup(temp);
    return (1);
}

int     read_header_line(int fd, int *dst, int *ln)
{
    int     ret;
    char    *line;

    (*ln)++;
    ret = get_next_line(fd, &line);
    if (ret <= 0)
        return (1);
    *dst = ft_atoi(line);
    free(line);
    return (0);
}

int     read_layer(int fd, t_layer **temp, int *ln, int cols)
{
    char    *line;
    char    *i;
    int     ret;
    int     col;
    int     x;
    t_layer *newl;

    newl = new_layer(cols, *temp);
    // If we don't have space to malloc... 
    // error occurs on line number -11 ¯\_(ツ)_/¯
    if (!temp)
    {
        *ln = -11;
        return (1);
    }
    *temp = newl;

    // clear the empty line
    (*ln)++;
    ret = get_next_line(fd, &line);
    if (ret <= 0)
        return (1);
    free(line);

    (*ln)++;
    ret = get_next_line(fd, &line);
    if (ret <= 0)
        return (1);

    i = line;
    col = 0;
    while (col < cols)
    {
        newl->grid[0][col] = ft_atoi(i);
        x = 0;
        while (x++ < 3 && *i)
            i++;
        if (x != 4)
        {
            free(line);
            return (1);
        }
        col++;
    }
    free(line);

    (*ln)++;
    ret = get_next_line(fd, &line);
    if (ret <= 0)
        return (1);

    i = line;
    col = 0;
    while (col < cols)
    {
        newl->grid[1][col] = ft_atoi(i);
        x = 0;
        while (x++ < 3 && *i)
            i++;
        if (x != 4)
        {
            free(line);
            return (1);
        }
        col++;
    }
    free(line);

    return (0);
}

int     read_file(char *filename, t_layer **safe, int *columns, int *target)
{
    int     fd;
    int     ret;
    int     ln;
    int     cols;
    int     targ;
    int     lays;
    t_layer *temp;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("Unable to open file: ");
        ft_putendl(filename);
        return (-1);
    }

    ln = 0;
    ret = read_header_line(fd, &targ, &ln);
    if (ret)
        return (bad_file(filename, ln, NULL));
    ret = read_header_line(fd, &lays, &ln);
    if (ret)
        return (bad_file(filename, ln, NULL));
    ret = read_header_line(fd, &cols, &ln);
    if (ret)
        return (bad_file(filename, ln, NULL));

    while (lays--)
    {
        ret = read_layer(fd, &temp, &ln, cols);
        if (ret == -1)
            return (bad_file(filename, ln, temp));
    }

    *safe = temp;
    *columns = cols;
    *target = targ;
    return (0);
}
