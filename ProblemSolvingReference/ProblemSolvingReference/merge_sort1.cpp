#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 200000

//#define NORMAL
#define TEST1

struct _mystr_t
{
	int id;
	int val;
};

typedef struct _mystr_t mystr_t;

int testN;

mystr_t A[MAX_N];
mystr_t temp[MAX_N];

int mergesort(int , int );
int print_mergesort(void);
int gen_input_data(void);

int main(void)
{
	int ret = 0;
	int i;
	clock_t start, end;
	double result;
	//freopen("mergesort2.txt", "r", stdin);
	//scanf("%d", &testN);
	//printf("testN(%d)\n", testN);
#if 0
	for (i = 0; i < testN; i++)
	{
		scanf("%d", &A[i].id);
		scanf("%d", &A[i].val);
		printf("%d %d\n", A[i].id, A[i].val);
	}
#endif
	testN = MAX_N;
	gen_input_data();
	start = clock();
	mergesort(0, testN - 1);
	end = clock ();
	result = (double)(end - start);
	printf("%f\n", result);

	//print_mergesort();
	return ret;
}

int gen_input_data(void)
{
	int ret = 0;
	int random1;
	int random2;
	int i;
	FILE *fp1 = fopen("abc.txt", "w+t");
	srand(time(NULL));

	for (i = 0; i < MAX_N; i++)
	{
		random1 = rand() % 100;
		random2 = rand() % 100;
		A[i].id = random1;
		A[i].val = random2;
		fprintf(fp1, "%d %d %d\n", i, A[i].id, A[i].val);
		//printf("i(%d), id(%d), val(%d)\n", A[i].id, A[i].val);
	}
	fclose(fp1);
	//printf("%d\n", random);

	return ret;
}

int print_mergesort(void)
{
	int ret = 0;
	int i = 0;

	for (i = 0; i < MAX_N; i++) {
		printf("i(%d), id(%d), val(%d)\n", i, A[i].id, A[i].val);
	}

	return ret;
}

#ifdef NORMAL
int compare_func(mystr_t in[], int i, int j)
{
	int ret = 0;

	if (in[i].val > in[j].val)
	{
		ret = 1;
	}

	return ret;
}
#endif

#ifdef TEST1
int compare_func(mystr_t in[], int i, int j)
{
	int ret = 0;

	if (in[i].val == in[j].val)
	{
		if (in[i].id < in[j].id)
		{
			ret = 1;
		}
	}
	else
	{
		if (in[i].val > in[j].val)
		{
			ret = 1;
		}
	}
	return ret;
}
#endif

int mergesort(int start, int end)
{
	int ret = 0;
	int i;
	int j;
	int k;
	int middle;

	middle = (start + end) / 2;
	i = start;
	j = middle + 1;
	k = start;

	if (start >= end)
	{
		return ret;
	}

	mergesort(start, middle);
	mergesort(middle + 1, end);

	while ((i <= middle) && (j <= end))
	{
		if (compare_func(A, i, j) == 1)
		{
			temp[k++] = A[i++];
		}
		else
		{
			temp[k++] = A[j++];
		}
	}

	while (i <= middle)
	{
		temp[k++] = A[i++];
	}

	while (j <= end)
	{
		temp[k++] = A[j++];
	}

	for (k = start; k <= end; k++)
	{
		A[k] = temp[k];
	}

	return ret;
}
