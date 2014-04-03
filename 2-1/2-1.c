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

	//int *tree[2*k] 의 형식... 1차원 포인터 배열..
	tree = (int **)malloc(sizeof(int*) * (2*k));

	contents = (int**)malloc(sizeof(int*) * k);

	start = k;

	//집어 넣을 내용을 입력..
	//contents[0], contents[1],... 이 하나의 run.
	//pointer을 할때에는 contents[0]+1 이런식으로 가리키게 된다....
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
	
	while(1)//1회 Winner Tree를 계산한다.
	{
		if(start == 1)
		{
			break;
		}
		for ( i = start ; i < (start * 2) ; i += 2 )//level마다 연산한다.
		{
			if ( *tree[i] < *tree[i+1])//조건에 따라 parent부분에 주소를 삽입한다.
			{
				tree[i/2] = tree[i];
			}
			else
			{
				tree[i/2] = tree[i+1];
			}
		}
		
		start /= 2;//윗 level, parent level로 올라간다.
	}
	
	for ( i  = k/2 ; i < k ; i ++ )//예시에서 4,5,6,7
	{
		fprintf(out, "Node #%d : %d\n", i, *(tree[i]));
	}
	
	

	free(tree);
	free(contents);
	fclose(fin);
	fclose(out);
}