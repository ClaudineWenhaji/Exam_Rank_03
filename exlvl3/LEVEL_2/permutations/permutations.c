#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int isin(char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *sort_str(char *s)
{
    int len = ft_strlen(s);
    int sorted = 0, i;
    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (i < len - 1)
        {
            if (s[i] > s[i + 1])
            {
                swap(&s[i], &s[i + 1]);
                sorted = 0;
            }
            i++;
        }
    }
    return s;
}

void perms(char *s, char *out, int pos)
{
    int i = 0;
    if (ft_strlen(out) == ft_strlen(s))
    {
        write(1, out, ft_strlen(out));
        write(1, "\n", 1);
        return;
    }
    while (s[i])
    {
        if (!isin(out, s[i]))
        {
            out[pos] = s[i];
            perms(s, out, pos + 1);
            out[pos] = 0;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    char *out;
    char *s;

    if (ac != 2 || ft_strlen(av[1]) == 0)
        return 1;
    out = calloc(ft_strlen(av[1]) + 1, 1);
    if (!out)
        return 1;
    s = sort_str(av[1]);
    perms(s, out, 0);
    free(out);
    return 0;
}
