#include <stdio.h>
#include <stdlib.h>

void display(int size_tmp, int *tab_tmp)
{
    int i;

    if (size_tmp == 0)
        printf("\n");
    else
    {
        printf("%d", tab_tmp[0]);
        i = 1;
        while (i < size_tmp)
        {
            printf(" %d", tab_tmp[i]);
            i++;
        }
        printf("\n");
    }
}

void backtrack(int size, int size_tmp, int start, int sum, int *tab, int *tab_tmp, int target)
{
    int i = start;

    if (sum == target)
        display(size_tmp, tab_tmp);
    while (i < size)
    {
        tab_tmp[size_tmp] = tab[i];
        backtrack(size, size_tmp + 1, i + 1, sum + tab[i], tab, tab_tmp, target);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    int size = argc - 2;
    int target = atoi(argv[1]);

    if (argc < 2)
        return 1;
    if (size > 0)
    {
        int *tab = malloc(sizeof(int) * size);
        int *tab_tmp = malloc(sizeof(int) * size);
        if (!tab || !tab_tmp)
            return 1;
        while (i < size)
        {
            tab[i] = atoi(argv[i + 2]);
            i++;
        }
        backtrack(size, 0, 0, 0, tab, tab_tmp, target);
        free(tab);
        free(tab_tmp);
    }
    return 0;
}
