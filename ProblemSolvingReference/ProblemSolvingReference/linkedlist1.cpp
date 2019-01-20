#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "malloc.h"
#include <iostream>

using namespace std;

#define MAX_N 5

int test_case;
int N;
int in[MAX_N];
int not_test_case1;

typedef struct _list_t
{
	struct _list_t *prev;
	struct _list_t *next;
	int key;
	int data;
}list_t;

list_t *phead;

void list_add_head(list_t *head, list_t *target);
void list_del(list_t *target);

list_t *add_item(int idx)
{
	list_t *ret;
	list_t *d;
	d = (list_t *)malloc(sizeof(list_t));
	d->data = in[idx];
	list_add_head(phead, d);
	ret = d;
	return ret;
}

void list_add_head(list_t *head, list_t *target)
{
	target->prev = head;
	target->next = head->next;
	head->next->prev = target;
	head->next = target;
}

void list_del(list_t *target)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;
	target->prev = target;
	target->next = target;
}

void list_init(void)
{
	if (not_test_case1 == 1)
	{
		int i = 0;
		for (i = 0; i < N; i++)
		{
			in[i] = 0;
		}
	}
	phead = (list_t *)malloc(sizeof(list_t));
	phead->next = phead;
	phead->prev = phead;

	not_test_case1 = 1;	
}

void print_list(void)
{
	list_t *tmp;
	int idx = 0;
	printf("\n");
	printf("start print_list\n");
	for (tmp = phead->next; tmp != phead; tmp = tmp->next)
	{
		printf("data(%d), idx(%d)\n", tmp->data, idx);
		idx++;
	}
	printf("end print_list\n");
	printf("\n");
}

list_t *del_item(int data)
{
	list_t *ret;
	list_t *tmp;

	for (tmp = phead->next; tmp != phead; tmp = tmp->next)
	{
		if (tmp->data == data) {
			break;
		}
	}
	list_del(tmp);
	free(tmp);
	ret = tmp;
	//printf("del_item, ret(%p)\n", ret);

	return ret;
}

int main(void)
{
	int ret = 0;
	int i, j;

	freopen("linkedlist1.txt", "r", stdin);
	scanf("%d", &test_case);
	printf("test_case(%d)\n", test_case);
	for (i = 1; i <= test_case; i++)
	{
		scanf("%d", &N);
		printf("N(%d)\n", N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &in[j]);
			printf("in[%d] = %d\n", j, in[j]);
		}
		list_init();
		for (j = 0; j < N; j++)
		{
			add_item(j);
		}
		print_list();
		del_item(3);
		print_list();

		free(phead);
	}
	return ret;
}