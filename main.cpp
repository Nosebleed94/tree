#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "derevtso.h"
#include "dumpnahuy.h"
#include "filinghtml.h"

int main ()
{
    FILE* file_derevtso = fopen ("file_derevtso.txt", "r+");

    fseek(file_derevtso, 0, SEEK_END);
    long int position = ftell(file_derevtso);
    size_t quentity_symbols = (size_t)position / sizeof(char);
    fseek(file_derevtso, 0, SEEK_SET);

    char first_elem[SIZE_OBJECT] = "";
    printf ("Hello, specify the first object");
    scanf("%s", first_elem);
    struct Node_t* node = create_first_node (first_elem);

    Akinator (node);
    Print (node, file_derevtso);
    // Filling_the_beginning_of_html ();
    Dump_moment (node);
    // Filling_the_end_of_html ();

    Deductr (node);

    fclose (file_derevtso);

    return 0;
}