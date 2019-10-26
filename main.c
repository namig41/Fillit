#include "includes/fillit.h"
#include "includes/solve.h"

void draw(t_tetriminos *t, int count)
{
    for (int i=0; i < count; i++)
    {
        for (size_t j = 0; j < t[i].height; j++)
        {
            for (size_t z = 0; z < t[i].width; z++)
            {
               ft_putchar(t[i].shape[j][z]); 
            }
            ft_putchar('\n');
        }
            ft_putchar('\n');
    }
}

int main()
{
    g_tetro_list[0].shape = (char **)malloc(sizeof(char) * 3);
    g_tetro_list[0].shape[0] = (char *)malloc(sizeof(char) * 2); 
    g_tetro_list[0].shape[1] = (char *)malloc(sizeof(char) * 2); 
    g_tetro_list[0].shape[2] = (char *)malloc(sizeof(char) * 2); 

    g_tetro_list[0].shape[0] = ".x";
    g_tetro_list[0].shape[1] = "xx";
    g_tetro_list[0].shape[2] = "x.";
    g_tetro_list[0].height = 3;
    g_tetro_list[0].width = 2;
    g_tetro_list[0].letter = 'A';

    g_tetro_list[1].shape = (char **)malloc(sizeof(char) * 3);
    g_tetro_list[1].shape[0] = (char *)malloc(sizeof(char) * 2); 
    g_tetro_list[1].shape[1] = (char *)malloc(sizeof(char) * 2); 
    g_tetro_list[1].shape[2] = (char *)malloc(sizeof(char) * 2); 
    g_tetro_list[1].shape[0] = "x.";
    g_tetro_list[1].shape[1] = "xx";
    g_tetro_list[1].shape[2] = ".x";
    g_tetro_list[1].height = 3;
    g_tetro_list[1].width = 2;
    g_tetro_list[1].letter = 'B';

    search_solve(g_tetro_list, 2, 6);
    return (0);
}