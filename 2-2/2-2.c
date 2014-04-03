#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int total, k, size;

	int ***tree;
	int **contents;
	int i,j;
	int start;
	int x;

	FILE * fin = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");

	fscanf(fin, "%d %d", &total, &k);
	size = total / k;

	//int *tree[2*k] 의 형식... 1차원 포인터 배열..
	tree = (int ***)malloc(sizeof(int**) * (2*k));

	contents = (int**)malloc(sizeof(int*) * k);

	start = k;

	//집어 넣을 내용을 입력..
	//contents[0], contents[1],... 이 하나의 run.
	//pointer을 할때에는 contents[0]+1 이런식으로 가리키게 된다....
	for ( i = 0 ; i < k ; i ++ )
	{
		contents[i] = (int*)malloc(sizeof(int)*(size+1));
		for ( j = 0 ; j < size ; j ++ )
		{
			fscanf(fin, "%d", &contents[i][j]);
		}
		contents[i][5] = NULL;//추가로 끝을 알리는 곳에 NULL을 추가.
	}

	for ( i = start ; i < start * 2 ; i ++ )
	{
		tree[i] = &contents[i-start];
	}
	
	for ( j = 0 ; j < total ; j ++ )
	{
		start = k;//초기화.
		while(1)//1회 Winner Tree를 계산한다.
		{
			
			if(start == 1)
			{
				fprintf(out, "%d ", **tree[start]);
				(*tree[start])++;//최종 값이 있는 content[x]의 주소를 올려 그다음 값이 Winner Tree에 참가하도록 한다.
				break;
			}
			for ( i = start ; i < (start * 2) ; i += 2 )//level마다 연산한다.
			{
				if(**tree[i] == NULL)//NULL이 입력된 끝부분이면 그 content[x] RUN단위는 진행하지 않고 상대방이 부전승형식으로 올라간다.
				{
					tree[i/2] = tree[i+1];
				}
				else if(**tree[i+1] == NULL)
				{
					tree[i/2] = tree[i];					
				}
				else if (**tree[i] < **tree[i+1])//서로 NULL이 아니면 조건에 따라 parent부분에 주소를 삽입한다.
				{
					tree[i/2] = tree[i];
				}
				else if (**tree[i] >= **tree[i+1])
				{
					tree[i/2] = tree[i+1];
				}

			}
		
			start /= 2;//윗 level, parent level로 올라간다.
		}
	}

	
	

	free(tree);
	free(contents);
	fclose(fin);
	fclose(out);
}