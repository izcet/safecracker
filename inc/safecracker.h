#ifndef SAFECRACKER_H
# define SAFECRACKER_H

#include "libft.h"

typedef struct      s_layer
{
    char            **grid;
    unsigned char   rotation_offset;
    struct s_layer  *next;
}                   t_layer;

int     read_file(char *filename, t_layer **safe, int *columns, int *target);
int     crack(t_layer *safe, int columns, int target);
int     rotate(t_layer *safe, int columns);
void    print_results(t_layer *safe, int columns);

t_layer *new_layer(int cols, t_layer *next);
void    cleanup(t_layer *safe);

#endif
