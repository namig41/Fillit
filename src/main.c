#include "fillit.h"
#include "solve.h"
#include "take_tetrimino.h"

int main(int argc, char *argv[])
{
    int fd;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        parse_file(fd);
        search_solve(g_tetro_list, g_max_size);
    }
    return (0);
}
