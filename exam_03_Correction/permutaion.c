
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Forward declarations
void permute_rec(char *str, int l, int r, char **arr, int *index);
void permute_positions(char *str, int l, int r, char **arr, int *index, int i);
void swap(char *a, char *b);
void bubble_sort_clear(char **arr, int n);
int bubble_pass_clear(char **arr, int n);
void print_rec(char **arr, int n, int i);
void free_rec(char **arr, int n, int i);
int factorial(int n);

// Swap two characters
void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

// Permute positions recursively with backtracking
void permute_positions(char *str, int l, int r, char **arr, int *index, int i) {
    if (i > r) return;
    swap(&str[l], &str[i]);
    permute_rec(str, l + 1, r, arr, index);
    swap(&str[l], &str[i]); // backtrack
    permute_positions(str, l, r, arr, index, i + 1);
}

// Recursive permutation generator
void permute_rec(char *str, int l, int r, char **arr, int *index) {
    if (l == r) {
        arr[*index] = strdup(str);
        if (!arr[*index]) { // check strdup success
            write(2, "Memory allocation failed\n", 25);
            exit(1);
        }
        (*index)++;
        return;
    }
    permute_positions(str, l, r, arr, index, l);
}

// Recursive bubble pass
int bubble_pass_clear(char **arr, int n) {
    if (n <= 1) return 0;
    int swapped = 0;
    if (strcmp(arr[0], arr[1]) > 0) {
        char *tmp = arr[0];
        arr[0] = arr[1];
        arr[1] = tmp;
        swapped = 1;
    }
    if (bubble_pass_clear(arr + 1, n - 1)) swapped = 1;
    return swapped;
}

// Recursive bubble sort
void bubble_sort_clear(char **arr, int n) {
    if (n <= 1) return;
    if (bubble_pass_clear(arr, n)) bubble_sort_clear(arr, n);
}

// Recursive print
void print_rec(char **arr, int n, int i) {
    if (i == n) return;
    printf("%s\n", arr[i]);
    print_rec(arr, n, i + 1);
}

// Recursive free
void free_rec(char **arr, int n, int i) {
    if (i == n) return;
    free(arr[i]);
    free_rec(arr, n, i + 1);
}

// Factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Main
int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    char *str = argv[1];
    int n = strlen(str);
    int total = factorial(n);

    // Safe malloc check
    char **arr = malloc(sizeof(char*) * total);
    if (!arr) {
        write(2, "Memory allocation failed\n", 25);
        return 1;
    }

    int index = 0;
    permute_rec(str, 0, n - 1, arr, &index);
    bubble_sort_clear(arr, total);
    print_rec(arr, total, 0);
    free_rec(arr, total, 0);
    free(arr);

    return 0;
}







