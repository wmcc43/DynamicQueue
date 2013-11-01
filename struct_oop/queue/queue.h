#ifndef QUEUE_H_
#define QUEUE_H_
#endif /* QUEUE_H_ */

typedef void (*func_pnt)(void *,...);
typedef int (*popfp)(void **,...);

struct Queue
{
	int number;
	popfp popQueue;
	func_pnt addQueue;
	struct Queue *next;
}typedef Queue;

Queue *newQueue(int number);
