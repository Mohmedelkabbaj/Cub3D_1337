#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int ft_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i]) {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int check(const char *input) {
    int i = 0;
    int j;

    while (input[i]) {
        if (input[i] == '+' && i == 0) {
            i++;
        }
        if (input[i] < '0' || input[i] > '9') {
            return EXIT_FAILURE;
        }
        i++;
    }

    int num = ft_atoi(input);
    if ((num < 60) || (num < 0) || (input[0] == '\0') || (input[0] == '\0') || (ft_atoi(&input[1]) == 0)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main() {
    const char *input = "255,222204";
    int result = check(input);

    if (result == EXIT_SUCCESS) {
        printf("Input is valid.\n");
    } else {
        printf("Input is invalid.\n");
    }

    return 0;
}
