
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void    count_removals(char *str, int *rem_open, int *rem_close)
{
    int bal = 0;
    int i = 0;
    *rem_open = 0;
    *rem_close = 0;
    while (str[i])
    {
        if (str[i] == '(')
            bal++;
        else if (str[i] == ')')
        {
            if (bal > 0)
                bal--;
            else
                (*rem_close)++;
        }
        i++;
    }
    *rem_open = bal;
}

void backtrack(char *str, int i, int rem_open, int rem_close, int bal)
{
    if (!str[i])
    {
        if (rem_close == 0 && rem_open == 0 && bal == 0)
            puts(str);
        return ;
    }
    if (str[i] == '(')
    {
        if (rem_open > 0)
        {
            str[i] = ' ';
            backtrack(str, i + 1, rem_open - 1, rem_close, bal);
            str[i] = '(';
        }
        backtrack(str, i + 1, rem_open, rem_close, bal + 1);
        
    }
    else if (str[i] == ')')
    {
        if (rem_close > 0)
        {
            str[i] = ' ';
            backtrack(str, i + 1, rem_open, rem_close - 1, bal);
            str[i] = ')';
        }
        if (bal > 0)
            backtrack(str, i + 1, rem_open, rem_close, bal - 1);
    }
    else
        backtrack(str, i + 1, rem_open, rem_close, bal);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    char *str = argv[1];
    int rem_open;
    int rem_close;
    count_removals(str, &rem_open, &rem_close);
    backtrack(str, 0, rem_open, rem_close, 0);
    return (0);
}