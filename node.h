#ifdef VECTOR_H

struct Node
{
//  int data;
//  struct Task *data;
  void *data;
};


#elif LIST_H

struct Node
{
  //int          data;
//  struct Task *data;
  void *data;
  struct Node *next;
};

#endif 

struct Node* create_node(void *data);
void         delete_node(struct Node *node);
