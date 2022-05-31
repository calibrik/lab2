vector:
					clang main.c stack.c queue.c node.c -DVECTOR_H
					valgrind ./a.out

list:
					clang main.c stack.c node.c queue.c -DLIST_H
					valgrind ./a.out

