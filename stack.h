#include <stdlib.h>
#include "node.h"

#ifdef VECTOR_H

struct Stack
{
  size_t        head; 
  size_t        msize;
  struct Node **nodes;
};

struct Stack* create_stack(size_t msize);

#elif LIST_H

struct Stack
{
  struct Node *head;
};

struct Stack* create_stack();

#endif 

void delete_stack(struct Stack *stack);

int         push(struct Stack *stack, int data);
struct Node* pop(struct Stack *stack);

