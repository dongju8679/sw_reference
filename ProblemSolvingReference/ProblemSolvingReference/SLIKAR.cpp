/*  SLIKAR  */
#include <stdio.h>
struct Queue
{
	int y, x, time, type;
}q[50 * 50];
int wp, rp;
char map[60][60];
int Y, X, T;
#define FLOOD   '*'
#define ARTIST  'S'
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int bfs(void)
{
	struct Queue ndata, data;

	while (wp > rp)
	{
		data = q[rp++];
		ndata = data;

		for (int i = 0; i < 4; i++)
		{
			ndata.y = data.y + dy[i]; ndata.x = data.x + dx[i];
			if (map[ndata.y][ndata.x] == '.')
			{
				map[ndata.y][ndata.x] = 'X';
				ndata.time = data.time + 1;
				q[wp++] = ndata;
			}
			if ((map[ndata.y][ndata.x] == 'D') && (data.type == 'S'))
			{
				return data.time + 1;
			}
		}
	}
	return -1;
}
int main(void)
{
	struct Queue data, start;
	int sy, sx;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &Y, &X);

		wp = rp = 0;
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				map[i][j] = 0;

		for (int i = 1; i <= Y; i++)
		{
			scanf("%s", &map[i][1]);
			for (int j = 1; j <= X; j++)
			{
				if (map[i][j] == '*')
				{
					data.y = i; data.x = j; data.time = 0;
					data.type = map[i][j];
					q[wp++] = data;
				}
				else if (map[i][j] == 'S')
				{
					start.y = i; start.x = j; start.time = 0;
					start.type = map[i][j];
				}
			}
		}
		q[wp++] = start;

		int sol = bfs();
		if (sol == -1)printf("KAKTUS\n");
		else printf("%d\n", sol);

	}
	return 0;
}
/**************************************************************
Problem: 2609
User: AXQ4455
Language: C++
Result: Accepted
Time:0 ms
Memory:1124 kb
****************************************************************/
