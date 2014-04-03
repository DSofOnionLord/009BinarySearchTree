#include<stdio.h>
#include<stdlib.h>

typedef struct raynor * list;

struct raynor
{
	int val;
	list sch;
	list bch;
};

//�Է� ����
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
			
			if( temp->val > pos->val)//�������� ���� ���� ��ġ�� ���� ū ���
			{
				if(!pos->bch)//������(ū ���� ����Ű�� Branch)�� ���� ������ �����ʿ� �ش� node����.
				{
					pos->bch = temp;
					break;
				}
				pos = pos->bch;//�̹� ������ ū������ �Ѿ��
			}
			else//�������� ���� ���� ��ġ�� ���� ���� ���
			{
				if(!pos->sch)//����(���� ���� ����Ű�� Branch)�� ���� ������ ���ʿ� �ش� node����.
				{
					pos->sch = temp;
					break;
				}
				pos = pos->sch;//�̹� ������ ���� ������ �Ѿ��
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

	//BST�� ����.
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