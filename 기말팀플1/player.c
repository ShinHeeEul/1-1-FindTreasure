#include "����.h"



char item_monster[50] = "��� �پ��!";
char item_jump[50] = "��� ������ �۷�?(����Ű Ŭ��!)";
char itemuse[50] = "����� ������ Ŭ��!(a=Jump s=Freeze)";

char item_jump_done[50] = " ��������!";
char noitem[50] = "  �������� �� ���� �Ф�";

int item_check(int *u_x, int *u_y, int *monster, int input_text[50], char prase1[50], char prase2[50], char prase3[50], int *jump_num, int *freeze_num);

int player(int M[][30], int *user_x, int* user_y, int* monster,int input_text[60],char prase1[60],char prase2[60],char prase3[60], int *jump_num, int *freeze_num, int *point){

	int ch = 0, i, u_x = *user_x, u_y = *user_y;
	int item = 1;

	gotoxy(2*(*user_x), *user_y);

	while (ch != 224 && ch != 105)
	{
		ch = _getch();
	}
		if (ch == 224)
			ch = _getch();
		switch (ch) {
		case 72:
			u_y--;
			break;
		case 80:
			u_y++;
			break;
		case 75:
			u_x--;
			break;
		case 77:
			u_x++;
			break;
		}

	if (ch == 105) {
		//ch = getch();
		item = 0;
	}
	if (!item) {
		strcpy(input_text, itemuse);
		text_print(input_text, prase1, prase2, prase3);

		item_check(&u_x, &u_y, monster, input_text, prase1, prase2, prase3,jump_num,freeze_num);
	
		strcpy(input_text, "�������� ����ϽǷ��� i�� �����ּ���");
		text_print(input_text, prase1, prase2, prase3);
	}
	item = 1;


	if (M[u_y][u_x] != '��')
	{
		printf(" ");
		*user_x = u_x;
		*user_y = u_y;
	}
	printf(" ");
	gotoxy(2*(*user_x), *user_y);
	printf("��");
	gotoxy(0, 0);

	*point += 1;
	return 0;


}


int item_check(int *u_x, int *u_y, int *monster, int input_text[50],char prase1[50], char prase2[50], char prase3[50],int *jump_num,int *freeze_num)
{
	int ch;
	ch = _getch();
	if (ch == 'a') {
		strcpy(input_text, item_jump);
		text_print(input_text, prase1, prase2, prase3);
		if (*jump_num < 1) {
			strcpy(input_text, noitem);
			text_print(input_text, prase1, prase2, prase3);
			return 0;
		}
		gotoxy(2*(*u_x), *u_y);
		printf(" ");
		_getch();
		ch = _getch();
		if (ch == 224)
			ch = _getch();
		switch (ch) {
		case 72:
			*u_y -= 2;
			break;
		case 80:
			*u_y += 2;
			break;
		case 75:
			*u_x -= 2;
			break;
		case 77:
			*u_x += 2;
			break;
		}
		strcpy(input_text, item_jump_done);
		text_print(input_text, prase1, prase2, prase3);
		(*jump_num)--;

	}
	else if (ch == 's') {
		//getch();
		if (*freeze_num < 1){
			strcpy(input_text, noitem);
			text_print(input_text, prase1, prase2, prase3);
			return 0;
		}
		strcpy(input_text, item_monster);
		text_print(input_text, prase1, prase2, prase3);
		(*monster) -= 4;
		(*freeze_num)--;
	}

}