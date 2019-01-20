#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h.>

using namespace std;

#define MAX_TABLE 10

int arr_idx = 0;

struct NODE {
	char data[7];
	NODE *prev;
}a[20000];

NODE *myalloc(void)
{
	return &a[arr_idx++];
}
NODE *hTable[MAX_TABLE];

unsigned long myhash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
		//cout << "hash = " << hash << endl;
	}
	return hash % MAX_TABLE;
}

int main(void)
{
	freopen("hash_linkedlist1.txt", "r", stdin);
	// freopen("output.txt", "w", stdout)
	// for(int i = 0; i < 100; i++)
	// {
	//  for(int j = 0; j < 6; j++)
	//  cout << (char)(rand() % 26 + 'a');
	//  cout << endl;
	// }
	arr_idx = 0;
	for (int i = 0; i < MAX_TABLE; i++)
	{
		hTable[i] = NULL;
	}

	NODE *p;
	int key;
	char in[7];
	int test_case;
	cin >> test_case;
	cout << "test_case = " << test_case << endl;
	
	for (int T = 0; T < test_case; T++)
	{
		cin >> in;
		cout << "start, in " << in << endl;
		key = (int)myhash(in);
		cout << "Add to Hash table key = " << key << ":" << in << endl;
		p = myalloc();
		cout << "myalloc, p = " << hex << p << endl;
		strncpy(p->data, in, 7);
		//cout << "hTable[" << key << "] = " << hTable[key] << endl;
		printf("hTable[%d] = 0x%x, p->prev(0x%x)\n", key, hTable[key], p->prev);
		p->prev = hTable[key];
		cout << "p->prev = 0x" << hex << p->prev << endl;
		//printf("dongju1, hTable[%d] = 0x%x\n", key, hTable[key]);
		
		hTable[key] = p;
		printf("dongju2, hTable[%d] = 0x%x\n", key, hTable[key]);

		for (int _tKey = 0; _tKey < MAX_TABLE; _tKey++)
		{
			cout << "Hash table(" << _tKey << "):";
			for (NODE *pp = hTable[_tKey]; pp != NULL; pp = pp->prev)
			{
				cout << "" << pp->data << endl;
				cout << "pp = 0x" << hex << pp << endl;
				printf("pp->prev(0x%x)\n", pp->prev);
			}
			cout << endl;
		}
		cout << endl;
	}

	// Hash table
	char search[7] = "vrvipy";
	//char search[7] = "Essen";
	cout << "Searching : " << search << endl;

	int k = (int)myhash(search); // hash key
	cout << "Hash table key : " << k << endl;

	// hash table
	for (NODE *pp = hTable[k]; pp != NULL; pp = pp->prev)
	{
		cout << "pp->data = " << pp->data << endl;
		if (!strncmp(search, pp->data, 6))
			cout << "FOUND : " << pp->data << endl << endl;
	}

	NODE **del = &hTable[k];
	printf("k(%d)\n", k);
	cout << "del = 0x" << hex << del << endl;
	for (NODE *iter = hTable[k]; iter != NULL; iter = iter->prev)
	{
		if (!strncmp(search, iter->data, 6))
		{
			cout << "FOUND & DEL : " << iter->data << endl << endl;			
			*del = iter->prev;
		}
		printf("dongju1, del(0x%x), &iter->prev = 0x%x\n", del, &iter->prev);
		del = &iter->prev;
		printf("dongju2, del(0x%x), &iter->prev = 0x%x\n", del, &iter->prev);
	}
	cout << "Check delete" << endl;
	for (NODE *iter = hTable[k]; iter != NULL; iter = iter->prev)
	{
		printf("iter(0x%x), iter->prev(0x%x)\n", iter, iter->prev);
		if (!strncmp(search, iter->data, 6))
			cout << "FOUND : " << iter->data << endl << endl;
	}

	for (int _tKey = 0; _tKey < MAX_TABLE; _tKey++)
	{
		cout << "Hash table(" << _tKey << "):";
		for (NODE *pp = hTable[_tKey]; pp != NULL; pp = pp->prev)
		{
			cout << "pp->data = " << pp->data << endl;
			cout << "pp = 0x" << hex << pp << endl;
			printf("pp->prev(0x%x)\n", pp->prev);
		}
		cout << endl;
	}
}