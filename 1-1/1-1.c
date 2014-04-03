#include<stdio.h>
#include<stdlib.h>

typedef struct raynor * list;

struct raynor
{
	int val;
	list sch;
	list bch;
};

//입력 받음
void input(list *y, list j, int val)
{
	list temp;
	list pos = (*y);
	if(!(*y)->val)
	{
		
		(*y)->val = val;
	}
	else
	{
		temp = (list)malloc(sizeof(*temp));
		temp->val = val;
		temp->bch = NULL;
		temp->sch = NULL;
		while(1)
		{
			
			if( temp->val > pos->val)//넣으려는 값이 현재 위치값 보다 큰 경우
			{
				if(!pos->bch)//오른쪽(큰 것을 가리키는 Branch)에 값이 없으면 오른쪽에 해당 node삽입.
				{
					pos->bch = temp;
					break;
				}
				pos = pos->bch;//이미 있으면 큰쪽으로 넘어간다
			}
			else//넣으려는 값이 현재 위치값 보다 작은 경우
			{
				if(!pos->sch)//왼쪽(작은 것을 가리키는 Branch)에 값이 없으면 왼쪽에 해당 node삽입.
				{
					pos->sch = temp;
					break;
				}
				pos = pos->sch;//이미 있으면 작은 쪽으로 넘어간다
			}
		}
	}
}

void inorder(list y, FILE * out)
{
	if(y)
	{
		inorder(y->sch, out);
		fprintf(out, "%d ", y->val);
		inorder(y->bch, out);
	}

}

int main()
{
	list y, j;
	int n, i, tmp;

	FILE * inp = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");

	fscanf(inp, "%d", &n);

	y = (list)malloc(sizeof(*y));
	y -> bch = NULL;
	y -> sch = NULL;
	y -> val = NULL;
	
	j = y;

	//BST에 삽입.
	for ( i = 0 ; i < n ; i ++ )
	{
		fscanf(inp, "%d", &tmp);
		input(&y, j, tmp);
	}

	//inorder(y, out);

	fclose(inp);
	fclose(out);
	return 0;
}