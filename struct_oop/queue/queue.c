#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static int pullFunc(Queue **start);
static void pushFunc(Queue *last,int number);
static void insert(Queue *start, int after,int number);
Queue *newQueue(int number);

static int pullFunc(Queue **start)
{
	int result;
	Queue *temp=*start;
	result=(*start)->number;
	*start=(*start)->next;
	free(temp);
	return result;
}

static void insert(Queue *start, int after,int number)
{
	Queue *pointer=start;
	Queue *newitem=malloc(sizeof(Queue));
	int i;
	for(i=1;i<after;i++)
	{
		if(pointer->next==NULL)
			break;
		else
			pointer=pointer->next;
	}
	newitem->number=number;
	newitem->popQueue=pullFunc;
	newitem->addQueue=pushFunc;
	newitem->insertQueue=insert;
	newitem->next=pointer->next;
	pointer->next=newitem;
}

static void pushFunc(Queue *last,int number)
{
	Queue *newitem=malloc(sizeof(Queue));
	newitem->number=number;
	newitem->popQueue=pullFunc;
	newitem->addQueue=pushFunc;
	newitem->insertQueue=insert;
	newitem->next=NULL;
	last->next=newitem;
}

Queue *newQueue(int number)
{
	Queue *newone=malloc(sizeof(Queue));
	newone->number=number;
	newone->popQueue=pullFunc;
	newone->addQueue=pushFunc;
	newone->insertQueue=insert;
	newone->next=NULL;
	return newone;
}
