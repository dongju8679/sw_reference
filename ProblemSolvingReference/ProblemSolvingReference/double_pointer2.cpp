#include <stdio.h>
#include "malloc.h"

using namespace std;

struct _data_t
{
	int key;
	int data;
	data_t **pp;
};

typedef struct _data_t data_t;

data_t gd1;

int main(void)
{
	int ret = 0;
	data_t dd1;
	data_t dd2;
	data_t *pd1 = &dd1;
	data_t *pd2 = &dd2;
	data_t *pp3 = (data_t *)malloc(sizeof(data_t));

	data_t *pdat1 = (data_t *)malloc(sizeof(data_t));
	
	gd1.pp = &pp3;

	free(pdat1);	
	free(pp3);

	return ret;
}