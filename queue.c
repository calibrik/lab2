#include "queue.h"


#ifdef VECTOR_H



struct Queue* create_queue(size_t msize)
{
	struct Queue *queue=calloc(1,sizeof(struct Queue));
	queue->msize=msize;
	queue->nodes=calloc(msize,sizeof(struct Nodes*));
	return queue;
}




void delete_queue(struct Queue *queue)
{
	for (queue->head=0;queue->head<queue->msize;++queue->head)
        {
		
        	if (queue->nodes[queue->head]!=NULL) free(queue->nodes[queue->head]);
        }
        free(queue->nodes);
        free(queue);
}



int push_queue (struct Queue *queue,int data)
{
	if (queue->tail==queue->msize)
	{
		if (queue->head!=0)
		{
			queue->tail=0;
		}
		else return 1;
	}
	else 
	{
		if (queue->tail==queue->head&&queue->head!=0) return 1;
	}
	queue->nodes[queue->tail]=create_node(data);
	++queue->tail;
	return 0;
}



struct Node* pop_queue(struct Queue *queue)
{	
	if (queue->msize==queue->head)
	{
		if (queue->tail==queue->msize) return NULL;
		queue->head=0;
	}
	if (queue->tail==queue->head) return NULL;
	++queue->head;
	return queue->nodes[queue->head-1];
}
#elif LIST_H



struct Queue* create_queue()
{
	struct Queue *queue=calloc(1,sizeof(struct Queue));
	return queue;
}


void delete_queue(struct Queue *queue)
{
	if (queue->head!=NULL)
	{
	struct Node *trash=queue->head;
	queue->head=queue->head->next;
	delete_node(trash);
	}
	free(queue);
}



int push_queue (struct Queue *queue,int data)
{
	struct Node *new=create_node(data);
	if (queue->tail==NULL)
	{
		queue->tail=new;
		queue->head=new;

	}
	else
	{
		queue->tail->next=new;
		queue->tail=queue->tail->next;
	}
	return 0;
}


struct Node* pop_queue(struct Queue *queue)
{
	if (queue->head==NULL) return NULL;
	struct Node *curr=queue->head;
	queue->head=queue->head->next;
	curr->next=NULL;
	return curr;
}
#endif
