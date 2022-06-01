vector:
					clang main.c queue.c node.c task.c -DVECTOR_H
					valgrind ./a.out

list:
					clang main.c node.c queue.c task.c -DLIST_H
					valgrind ./a.out

