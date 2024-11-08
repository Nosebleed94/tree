#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <assert.h>

#include "derevtso.h"
#include "dumpnahuy.h"

void Dump_moment (struct Node_t* node)
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    long seconds = tv.tv_sec;
    long microseconds = tv.tv_usec;

    char filename[SIZE_FILENAME] = {0};
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.dot",  seconds, microseconds);
    
    FILE* file_html = fopen ("dump.html", "a+");
    assert (file_html && "file open err");

    FILE* file_dump = fopen (filename, "a+");
    assert (file_dump && "file open err");

    fprintf (file_dump, "%s", adding_html_first);

    Print_to_arr (node, file_dump);
    
    Print_dot (node, file_dump);

    char command[SIZE_COMMAND] = {};
    snprintf (command, sizeof(command), "dot -Tpng %s -o %.22s.png", filename, filename);
    snprintf (filename, sizeof(filename), "file_%ld_%06ld.png",  seconds, microseconds);
    fprintf  (file_html, "\t<img src=\"%s\"/>\n", filename);
    fprintf  (file_dump, "}\n");
    fclose   (file_dump);   
    system   (command);
    fclose   (file_html);

    return;
}

void Print_dot (struct Node_t* node, FILE* file)
{
    if(!node) return; 

    if (node->right)
    {
        fprintf   (file,"%d:<f2> -> %d\n", node->data_node, node->right->data_node);
        Print_dot (node->right, file);
    }
    if (node->left)
    {
        fprintf   (file, "%d:<f1> -> %d\n", node->data_node, node->left->data_node);
        Print_dot (node->left, file);
    }
}

void Print_to_arr (struct Node_t* node, FILE* file)
{
    assert (node);

    if(!node) return; 

    void* pointer = (void*)(uintptr_t)node->data_node; // спросить Вову 
    fprintf (file, "%d[shape=record, label= \"{ip: %p | data: %d | {<f1> no | <f2> yes}}\"];\n", 
    node->data_node, pointer, node->data_node);

    if (node->left)   {Print_to_arr (node->left, file);}
    if (node->right)  {Print_to_arr (node->right, file);}
}