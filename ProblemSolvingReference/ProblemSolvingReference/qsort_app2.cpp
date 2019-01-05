#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#define MAX_N 5

using namespace std;

int test_case;
int N;
int input[MAX_N];

typedef struct _data_t
{
	int id;
	int val;
}data_t;

data_t arr[MAX_N];

int main(void)
{
	int test_case;
	int i;
	freopen("qsort_app2.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &test_case);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
		printf("input[%d] = %d\n", i, input[i]);
		arr[i].id = i;
		arr[i].val = input[i];
	}
	



}