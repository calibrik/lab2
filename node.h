#ifdef VECTOR_H

struct Node
{
  int data;
};


#elif LIST_H

struct Node
{
  int          data;
  struct Node *next;
};

#endif 

struct Node* create_node(int data);
void         delete_node(struct Node *node);
