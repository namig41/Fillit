#include "fillit.h"
#include "solve.h"
#include "take_tetrimino.h"

int main(void)
{
    int fd = open("input_test1", O_RDONLY);

    parse_file(fd);
    search_solve(g_tetro_list, 2, 4);
    return (0);
}
