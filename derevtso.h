#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

const int SIZE_FILENAME = 100;
const int SIZE_COMMAND  = 256;

struct Node_t
{
    int data_node;
    Node_t* left;
    Node_t* right;
};

struct Node_t* create_node       (int data);
struct Node_t* insert_new_value  (struct Node_t* root, int data);
void Print                       (struct Node_t* node);
void Deductr                     (struct Node_t* node);
void Print_dot                   (struct Node_t* node);
void Print_to_arr                (struct Node_t* node);
