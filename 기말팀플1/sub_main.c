#include "팀플.h"

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
	script("- 보 물 찾 기 -", "- 게임 시작   ", "- 난이도 설정 ", "- 게임 설명", "- 점수   ", L_y);
	gotoxy(L_x, L_y[4]);
	printf("- 게임 종료    ");
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
				script("- 보 물 찾 기 -", "- 게임 시작   ", "- 난이도 설정 ", "- 게임 설명", "- 점수   ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- 게임 종료    ");
			}
			else if (i == 2)
			{
				game_exe();
				script("- 보 물 찾 기 -", "- 게임 시작   ", "- 난이도 설정 ", "- 게임 설명", "- 점수    ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- 게임 종료    ");
			}
			else if (i == 3)
			{
				game_point(r);
				script("- 보 물 찾 기 -", "- 게임 시작   ", "- 난이도 설정 ", "- 게임 설명", "- 점수    ", L_y);
				gotoxy(L_x, L_y[4]);
				printf("- 게임 종료    ");
			}
			else if (i == 4)
				return 0;
		}
	}
}

void outline(void)
{
	int i;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); //30
	for (i = 0; i < 28; i++)
		printf("■                                                        ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

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
	printf("- 게 임 설 명 -");
	gotoxy(3, 5);
	printf("\t당신을 쫒아오는 몬스터를 다양한 방법으로 피해가면");
	gotoxy(3, 6);
	printf("\t서 보물 깃발을 다 모으는 게임입니다.");
	gotoxy(3, 7);
	printf("\t당신이 움직일때마다 점수가 1점씩 늘어나며");
	gotoxy(3, 8);
	printf("\t점수가 적은 사람이 더 높은 순위를 가집니다.");
	gotoxy(3, 10);
	printf("\t**위험할 땐 아이템도 써보세요!");
	gotoxy(3, 11);
	printf("\t아이템은 i키를 눌러서 사용할 수 있으며, 견고한");
	gotoxy(3, 12);
	printf("\t벽도 뛰어 넘으며 2칸씩 이동하는 \'점프\'와");
	gotoxy(3, 13);
	printf("\t몬스터들의 움직임을 멈추는 \'스턴\'이 있습니다.");
	gotoxy(3, 15);
	printf("- 캐 랙 터 설 명 -");
	gotoxy(3, 16);
	printf("\t◆ : 우리의 주인공, 당신입니다.");
	gotoxy(3, 17);
	printf("\t◇ : 당신을 쫒아오는 극악무도한 몬스터입니다.");
	gotoxy(3, 18);
	printf("\t     마주치는 순간 당신은 사망에 이르게됩니다.");
	gotoxy(3, 19);
	printf("\t♥ : 도착하기 전까진 뭐가 들어있는지 모르는");
	gotoxy(3, 20);
	printf("\t깃발 입니다.종류는 꽝, 보물, 미니게임이 있습니다.");
	gotoxy(3, 26);
	printf("\t\t\t\t\t다음  <");
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
	printf("- 미 니 게 임 -");
	gotoxy(3, 5);
	printf("\t미니게임은 미니 게임 깃발을 먹으면 나오는 게임속");
	gotoxy(3, 6);
	printf("\t게임으로 간단한 \'숫자 야구\'로 이루어져 있습니다.");
	gotoxy(3, 7);
	printf("\t숫자 야구는 컴퓨터가 임의로 뽑은 4자리 숫자를");
	gotoxy(3, 8);
	printf("\t맞추는 게임입니다. 일단 컴퓨터가 0~9 중에");
	gotoxy(3, 9);
	printf("\t겹치지 않게 랜덤한 숫자 4개를 뽑습니다.");
	gotoxy(3, 10);
	printf("\t그리고 당신이 4자리 숫자를 입력하고,");
	gotoxy(3, 12);
	printf("\t답중에 같은 숫자가 있으면 \'ball\',");
	gotoxy(3, 14);
	printf("\t그 숫자가 자리까지같으면 \'strike\'입니다.");
	gotoxy(3, 15);
	printf("\t이것을 반복하며 당신은 답을 추리해나가면 됩니다.");
	gotoxy(3, 17);
	printf("\t클리어를 하게 된다면 점수가 5점 줄어듭니다.");
	gotoxy(3, 18);
	printf("\t또한 클리어 하지 못해도 불이익은 없습니다.");
	gotoxy(3, 19);
	printf("\t당신이 추리할 수 있는 기회는 7번으로 제한됩니다.");
	gotoxy(3, 26);
	printf("\t\t\t\t메인화면으로 돌아가기  <");
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
	script("- 난이도 조정 -", "- 쉬움 ", "- 보통 ", "- 어려움 ", "- 헬   " , L_y);

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
	printf("\t\t\t\t메인화면으로 돌아가기  <");
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
	}
}