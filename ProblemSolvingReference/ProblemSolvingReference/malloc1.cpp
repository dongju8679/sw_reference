#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "malloc.h"
#include <string.h>

int gN;
int cmdN;

enum
{
	ADD,
	DELETE,
	CHANGE,
	GET_USER,
};

enum
{
	INVALID,
	NORMAL,
	MASTER,
};

typedef struct _evt_t
{
	int state;
	int uid;
	char ename[15];
	struct _evt_t *prev;
	struct _evt_t *next;
}evt_t;

typedef struct _hash_t
{
	char key[15];
	struct _evt_t *next;
	int uniq;
}hash_t;

typedef struct _grp_t
{
	int gid;	
	int hash_cnt;
	hash_t hash[200];	
}grp_t;

grp_t grp[10];
grp_t *pgrp;

typedef struct _cmd_t
{
	int type;
	int group_num;
	char ename[15];
	int user_num;
}cmd_t;

cmd_t cmd[10];

int init(int uniq)
{
	int ret = 0;
	int i;
	int j;
	pgrp = (grp_t *)malloc(sizeof(grp_t) * gN);
	for (i = 0; i < gN; i++)
	{
		for (j = 0; j < 200; j++)
		{
			(pgrp + i)->hash[j].next = NULL;
			(pgrp + i)->hash_cnt = 0;			
		}
	}
	return ret;
}

int mystrcmp()
{
	int ret = 0;

	return ret;
}

int mystrcpy()
{
	int ret = 0;

	return ret;
}

int _check_master(int gid, char ename[])
{
	int ret = 0;
	int i = 0;
	int valid_hash_cnt = (pgrp + gid)->hash_cnt;	

	if (valid_hash_cnt == 0)
	{
		ret = 1;
		goto exit;
	}

	for (i = 0; i < 200; i++)
	{

	}	

exit:
	return ret;
}

int add(int idx)
{
	int ret = 0;
	evt_t *pevt;
	int group_idx = cmd[idx].group_num;
	//printf("add\n");	
	printf("%d %d %s\n", cmd[idx].group_num, cmd[idx].user_num, cmd[idx].ename);
	pevt = (evt_t *)malloc(sizeof(evt_t));
	pevt->uid = cmd[idx].user_num;
	strcpy(pevt->ename, cmd[idx].ename);
	if (_check_master(group_idx) == 1)
	{
		pevt->state = MASTER;
	}
	return ret;
}

int delete_()
{
	int ret = 0;

	return ret;
}

int get_user()
{
	int ret = 0;

	return ret;
}

int change()
{
	int ret = 0;


	return ret;
}

int main()
{
	int test_case;
	
	int i = 0;
	int ret = 0;
	freopen("malloc1.txt", "r", stdin);	
	setbuf(stdout, NULL);
	scanf("%d", &test_case);	
	scanf("%d", &gN);
	scanf("%d", &cmdN);
	for (i = 0; i < cmdN; i++)
	{
		scanf("%d %d %s %d", &cmd[i].type, &cmd[i].group_num, cmd[i].ename, &cmd[i].user_num);
		printf("%d %d %s %d\n", cmd[i].type, cmd[i].group_num, cmd[i].ename, cmd[i].user_num);
	}	
	
	init();

	for (i = 0; i < cmdN; i++)
	{
		int type = cmd[i].type;
		switch (type)
		{
		case ADD:
			ret = add(i);
			break;
		case DELETE:
			ret = delete_();
			break;
		case CHANGE:
			ret = change();
			break;
		case GET_USER:
			ret = get_user();
			break;
		}
	}
	free(pgrp);
}