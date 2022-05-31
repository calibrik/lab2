#include <stdlib.h>
#include "node.h"




#ifdef VECTOR_H

struct Queue
{
	size_t msize;
	size_t head;
	size_t tail;
	struct Node **nodes;
};
struct Queue* create_queue(size_t msize);
#elif LIST_H
struct Queue 
{
	struct Node *head;
	struct Node *tail;
};
struct Queue* create_queue();
#endif
int push_queue (struct Queue *queue,int data);
struct Node* pop_queue(struct Queue *queue);
void delete_queue(struct Queue *queue);

