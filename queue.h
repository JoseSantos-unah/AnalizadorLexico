
#pragma once

#include <stdlib.h>
#include "structs.h"
#include <string.h>

struct Node
{
    struct Node* next;
    const char* name ;
    Tag Tag ;
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
void printQueue(struct Queue* q);

void destroyQueue(struct Queue* q);
int compareStrings(const char* s1, const char* s2);


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
    const char* h = (control->name);

    while (control->next != null_node_ptr)
    {
        if(compareStrings(control->name, name) == 1)
        {
            return control;
        }else
        {
            control = control->next;
        }
        
    }
    
    return null_node_ptr;
}

void reserveWord(struct Queue* q, const char* name, unsigned int tag)
{
    struct Node* control = q->first;

    if(compareStrings(control->name, " ") == 1)
    {
        control->name = name;
        control->Tag = tag;

        q->size++;
    }
    else
    {
        while (control->next != null_node_ptr)
        {
            if ( compareStrings(control->name, name) == 0 )
            {
                control = control->next;
            }else
            {
                return;
            }
        }

        control->next = nodeConstructor();
        control->next->name = name;
        control->next->Tag = tag;

        q->size++;
    }
    
}

void destroyQueue(struct Queue* q)
{
    struct Node* clone = q->first;
    struct Node* control = clone;

    while (clone->next != null_node_ptr)
    {
        control = clone;
        clone = clone->next;

        free((void*) control);
    }

    free((void*) clone);
    free((void*)q);

}


void printQueue(struct Queue* q)
{
    struct Node* clone = q->first;

    while (clone->next != null_node_ptr)
    {
        printf("%s\n", clone->name);

        clone = clone->next;
    }

    printf("%s\n", clone->name);
}

int compareStrings(const char* s1, const char* s2)
{
    const char* s1p = s1;
    const char* s2p = s2;

    unsigned int count = 0;

    if (strlen(s1) == strlen(s2))
    {
        while (*s1p != '\0')
        {
            if (*s1p == *s2p)
            {
                count++;
            }else
            {
                return 0;
            }
                    
            s1p++; s2p++; 
        }

        if (count == strlen(s1))
        {
            return 1;
        }

    }else
    {
        return 0;
    }
    
}