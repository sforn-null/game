#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initboard(char board[row][col], int r, int c) 
{
	int i = 0;
	int j = 0;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//代码比较局限，无法改变打印的列
//void DisplayBoard(char board[row][col], int r, int c)
//{
//	int i = 0;
//	for (i = 0;i < r;i++)
//	{
//		//1.打印一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//2.打印分割行
//		if(i<row-1)
//		printf("---|---|---\n");
//	}
//}
void DisplayBoard(char board[row][col], int r, int c)
{
	int i = 0;
	for (i = 0;i < r;i++)
	{
		//1.打印一行的数据
		int j = 0;
		for (j = 0;j < c;j++) 
		{
			printf(" %c ", board[i][j]);
			if(j<c-1)
			printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0;j < c;j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void playermove(char board[row][col], int r, int c)
{
	int x = 0;
	int y = 0;
	printf("玩家走:\n");
	while (1)
	{
		printf("请输入要下的坐标:");
		scanf("%d%d", &x, &y);
		//判断x，y坐标的合法性
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void computermove(char board[row][col], int r, int c)
{
	int x;
	int y;
	printf("电脑走:\n");
	
	while (1)
	{	
		x = rand() % r;
	    y = rand() % c;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

char iswin(char board[row][col], int r, int c)
{
	int i;
	for (i = 0;i < r;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
		{
			return board[i][0];
	}
	}
	for (i = 0;i < c;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[2][0];
	//判断是否平局
	if (1 == isfull(board, row, col))
	{
		return 'a';
	}
	return 'b';
}

int isfull(char board[row][col], int r, int c)
{
	int i;
	int j;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

