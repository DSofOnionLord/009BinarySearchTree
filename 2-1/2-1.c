#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int total, k, size;

	int **tree;
	int **contents;
	int i,j;
	int start;
	

	FILE * fin = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");

	fscanf(fin, "%d %d", &total, &k);
	size = total / k;

	//int *tree[2*k] �� ����... 1���� ������ �迭..
	tree = (int **)malloc(sizeof(int*) * (2*k));

	contents = (int**)malloc(sizeof(int*) * k);

	start = k;

	//���� ���� ������ �Է�..
	//contents[0], contents[1],... �� �ϳ��� run.
	//pointer�� �Ҷ����� contents[0]+1 �̷������� ����Ű�� �ȴ�....
	for ( i = 0 ; i < k ; i ++ )
	{
		contents[i] = (int*)malloc(sizeof(int)*size);
		for ( j = 0 ; j < size ; j ++ )
		{
			fscanf(fin, "%d", &contents[i][j]);
		}
	}

	for ( i = start ; i < start * 2 ; i ++ )
	{
		tree[i] = contents[i-start];
	}
	
	while(1)//1ȸ Winner Tree�� ����Ѵ�.
	{
		if(start == 1)
		{
			break;
		}
		for ( i = start ; i < (start * 2) ; i += 2 )//level���� �����Ѵ�.
		{
			if ( *tree[i] < *tree[i+1])//���ǿ� ���� parent�κп� �ּҸ� �����Ѵ�.
			{
				tree[i/2] = tree[i];
			}
			else
			{
				tree[i/2] = tree[i+1];
			}
		}
		
		start /= 2;//�� level, parent level�� �ö󰣴�.
	}
	
	for ( i  = k/2 ; i < k ; i ++ )//���ÿ��� 4,5,6,7
	{
		fprintf(out, "Node #%d : %d\n", i, *(tree[i]));
	}
	
	

	free(tree);
	free(contents);
	fclose(fin);
	fclose(out);
}