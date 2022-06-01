#ifndef FOO_H
#define FOO_H

#include "queue.h"

struct Task {
  int    id; // slave
  int    angle;
  double solution;
};

struct Task* create_task(int id, int angle);

void solve_task(struct Task *task);

int factorial(int n);
double   makloren(int x);
void calc_machine(struct Queue *boss, struct Queue **slave, int qty, int start, int end);

#endif // FOO_H
