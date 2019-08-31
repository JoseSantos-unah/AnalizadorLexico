
#include <stdlib.h>

struct Node
{
    struct Node* next;
    const char* name ;
    unsigned int Tag ;
};

struct Queue
{
    unsigned int size ;
    struct Node* first;
};

#define null_node_ptr (struct Node*)0

struct Node* nodeConstructor();
struct Queue* queueConstructor();

struct Node* getFromQueue(struct Queue* q, const char* name);
void reserveWord(struct Queue* q, const char* name, unsigned int tag);

struct Node* nodeConstructor()
{
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->name = " ";
    n->next = null_node_ptr;
    n->Tag = 0;

    return n;
}

struct Queue* queueConstructor()
{
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->first = nodeConstructor();
    q->size = 0;

    return q;
}

struct Node* getFromQueue(struct Queue* q, const char* name)
{
    struct Node* control = q->first;

    if(control->name == name)
    {
        return control;
    }

    while (control->next != null_node_ptr)
    {
        if(control->name == name)
        {
            return control;
        }else
        {
            control = control->next;
        }
    }
    
    struct Node* r = nodeConstructor();

    return r;
}

void reserveWord(struct Queue* q, const char* name, unsigned int tag)
{
    struct Node* control = q->first;

    if(control == null_node_ptr)
    {
        control = nodeConstructor();
        control->name = name;
        control->Tag = tag;

        (*q).size++;
    }
    else
    {
        while (control->next != null_node_ptr)
        {
            control = control->next;
        }

        control->next = nodeConstructor();
        control->next->name = name;
        control->next->Tag = tag;

        (*q).size++;
    }
    

}
