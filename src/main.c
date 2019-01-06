#include "safecracker.h"

int         usage(char *exec)
{
    ft_putstr("Usage: ");
    ft_putstr(exec);
    ft_putstr(" <file to crack>");
    return (0);
}

int			main(int argc, char **argv)
{
    t_layer *safe;
    int     columns;
    int     target;
    int     err;

    if (argc != 2)
        return (usage(argv[0]));
   
    err = read_file(argv[1], &safe, &columns, &target);
    if (err)
        return (err);

    err = crack(safe, columns, target);
    if (!err)
        print_results(safe, columns);
    else
        ft_putendl("No solution :(");

    cleanup(safe);
   
	return (err);
}
