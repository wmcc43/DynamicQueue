#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static int pullFunc(Queue **start)
{
	int result;
	Queue *temp=*start;
	result=(*start)->number;
	*start=(*start)->next;
	free(temp);
	return result;
}

static void pushFunc(Queue *last,int number)
{
	Queue *newitem=malloc(sizeof(Queue));
	newitem->number=number;
	newitem->popQueue=pullFunc;
	newitem->addQueue=pushFunc;
	newitem->next=NULL;
	last->next=newitem;
}

Queue *newQueue(int number)
{
	Queue *newone=malloc(sizeof(Queue));
	newone->number=number;
	newone->popQueue=pullFunc;
	newone->addQueue=pushFunc;
	newone->next=NULL;
	return newone;
}
