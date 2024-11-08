#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "derevtso.h"
#include "dumpnahuy.h"
#include "filinghtml.h"

int main ()
{
    {
        struct Node_t* node = NULL;
        Filling_the_beginning_of_html ();
        node = insert_new_value (node, 50);
        node = insert_new_value (node, 30);
        node = insert_new_value (node, 35);
        node = insert_new_value (node, 70);
        node = insert_new_value (node, 10);
        node = insert_new_value (node, 65);
        node = insert_new_value (node, 80);
        node = insert_new_value (node, 66);
        Dump_moment (node);
        Filling_the_end_of_html ();
        Deductr (node);
    }
}