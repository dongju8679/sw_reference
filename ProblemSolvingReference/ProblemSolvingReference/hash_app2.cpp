#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct
{
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;	
	printf("*str(0x%x, %c)\n", *str, *str);
	while (c = *str++)
	{
		printf("ch1, *str(0x%x, %c), hash(%ld), c(%c)\n", *str, *str, hash, c);
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
		printf("hash(%ld)\n", hash);
	}
	printf("hash(%ld), hash % MAX_TABLE = %ld\n", hash, hash % MAX_TABLE);
	return hash % MAX_TABLE;
}

int find(const char *key, char *data)
{
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			strcpy(data, tb[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int add(const char *key, char *data)
{
	printf("add, key(%s)\n", key);
	unsigned long h = hash(key);
	printf("h(%ld)\n", h);
	printf("dongju, tb[h].key[0] = 0x%x\n", tb[h].key[0]);
	while (tb[h].key[0] != 0)
	{		
		if (strcmp(tb[h].key, key) == 0)
		{
			return 0;
		}

		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	strcpy(tb[h].data, data);
	return 1;
}


int main(int argc, char* argv[])
{
	int T, N, Q;
	freopen("hash_app2.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	printf("T(%d)\n", T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		printf("sizeof(tb) = %d\n", sizeof(tb));
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for (int i = 0; i < N; i++)
		{
			scanf("%s %s\n", &k, &d);
			printf("key(%s), data(%s)\n", k, d);
			add(k, d);
		}

		printf("#%d\n", test_case);

		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s\n", &k);

			if (find(k, d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}