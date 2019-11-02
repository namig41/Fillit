#include "includes/fillit.h"
#include "includes/solve.h"
#include "includes/take_tetrimino.h"

int main(int argc, char *argv[])
{
    int fd = open("input_test1", O_RDONLY);

    parse_file(fd);
    search_solve(g_tetro_list, 2, 4);
    return (0);
}
