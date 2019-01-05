#define _CRT_SECURE_NO_WARNINGS
#define DDD
#ifdef DDD
#include <stdio.h>
#endif

#define MAX_X 100
#define MAX_Y 100

int X;
int Y;
int sx;
int sy;
int ex;
int ey;

int map[MAX_X + 5][MAX_Y + 5];
int visit[MAX_X + 5][MAX_Y + 5];

typedef struct _que_t{
	int x;
	int y;
	int cnt;
}que_t;

int front;
int rear;
que_t Q[MAX_X * MAX_Y + 100];

#if 0
int print_map()
{
	int i, j;
	int ret = 0;
	for (j = 1; j <= Y; j++)
	{
		for (i = 1; i <= X; i++)
		{
			printf("%d", map[j][i]);
		}
		printf("\n");
	}
	return ret;
}
#endif

int init()
{
	int ret = 0;
	int i, j;
	front = 0;
	rear = 0;
	for (j = 0; j <= Y; j++)
	{
		for (i = 0; i <= X; i++)
		{
			visit[j][i] = 0;
		}
	}
	return ret;
}

que_t deq(void)
{
	que_t ret;
	ret.x = Q[rear].x;
	ret.y = Q[rear].y;
	ret.cnt = Q[rear].cnt;
	rear++;
	return ret;
}

int enq(que_t tmp)
{
	int ret = 0;
	if (map[tmp.y][tmp.x] == 0)
	{
		goto exit;
	}
	if (visit[tmp.y][tmp.x] == 1)
	{
		goto exit;
	}	
	Q[front].x = tmp.x;
	Q[front].y = tmp.y;
	Q[front].cnt = tmp.cnt;
	front++;
	//printf("front(%d)\n", front);
exit:
	return ret;
}

int BFS(void)
{
	int ret = 0;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };	
	int di;	

	Q[front].x = sx;
	Q[front].y = sy;
	Q[front].cnt = 0;	
	front++;
	visit[sy][sx] = 1;
	//printf("front(%d), rear(%d)\n", front, rear);

	while (rear < front)
	{
		que_t tmp = deq();		
		//printf("cur_xycnt(%d/%d/%d), map(%d), rear(%d), front(%d)\n", tmp.x, tmp.y, tmp.cnt, map[tmp.y][tmp.x], rear, front);		
		visit[tmp.y][tmp.x] = 1;

		for (di = 0; di < 4; di++)
		{
			que_t new1;
			new1.x = tmp.x + dx[di];
			new1.y = tmp.y + dy[di];
			new1.cnt = tmp.cnt + 1;			
			//printf("xycnt(%d/%d/%d), di(%d), cur(%d/%d)\n", new1.x, new1.y, new1.cnt, di, tmp.x, tmp.y);			
			if (new1.x == ex && new1.y == ey)
			{
				ret = new1.cnt;
				//printf("ret(%d), new1(%d/%d)\n", ret, new1.x, new1.y);
				return ret;
			}
			enq(new1);				
		}		
	}
	//printf("ret(%d)\n", ret);
	return ret;
}

int main(void)
{
	int ret = 0;
	int i, j;	
	//freopen("miro.txt", "r", stdin);	
	setbuf(stdout, NULL);
	scanf("%d %d", &X, &Y);
	//printf("X(%d), Y(%d)\n", X, Y);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	//printf("start(%d %d), end(%d %d)\n", sx, sy, ex, ey);
	for (j = 1; j <= Y; j++)
	{
		for (i = 1; i <= X; i++)
		{
			scanf("%1d", &map[j][i]);
			map[j][i] = map[j][i] ^ 1;
		}
	}
#ifdef DDD
	//print_map();
#endif
	init();	

	if (sx == ex && sy == ey)
	{
		ret = 0;
		return ret;
	}

	ret = BFS();
	printf("%d\n", ret);
	
	return ret;
}