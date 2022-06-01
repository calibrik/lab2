#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task.h"


int right_input()
{
  char input[128];
	while (1)
	{	
		fgets(input,128,stdin);
		int i=0;
		int flag=1;
		if (input[i]=='-') ++i;
		for (;input[i]!='\n' && input[i]!='\0';++i)
		{
			if (input[i]<'0'||input[i]>'9')
			{
				flag=0;
				printf("Incorrect input. Enter again: ");
				break;
			}
		}
		if (flag==1)
    { break; }
	}
  return atoi(input);
}
int right_size()     
{       
	int a=right_input();
  while (a<=0)
  {      
    printf("Incorrect input. Enter again: ");
		a=right_input();
  }
	return a;
}
struct Queue** init_slave(int qty_slave, int size)
{
  struct Queue **slave = calloc(qty_slave, sizeof(struct Queue*));
  for (int i = 0; i < qty_slave; ++i)
  {   
#ifdef VECTOR_H
    slave[i] = create_queue(size);
#elif  LIST_H
    slave[i] = create_queue();
#endif 
  }
  
  return slave;
}
void free_slave(struct Queue **slave, int qty_slave)
{
  for (int i = 0; i < qty_slave; ++i)
  {   
    delete_queue(slave[i]);
  }
  
  free(slave);
}



int main() {
  srand(time(NULL));

  int qty_slave;
  int start, end;
  if (scanf("%d %d %d", &qty_slave, &start, &end) < 3) // 90 720
    return 1;

  int distance = (end - start) % 360; // 630 % 360
  if (distance == 0)
    end = start + 360;
  else
    end = start + distance; // 360 

  struct Queue **slave = init_slave(qty_slave, distance); // [0] - BOSS

  struct Queue *boss = NULL;
#ifdef VECTOR_H
  boss = create_queue(distance);
#elif  LIST_H
  boss = create_queue();
#endif // 
       
  // PROCESS
  calc_machine(boss, slave, qty_slave, start, end);
    
  free_slave(slave, qty_slave);
  delete_queue(boss);

  return 0;
}
