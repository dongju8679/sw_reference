#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

typedef struct _data_t
{	
	int id;
	int val;
	int key;
}data_t;

data_t data[10];


int check_low_true(data_t data[], int i, int pivot)
{
	int ret = 0;
	if (data[i].val >= data[pivot].val)
	{
		ret = 1;
	}
#if 0
	else if (data[i].val == data[pivot].val)
	{
		if (data[i].id < data[pivot].id)
		{
			ret = 1;
		}
	}
#endif
	return ret;
}

int check_high_true(data_t data[], int j, int pivot)
{
	int ret = 0;
	if (data[j].val < data[pivot].val)
	{
		ret = 1;
	}
	return ret;
}

void qsort(int first, int last, data_t data[])
{
	int pivot;
	int i;
	int j;
	data_t temp;
	printf("first(%d), last(%d)\n", first, last);

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (check_low_true(data, i, pivot) && i < last)
			{
				i++;
			}
			while (check_high_true(data, j, pivot))
			{
				j--;
			}
			if (i < j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}

		temp = data[pivot];
		data[pivot] = data[j];
		data[j] = temp;

		qsort(first, j - 1, data);
		qsort(j + 1, last, data);
	}
}

int print_array(data_t data[])
{
	int ret = 0;
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("sort(%d), val(%d), id(%d)\n", i, data[i].val, data[i].id);
	}
	return ret;
}

int main(void)
{
	int T;
	int test_case;
	int i;
	freopen("qsort_app1.txt", "r", stdin);
	scanf("%d", &T);
	printf("dongju start, T(%d)\n", T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &num);		
		for (i = 0; i < num; i++)
		{
			scanf("%d", &input[i]);
			data[i].val = input[i];
			data[i].id = i;
			printf("input(%d), val(%d), id(%d)\n", i, data[i].val, data[i].id);
		}
		qsort(0, num - 1, data);
		print_array(data);
	}
	return 0;
}