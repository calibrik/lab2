#include "queue.h"
#include <stdio.h>


int main()
{
  //struct Stack *stack = NULL;
  struct Queue *queue=NULL;	
#ifdef VECTOR_H
  queue = create_queue(10);
  //stack = create_stack(10);
#elif  LIST_H
  //stack = create_stack();
  queue=create_queue();
#endif 

  for (int i = 0; i < 10; ++i)
  {
	push_queue(queue,i);
    //push(stack, i);

  }
 /*
pop_queue(queue);
pop_queue(queue);
push_queue(queue,20);
push_queue(queue,30);
*/

  struct Node *node = NULL;
  while ((node = pop_queue(queue)) != NULL)
  {
    printf("%d\n", node->data);
    delete_node(node);
  }
  
  delete_queue(queue);

  return 0;
}
