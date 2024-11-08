#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "derevtso.h"
#include "dumpnahuy.h"

struct Node_t* create_node (int data)
{
    struct Node_t* newNode = (struct Node_t*)calloc(1, sizeof(struct Node_t));
    newNode->data_node = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node_t* insert_new_value (struct Node_t* node, int data)
{
    if (node == NULL){return create_node (data);}

    if (data > node->data_node){node->left = insert_new_value (node->left, data);}

    else if (data < node->data_node){node->right = insert_new_value (node->right, data);}

    return node;
}

void Print (struct Node_t* node)
{
    assert (node);

    if(!node) return;

    printf ("(");
    printf ("%d", node->data_node);

    if (node->right)  {Print (node->right);}
    if (node->left)   {Print (node->left);}

    printf (")");
}

void Deductr (struct Node_t* node)
{   
    if (node)
    {
        Deductr   (node->right);
        Deductr   (node->left);
        free      (node);
    }
}