#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "derevtso.h"
#include "dumpnahuy.h"

struct Node_t* create_node (char* data, Node_t* node)
{
    struct Node_t* newNode = (struct Node_t*)calloc(1, sizeof(struct Node_t));
    newNode->data_node = (char*)calloc(strlen(data) + 1, sizeof(char));
    strcpy(newNode->data_node, data);
    newNode->otets = node;
    newNode->no  = NULL;
    newNode->yes = NULL;
    return newNode;
}

// struct Node_t* insert_new_value (struct Node_t* node, int data)
// {
//     if (node == NULL){return create_node (data);}

//     if (data > node->data_node){node->no = insert_new_value (node->no, data);}

//     else if (data < node->data_node){node->yes = insert_new_value (node->yes, data);}

//     return node;
// }

struct Node_t* create_first_node (char* first_object)
{
    assert (first_object);

    struct Node_t* newNode = (struct Node_t*)calloc(1, sizeof(struct Node_t));
    newNode->data_node = (char*)calloc(strlen(first_object) + 1, sizeof(char));
    strcpy(newNode->data_node, first_object);
    newNode->no = NULL;
    newNode->yes = NULL;
    newNode->otets = NULL;
    return newNode;
}

void Print (struct Node_t* node, FILE*  file_derevtso)
{
    assert (node);

    if(!node) return;

    fprintf (file_derevtso, "{");
    fprintf (file_derevtso, "%s", node->data_node);

    if (node->yes)  {Print (node->yes, file_derevtso);}
    if (node->no)   {Print (node->no, file_derevtso);}

    fprintf (file_derevtso, "}");

}

void Deductr (struct Node_t* node)
{   
    if (node)
    {
        Deductr   (node->yes);
        Deductr   (node->no);
        free      (node->data_node);
        free      (node);
    }
}

struct Node_t* adding_obj_akinator_tree (struct Node_t* node, char* sing, char* object, char* parent)
{
    assert (node);

    node->no = create_node (parent, node);

    if (node->data_node != NULL)
    {
        free (node->data_node);
    }

    node->data_node = (char*)calloc(strlen(sing) + 1, sizeof(char));
    strcpy(node->data_node, sing);

    node->yes = create_node (object, node);

    return node;
}

struct Node_t* Rise_up_to_node (Node_t* node)
{
    assert (node);

    while (node->otets != NULL)
    {   
        fprintf(stderr,"%s\n", node->data_node);
        node = node->otets;
    }

    return node;
}

void Akinator (struct Node_t* node)
{
    assert (node);

    char answer[SIZE_ANSWER] = "";

    printf("The hidden object is %s?", node->data_node);

    scanf("%s", answer);
    
    if (strcmp (no, answer) == 0)
    {
        if (node->no == NULL && node->yes ==  NULL)
        {
            char sing[SIZE_SING] = "";
            char object[SIZE_OBJECT] = "";

            printf("I am very sorry if I could not meet your expectations or if there was an error in interaction.\n"
                "Please write the name of the object that was hidden: ");
            scanf("%s", object);

            printf("Please write a sign by which you can guess the object");
            scanf("%s", sing);

            adding_obj_akinator_tree (node, sing, object, node->data_node);
    
            Akinator (Rise_up_to_node (node));
        }
        else 
        {
            Akinator (node->no);
        }    
    }

    if (strcmp (yes, answer) == 0)
    {
        if (node->no == NULL && node->yes ==  NULL)
        {
            printf ("AXUENO UOUO");
            return;
        }
        else
        {
            Akinator (node->yes);
        }
    }
}
