#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "malloc.h"
#include <iostream>

using namespace std;

char *mystrcpy(char *dest, const char *src);
int mystrcmp(const char *dest, const char *src);

int main(void)
{
	int ret = 0;
	char *cret;
	char test1[15] = "abcd";
	char test2[15] = "efge";
	char test3[15] = "abcd";
	char dest1[15];
	char dest2[15];
	cret = strcpy(dest1, test1);
	printf("dest1(%s), test1(%s), cret(%s)\n", dest1, test1, cret);
	cret = mystrcpy(dest2, test2);
	printf("dest2(%s), test2(%s), cret(%s)\n", dest2, test2, cret);
	ret = strcmp(test1, test2);
	printf("ret1(%d)\n", ret);
	ret = strcmp(test1, test3);
	printf("ret2(%d)\n", ret);
	ret = mystrcmp(test1, test2);
	printf("ret3(%d)\n", ret);
	ret = mystrcmp(test1, test3);
	printf("ret4(%d)\n", ret);
	return ret;
}

char *mystrcpy(char *dest, const char *src)
{
	char *ret;
	int i = 0;
	int j = 0;
	
	while ( *(src+i) != '\0')
	{
		//printf("src[%d] = %c\n", i, src[i]);
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	ret = dest;	
	return ret;
}

int mystrcmp(const char *dest, const char *src)
{
	int ret = 0;
	int i = 0;	

	while (dest[i] != '\0' || src[i] != '\0')
	{
#if 0
		if (dest[i] > src[i])
		{
			ret = dest[i] - src[i];
			break;
		}
		else if (dest[i] < src[i])
		{
			ret = dest[i] - src[i];
			break;
		}
#endif
		if (dest[i] != src[i])
		{
			ret = dest[i] - src[i];
			break;
		}
		else if (dest[i] == src[i])
		{
			ret = 0;			
		}
		i++;
	}	
	return ret;
}