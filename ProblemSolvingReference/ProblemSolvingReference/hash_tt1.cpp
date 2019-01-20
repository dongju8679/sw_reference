#include <stdio.h>
#include <iostream>
#include "malloc.h"

#define MAX_TABLE 10

using namespace std;

unsigned long myhash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}

int mystrcmp(const char *strA, const char *strB)
{
	int i;
	int ret = 0;
	for (i = 0; strA[i] != '\0' ; i++)
	{
		if (strA[i] == strB[i])
		{
			return 0;
		}
		else if (strA[i] > strB[i])
		{
			return strA[i] - strB[i];
		}
		else if (strA[i] < strB[i])
		{
			return strB[i] - strA[i];
		}
	}
	return ret;
}

int main(void)
{
	int ret = 0;
	printf("dongju start\n");

	return ret;
}