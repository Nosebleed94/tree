#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

const int SIZE_FILENAME = 100;
const int SIZE_COMMAND  = 256;
const int SIZE_ANSWER   = 4;
const int SIZE_SING     = 100;
const int SIZE_OBJECT   = 25;

struct Node_t
{
    char* data_node;
    Node_t* no;
    Node_t* yes;
    Node_t* otets;
};

struct Node_t* create_node              (int data);
struct Node_t* insert_new_value         (struct Node_t* root, int data);
void Print                              (struct Node_t* node, FILE* file_derevtso);
void Deductr                            (struct Node_t* node);
void Print_dot                          (struct Node_t* node);
void Print_struct_node                       (struct Node_t* node);
struct Node_t* create_first_node        (char* first_object);
void Akinator                           (struct Node_t* node);
struct Node_t* adding_obj_akinator_tree (struct Node_t* node, char* sing, char* object, char* parent);
struct Node_t* Rise_up_to_node          (struct Node_t* node);