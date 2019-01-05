#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

typedef struct _data_t
{
	int id;
	int data;
	int key;
}data_t;

data_t data[MAX_SIZE];
data_t orig[MAX_SIZE];

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(data_t buf[], data_t value)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	printf("heapSize(%d)\n", heapSize);
	buf[heapSize].data = value.data;
	buf[heapSize].id = value.id;

	int current = heapSize;
	while (current > 0 && buf[current].data < buf[(current - 1) / 2].data)
	{
		data_t temp = buf[(current - 1) / 2];
		buf[(current - 1) / 2] = buf[current];
		buf[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(int *value)
{
	if (heapSize <= 0)
	{
		return -1;
	}

	*value = data[0].data;
	heapSize = heapSize - 1;

	data[0].data = data[heapSize].data;

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = data[current * 2 + 1].data < data[current * 2 + 2].data ? current * 2 + 1 : current * 2 + 2;
		}

		if (data[current].data < data[child].data)
		{
			break;
		}

		int temp = data[current].data;
		data[current].data = data[child].data;
		data[child].data = temp;

		current = child;
	}
	return 1;
}

int make_orig(data_t buf[], int i, int val)
{
	int ret = 0;
	buf[i].id = i;
	buf[i].data = val;
	return ret;
}

int main(int argc, char* argv[])
{
	int T, N;
	freopen("prio_queue2.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	printf("priority_queue start, T(%d)\n", T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		heapInit();
		
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			make_orig(orig, i, value);
			printf("orig, i(%d), id(%d), data(%d)\n", i, orig[i].id, orig[i].data);
			printf("data, i(%d), id(%d), data(%d)\n", i, data[i].id, data[i].data);
			heapPush(data, orig[i]);
		}		

		for (int i = 0; i < N; i++)
		{
			int value;
			heapPop(&value);
			printf("%d ", value);
		}
		printf("\n");
	}
	return 0;
}