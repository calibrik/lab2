#include "stack.h"



#ifdef VECTOR_H

struct Stack* create_stack(size_t msize)
{
  struct Stack *stack = calloc(1, sizeof(struct Stack));
  stack->msize        = msize;
  stack->nodes        = calloc(msize, sizeof(struct Node*));

  return stack;
}
void delete_stack(struct Stack *stack)
{
  for (int i = stack->head; i > 0; --i)
  {
    delete_node(stack->nodes[i - 1]);
  }
  free(stack->nodes);
  free(stack);
}
int push(struct Stack *stack, int data)
{
  if (stack->head == stack->msize)
  { return EXIT_FAILURE; } // 1
  
  stack->nodes[ stack->head ] = create_node(data);
  ++stack->head;

  return EXIT_SUCCESS;
}
struct Node* pop(struct Stack *stack)
{
  if (stack->head == 0)
  { return NULL; }

  --stack->head;
  return stack->nodes[ stack->head ];
}

#elif LIST_H

struct Stack* create_stack()
{
  return calloc(1, sizeof(struct Stack)); // stack->head = NULL;
}
void delete_stack(struct Stack *stack)
{
  struct Node *trash = NULL;
  while (stack->head != NULL)
  {
    trash = stack->head;
    stack->head = stack->head->next;
    delete_node(trash);
  }
  free(stack);
}
int push(struct Stack *stack, int data)
{
  struct Node *new_node = create_node(data);
  new_node->next = stack->head;
  stack->head = new_node;

  return EXIT_SUCCESS;
}
struct Node* pop(struct Stack *stack)
{
  if (stack->head == NULL)
  { return NULL; }

  struct Node *node = stack->head;
  stack->head = stack->head->next;
  node->next = NULL;

  return node;
}

#endif
