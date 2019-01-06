#include "safecracker.h"


int     sum_column(t_layer *safe, int col, int columns)
{
    int     n;

    n = 0;
    if (safe)
    {
        n = safe->grid[1][(safe->rotation_offset + col) % columns];
        if (n == -1 && safe->next)
            n = safe->next->grid[0][(safe->next->rotation_offset + col) % columns];
        n += sum_column(safe->next, col, columns);
    }
    return (n);
}

int     rotate(t_layer *safe, int columns)
{
    if (!safe)
        return (0);
    safe->rotation_offset++;
    if (safe->rotation_offset >= columns)
    {
        safe->rotation_offset = 0;
        return (rotate(safe->next, columns));
    }
    return (1);
}

int     solved(t_layer *safe, int columns, int target)
{
    int     i;
    int     n;

    i = 0;
    while (i < columns)
    {
        n = sum_column(safe, i, columns);
        if (n != target)
            return (0);
        i++;
    }
    return (1);
}

int     crack(t_layer *safe, int columns, int target)
{
    int     solveable;

    solveable = 1;
    while (solveable)
    {
        if (solved(safe, columns, target))
            return (0);
        solveable = rotate(safe, columns);
    }
    return (1);
}
