struct st
{
	int id;
	struct st * next;
}HEAD = { -1, NULL };

struct st * Insert(int d)
{
	// 코드설계
	struct st * p;
	struct st * head = &HEAD;
	while (head->next)
	{
		if (head->next->id > d) break;
		if (head->next->id == d)return 0;
		head = head->next;
	}
	p = (struct st *)calloc(1, sizeof(struct st));
	p->id = d;
	p->next = head->next;
	head->next = p;
	return p;

}

struct st * Delete(int d)
{
	// 코드설계

	struct st * head = &HEAD;
	struct st * temp;
	while (head->next)
	{
		if (head->next->id == d)
		{
			temp = head->next;
			head->next = head->next->next;
			return temp;
		}
		head = head->next;
	}
	return 0;
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지  

int main(void)
{
#define R (void *)1
#define N (void *)NULL

	int i;
	int oper[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, };
	int data[] = { 7, 2, 1, 5, 4, 7, 9, 9, 8, 1, 9, 7, 7, 3, 2, };
	void * res[] = { N, R, R, R, R, R, R, N, R, R, R, R, N, R, R, };
	int next[] = { -1, -1, 2, -1, 5, -1, -1, -1, 9, 2, -1, 8, -1, 4, 3, };
	struct st * r, *t;

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = Insert(data[i]);

			if (res[i] == NULL)
			{
				if (r != NULL)
				{
					printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
					return 0;
				}

				else
				{
					printf("return => 0x%.8X\n", r);
				}
			}

			else
			{
				t = &HEAD;
				printf("LINK : ");

				for (;;)
				{
					if (t->next == NULL)
					{
						if (t->id == -1) printf("HEAD\n", t->id);
						else printf("%d(LAST)\n", t->id);
						break;
					}

					else
					{
						if (t->id == -1) printf("HEAD -> ", t->id);
						else printf("%d -> ", t->id);
						t = t->next;
					}
				}

				if ((r->next == NULL) && (next[i] != -1))
				{
					printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
				}

				else
				{
					if ((r->next == NULL) && (next[i] == -1))
					{
						printf("id => %d, next => NULL\n", r->id);
					}

					else if (next[i] != r->next->id)
					{
						printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n ", next[i], r->next->id);
						return 0;
					}

					else
					{
						printf("next link ID => %d\n", r->next->id);

						if (r->id != data[i])
						{
							printf(">>>>Fail: Expected inserted ID => %d, Your inserted ID => %d\n", data[i], r->id);
							return 0;
						}

						else
						{
							printf("inserted ID => %d\n", r->id);
						}
					}
				}
			}
		}

		else
		{
			r = Delete(data[i]);

			if (res[i] == NULL)
			{
				if (r != NULL)
				{
					printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
					return 0;
				}

				else
				{
					printf("return => 0x%.8X\n", r);
				}
			}

			else
			{
				t = &HEAD;
				printf("LINK : ");

				for (;;)
				{
					if (t->next == NULL)
					{
						if (t->id == -1) printf("HEAD\n", t->id);
						else printf("%d(LAST)\n", t->id);
						break;
					}

					else
					{
						if (t->id == -1) printf("HEAD -> ", t->id);
						else printf("%d -> ", t->id);
						t = t->next;
					}
				}

				if ((r->next == NULL) && (next[i] != -1))
				{
					printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
				}

				else
				{
					if ((r->next == NULL) && (next[i] == -1))
					{
						printf("id => %d, next => NULL\n", r->id);
					}

					else if (next[i] != r->next->id)
					{
						printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n", next[i], r->next->id);
						return 0;
					}

					else
					{
						printf("next link ID => %d\n", r->next->id);

						if (r->id != data[i])
						{
							printf(">>>>Fail: Expected deleted ID => %d, Your deleted ID => %d\n", data[i], r->id);
							return 0;
						}

						else
						{
							printf("deleted ID => %d\n", r->id);
							free(r);
						}
					}
				}
			}
		}
	}

	return 1;
}