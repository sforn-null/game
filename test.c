#define _CRT_SECURE_NO_WARNINGS 1

//������������Ϸ
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("*****************************\n");
	printf("*******1.play   0. exit******\n");
	printf("*****************************\n");
}
//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char board[row][col] = {0};//�տ�ʼϣ������ȫ�ǿո�
	//��ʼ������
	Initboard(board, row, col);
	//��ӡ����
	DisplayBoard(board, row, col);
	//����
	while (1)
	{
		//�������
		playermove(board, row, col);
		DisplayBoard(board, row, col);
		//�ж�����Ƿ�Ӯ
		ret = iswin(board,row,col);
		if (ret !='b')
		{
			break;
		}
		//��������
		computermove(board, row, col);
		DisplayBoard(board, row, col);
		//�жϵ����Ƿ�Ӯ
		ret = iswin(board,row,col);
		if (ret !='b')
		{
			break;
	     }
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			    game();
				break;
		case 0:
				printf("�˳���Ϸ");
				break;
		default:
				printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}