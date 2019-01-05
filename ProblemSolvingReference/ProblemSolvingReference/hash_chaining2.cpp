/***********************************************************/
// [2-2.9] Hash Table => Chainning 방법의 구현
/***********************************************************/

#if 0

/***********************************************************/
// [2-2.9] Hash Table을 위한 기본 함수들
/***********************************************************/

#if 0

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score * next;
}SCORE;

#define MAX_ST      20
#define HASH_KEY    5

SCORE Hash_table[HASH_KEY];



int Create_Data(SCORE * p);
int Get_Hash_Key(int id);
void Init_Hash_Table(void);
void Print_All_Data(void);
int Insert_Data(SCORE * d);
SCORE * Search_Data(int id);
int Delete_Data(int id);

SCORE test[MAX_ST + 2] = { { 10, 50, "kim" },{ 2, 80, "lew" },{ 8, 50, "lew" },{ 4, 45, "lee" },{ 1, 90, "song" }, \
{3, 45, "kim"},{ 5, 50, "song" },{ 9, 100, "lee" },{ 7, 75, "moon" },{ 6, 90, "park" }, \
{15, 90, "ki"},{ 11, 20, "kong" },{ 14, 40, "shin" },{ 12, 50, "son" },{ 17, 48, "lee" }, \
{20, 100, "min"},{ 19, 80, "you" },{ 13, 45, "song" },{ 16, 54, "no" },{ 18, 100, "yang" }, \
{21, 58, "seo"},{ 23, 88, "oh" } };

int Create_Data(SCORE * p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}

int Get_Hash_Key(int id)
{
	return id % HASH_KEY;
}

void Init_Hash_Table(void)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
		Hash_table[i].next = (SCORE *)0;
	}
}

void Print_All_Data(void)
{
	int i;
	SCORE * p;

	for (i = 0; i<MAX_ST; i++)
	{
		p = Hash_table[i].next;

		for (;;)
		{
			if (p == (SCORE *)0) break;
			printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
			p = p->next;
		}
	}
}

#endif

/***********************************************************/
// [2-2.10] Insert
/***********************************************************/

#if 0

int Insert_Data(SCORE * d)
{
	SCORE * p;
	SCORE * q;

	p = &Hash_table[Get_Hash_Key(d->id)];
	q = calloc(1, sizeof(SCORE));
	if (q == (void *)0) return -1;
	*q = *d;

	for (;;)
	{
		if (p->next == (SCORE *)0) break;
		p = p->next;
	}

	p->next = q;
	q->next = (SCORE *)0;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i<MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
		Print_All_Data();
	}
}

#endif

/***********************************************************/
// [2-2.11] Delete
/***********************************************************/

#if 0

int Delete_Data(int id)
{
	SCORE * p;
	SCORE * prev;

	prev = &Hash_table[Get_Hash_Key(id)];
	p = prev->next;

	for (;;)
	{
		if (p->id == id)
		{
			prev->next = p->next;
			free(p);
			return 1;
		}

		if (p->next == (SCORE *)0) return -1;

		prev = p;
		p = p->next;
	}
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	Init_Hash_Table();

	for (i = 0; i<MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("[1] Delete Result=%d\n", r = Delete_Data(1));
	printf("[11] Delete Result=%d\n", r = Delete_Data(11));
	printf("[16] Delete Result=%d\n", r = Delete_Data(16));
	printf("[9] Delete Result=%d\n", r = Delete_Data(9));
	printf("[10] Delete Result=%d\n", r = Delete_Data(10));
	Print_All_Data();

	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[1]), test[1].id);
	printf("Inserted Position=%d, ID=%d\n", r = Insert_Data(&test[11]), test[11].id);
	Print_All_Data();
}

#endif

/***********************************************************/
// [2-2.12] Search
/***********************************************************/

#if 0

SCORE * Search_Data(int id)
{
	SCORE * p;

	p = Hash_table[Get_Hash_Key(id)].next;

	for (;;)
	{
		if (p->id == id) return p;
		if (p->next == (SCORE *)0) return (SCORE *)0;
		p = p->next;
	}
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	Init_Hash_Table();

	for (i = 0; i<MAX_ST; i++) printf("[Loop: %d] Insert Result=%d, ID=%d\n", i, r = Insert_Data(&test[i]), test[i].id);
	Print_All_Data();

	printf("Serch Result=0x%.8X\n", p = Search_Data(3));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(12));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
	printf("Serch Result=0x%.8X\n", p = Search_Data(25));
	if (p) printf("[%d] address:0x%.8X, ID: %d, NAME: %s, next: 0x%.8X\n", i, p, p->id, p->name, p->next);
}

#endif

#endif









/**************************************************************
Problem: 2910
User: AXQ4455
Language: C
Result: Compile Error
****************************************************************/
