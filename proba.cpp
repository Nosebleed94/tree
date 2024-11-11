#include <stdio.h>
#include <string.h>

int main() {
    char* str = "{ftl{oleg}{matvey}}";
    char ch1 = '{';
    char ch2 = '}';

    // Используем strchr для поиска символа
    char* result1 = strchr(str, ch1);
    char* result2 = strchr(str, ch2);

    printf ("position { = {%d}\n", result1 - str + 1);
    printf ("position { = {%d}", result2 - str + 1);
    return 0;
}
