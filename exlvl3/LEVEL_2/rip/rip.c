#include <unistd.h>

static int str_len(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

static int is_balanced(char *s, int n)
{
    int i = 0, bal = 0;
    while (i < n)
    {
        if (s[i] == '(') bal++;
        if (s[i] == ')') bal--;
        if (bal < 0) return 0;
        i++;
    }
    return (bal == 0);
}

static void find_min(char *s, int n, int i, int *min, int lvl)
{
    char tmp;
    if (is_balanced(s, n))
    {
        if (*min == -1 || lvl < *min) *min = lvl;
    }
    while (i < n)
    {
        tmp = s[i];
        s[i] = ' ';
        find_min(s, n, i + 1, min, lvl + 1);
        s[i] = tmp;
        i++;
    }
}

static void print_rip(char *s, int n, int i, int min, int lvl)
{
    char tmp;
    if (min < lvl) return;
    if (is_balanced(s, n) && lvl == min)
    {
        write(1, s, str_len(s));
        write(1, "\n", 1);
        return;
    }
    while (i < n)
    {
        tmp = s[i];
        s[i] = ' ';
        print_rip(s, n, i + 1, min, lvl + 1);
        s[i] = tmp;
        i++;
    }
}

int main(int ac, char **av)
{
    int min = -1, i = 0;
    if (ac != 2 || av[1][0] == 0) return 1;
    while (av[1][i])
    {
        if (av[1][i] != '(' && av[1][i] != ')') return 1;
        i++;
    }
    i = str_len(av[1]);
    find_min(av[1], i, 0, &min, 0);
    print_rip(av[1], i, 0, min, 0);
    return 0;
}
