/*
 * main.c
 *
 *  Created on: 2013/10/30
 *      Author: keith
 */
#include <stdio.h>
#include "queue/queue.h"
#define MAX 50
int main()
{
	int i;
	Queue *test=newQueue(10);
	Queue *pointer=test;
	for(i=0;i<MAX;i++)
	{
		pointer->addQueue(pointer,20+i);
		pointer=pointer->next;
		/*pushFunc(20+i,pointer);
		pointer=pointer->next;*/
	}
	pointer=test;
	for(i=0;i<MAX+1;i++)
	{
		printf("%d,",pointer->number);
		pointer=pointer->next;
	}
	pointer=test;
	test->insertQueue(test,5,1000);
	printf("\nPullOut:");
	while(test!=NULL)
		printf("%d,",test->popQueue(&test));
	return 0;
}
