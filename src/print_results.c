#include "safecracker.h"

char        get_num_from_next_layer(t_layer *n, int i, int columns)
{
    if (!n)
        return (0);
    return (n->grid[0][(i + n->rotation_offset) % columns]);
}

void        print_layer(t_layer *l, int columns)
{
    int     i;
    char    num;

    i = 0;
    while (i < columns)
    {
        num = l->grid[1][(i + l->rotation_offset) % columns];
        if (num == -1)
            num = get_num_from_next_layer(l->next, i, columns);
        if (num / 10 == 0)
            ft_putchar(' ');
        ft_putnbr(num);
        ft_putstr("  ");
        i++;
    }
}

void        print_results(t_layer *safe, int columns)
{
    t_layer *temp;

    temp = safe;
    while (safe)
    {
        print_layer(safe, columns);
        safe = safe->next;
        ft_putchar('\n');
    }
    safe = temp;
    while (safe)
    {
        ft_putchar('\n');
        ft_putstr("Layer rotation: ");
        ft_putnbr(safe->rotation_offset);
        safe = safe->next;
    }
    ft_putendl("\n");
}
