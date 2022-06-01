#include "task.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



struct Task* create_task(int id, int angle) {
  struct Task *task = malloc(sizeof(struct Task));
  task->id       = id;
  task->angle    = angle;
  task->solution = 0.0;

  return task;
}
void solve_task(struct Task *task) {
  if (task == NULL)
    return;
  
  printf("Solved: id: %d\tangle: %d\n", task->id, task->angle);
  task->solution = makloren(task->angle);
}
int factorial(int n) {
  int r = 1;
  while (n > 1)
    r *= (n--);

  return r;
}
double makloren(int x) {
  double res = 0.0;
#define INF 6
  for (int n = 1; n < INF; ++n)
    res += pow(-1, n + 1) * pow(x, 2 * n - 1) / factorial(2 * n - 1);

  return res;
}
int new_action() {
  // вычисление вероятности
  return rand() % 2 == 1;
}
void new_task(struct Queue **slave, int qty, int angle) {
  // given new task (Boss)
  printf("ANGLE [%d]\tNEW TASK\n\t", angle);

  struct Task *task = NULL;
  for (int id = 0; id < qty; ++id)
  {
    printf("[%d] - ", id + 1);
    if (new_action()) {
      task = create_task(id, angle); 
      push_queue(slave[id], task);
     // push(slave[i], angle);
      printf(" GIVEN\n\t");
    }
    else {
      printf("Not Given\n\t");
    }
  }
}
void work_slave(struct Queue *boss, struct Queue **slave, int qty) {
  // punckt 2
  printf("WORK SLAVE\n\t");

  struct Node *node = NULL;
  for (int id = 0; id < qty; ++id) {
    printf("[%d] - ", id + 1);
    if (new_action()) {
      while ((node = pop_queue(slave[id])) != NULL) {
        solve_task(node->data);
        push_queue(boss);
      }
    }
    else {
      printf("Not Given\n");
    }
  }
}

void calc_machine(struct Queue *boss, struct Queue **slave,
                  int qty, int start, int end) {
  for (int angle = start; angle < end; ++angle) {
    if (new_action())  // 1
      new_task(slave, qty, angle);
    
    if (new_action())  // 2
      work_slave(boss, slave, qty);

    if (new_action())  // 3
      NULL;
  }
}
