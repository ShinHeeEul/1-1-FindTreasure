#include "����.h"

void outline(void);
void Level(const int L_y[4], int* level);
void script(char a[10], char b[10], char c[10], char d[10], char f[10], const int L_y[4]);
void game_exe(void);
void game_point(struct rank r[12]);

int sub_main(int* level, struct rank r[12])
{
	
	int i, ch = 0;
	const int L_y[5] = { 17, 19, 21, 23, 25 };
	i = 0;
	script("- �� �� ã �� -", "- ���� ����   ", "- ���̵� ���� ", "- ���� ����", "- ����   ", L_y);
	gotoxy(L_x, L_y[4]);
	printf("- ���� ����    ");
	while (1)
	{
		printf("\b ");
		gotoxy(L_x + 15, L_y[i]);
		printf("<");
		ch = _getch();

		if (ch == 224)
			ch = _getch();
		switch (ch) {
		case 72:
			if (i >= 0)
				i--;
			if (i < 0)
				i = 4;
			break;
		case 80:
			if (i <= 4)
				i++;
			if (i > 4)
				i = 0;
			break;
		}
		if (ch == 13)
		{
			if (!i)
			{
				return 1;
			}
			else if (i == 1)
			{
				Level(L_y, level);
				script("- �� �� ã �� -", "- ���� ����   ", "- ���̵� ���� ", "- ���� ����", "- ����   ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- ���� ����    ");
			}
			else if (i == 2)
			{
				game_exe();
				script("- �� �� ã �� -", "- ���� ����   ", "- ���̵� ���� ", "- ���� ����", "- ����    ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- ���� ����    ");
			}
			else if (i == 3)
			{
				game_point(r);
				script("- �� �� ã �� -", "- ���� ����   ", "- ���̵� ���� ", "- ���� ����", "- ����    ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- ���� ����    ");
			}
			else if (i == 4)
				return 0;
		}
	}
}

void outline(void)
{
	int i;
	printf("�������������������������������\n"); //30
	for (i = 0; i < 28; i++)
		printf("��                                                        ��\n");
	printf("�������������������������������\n");

}

void script(char a[10], char b[10], char c[10], char d[10], char f[10], const int L_y[4])
{
	system("cls");
	outline();
	gotoxy(L_x, 10);
	printf("%s", a);
	gotoxy(L_x, L_y[0]);
	printf("%s", b);
	gotoxy(L_x, L_y[1]);
	printf("%s", c);
	gotoxy(L_x, L_y[2]);
	printf("%s", d);
	gotoxy(L_x, L_y[3]);
	printf("%s", f);

}

void game_exe(void)
{
	int ch;
	system("cls");
	outline();
	gotoxy(3, 3);
	printf("- �� �� �� �� -");
	gotoxy(3, 5);
	printf("\t����� �i�ƿ��� ���͸� �پ��� ������� ���ذ���");
	gotoxy(3, 6);
	printf("\t�� ���� ����� �� ������ �����Դϴ�.");
	gotoxy(3, 7);
	printf("\t����� �����϶����� ������ 1���� �þ��");
	gotoxy(3, 8);
	printf("\t������ ���� ����� �� ���� ������ �����ϴ�.");
	gotoxy(3, 10);
	printf("\t**������ �� �����۵� �Ẹ����!");
	gotoxy(3, 11);
	printf("\t�������� iŰ�� ������ ����� �� ������, �߰���");
	gotoxy(3, 12);
	printf("\t���� �پ� ������ 2ĭ�� �̵��ϴ� \'����\'��");
	gotoxy(3, 13);
	printf("\t���͵��� �������� ���ߴ� \'����\'�� �ֽ��ϴ�.");
	gotoxy(3, 15);
	printf("- ĳ �� �� �� �� -");
	gotoxy(3, 16);
	printf("\t�� : �츮�� ���ΰ�, ����Դϴ�.");
	gotoxy(3, 17);
	printf("\t�� : ����� �i�ƿ��� �ؾǹ����� �����Դϴ�.");
	gotoxy(3, 18);
	printf("\t     ����ġ�� ���� ����� ����� �̸��Ե˴ϴ�.");
	gotoxy(3, 19);
	printf("\t�� : �����ϱ� ������ ���� ����ִ��� �𸣴�");
	gotoxy(3, 20);
	printf("\t��� �Դϴ�.������ ��, ����, �̴ϰ����� �ֽ��ϴ�.");
	gotoxy(3, 26);
	printf("\t\t\t\t\t����  <");
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
	}
	system("cls");
	outline();
	gotoxy(3, 3);
	printf("- �� �� �� �� -");
	gotoxy(3, 5);
	printf("\t�̴ϰ����� �̴� ���� ����� ������ ������ ���Ӽ�");
	gotoxy(3, 6);
	printf("\t�������� ������ \'���� �߱�\'�� �̷���� �ֽ��ϴ�.");
	gotoxy(3, 7);
	printf("\t���� �߱��� ��ǻ�Ͱ� ���Ƿ� ���� 4�ڸ� ���ڸ�");
	gotoxy(3, 8);
	printf("\t���ߴ� �����Դϴ�. �ϴ� ��ǻ�Ͱ� 0~9 �߿�");
	gotoxy(3, 9);
	printf("\t��ġ�� �ʰ� ������ ���� 4���� �̽��ϴ�.");
	gotoxy(3, 10);
	printf("\t�׸��� ����� 4�ڸ� ���ڸ� �Է��ϰ�,");
	gotoxy(3, 12);
	printf("\t���߿� ���� ���ڰ� ������ \'ball\',");
	gotoxy(3, 14);
	printf("\t�� ���ڰ� �ڸ����������� \'strike\'�Դϴ�.");
	gotoxy(3, 15);
	printf("\t�̰��� �ݺ��ϸ� ����� ���� �߸��س����� �˴ϴ�.");
	gotoxy(3, 17);
	printf("\tŬ��� �ϰ� �ȴٸ� ������ 5�� �پ��ϴ�.");
	gotoxy(3, 18);
	printf("\t���� Ŭ���� ���� ���ص� �������� �����ϴ�.");
	gotoxy(3, 19);
	printf("\t����� �߸��� �� �ִ� ��ȸ�� 7������ ���ѵ˴ϴ�.");
	gotoxy(3, 26);
	printf("\t\t\t\t����ȭ������ ���ư���  <");
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
	}
}
void Level(const int L_y[4], int* level)
{
	int ch = 0, i = *level;
	script("- ���̵� ���� -", "- ���� ", "- ���� ", "- ����� ", "- ��   " , L_y);

	while (1)
	{
		printf("\b ");
		gotoxy(L_x + 15, L_y[i - 1]);
		printf("<");
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch) {
		case 72:
			if(i >= 1)
				i--;
			if (i < 1)
				i = 4;
			break;
		case 80:
			if(i <= 4)
				i++;
			if (i > 4)
				i = 1;
			break;
		}
		if (ch == 13)
		{
			*level = i;
			break;
		}
	}
}


void game_point(struct rank r[12])
{
	char ch;
	int j;
	
	system("cls");
	outline();
	gotoxy(3, 3);
	printf("Rank  NAME      POINT     ");
	
	for (j = 0; j < 10; j++)
	{
		gotoxy(3, 4 + 2 * j);
		printf("%-6d%-10s%-10d",j + 1,r[j].name, r[j].point);
	}
	gotoxy(3, 26);
	printf("\t\t\t\t����ȭ������ ���ư���  <");
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
	}
}