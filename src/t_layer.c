#include "safecracker.h"

void    cleanup(t_layer *safe)
{
    t_layer *temp;

    while (safe)
    {
        temp = safe->next;
        if (safe->grid)
        {
            if (safe->grid[0])
                free(safe->grid[0]);
            if (safe->grid[1])
                free(safe->grid[1]);
            free(safe->grid);
        }
        free(safe);
        safe = temp;
    }
}

t_layer *new_layer(int cols, t_layer *next)
{
    t_layer *l;
    int     i;

    l = (t_layer *)malloc(sizeof(t_layer));
    if (!l)
        return (NULL);

    l->rotation_offset = 0;
    l->next = next;

    l->grid = (char **)malloc(sizeof(char *) * 2);
    if (!l->grid)
    {
        cleanup(l);
        return (NULL);
    }

    i = 0;
    while (i < 2)
    {
        l->grid[i] = (char *)malloc(sizeof(char) * cols);
        if (!l->grid[i])
        {
            cleanup(l);
            return (NULL);
        }
        i++;
    }
    return (l);
}
