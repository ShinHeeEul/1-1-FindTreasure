#include "����.h"

void status_print(int jump_num, int freeze_num,int flag, int point) {

	int i = 0;
	int x_text = 60;
	int y_text = 0;

	gotoxy(x_text, y_text);
	printf("***********************************************************\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("***********************************************************\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("***********************************************************\n");
	// (i = 0; i < 10; i++) {
	y_text++;
	gotoxy(x_text, y_text);
	printf("**                                                       **\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("**����: %3d                                               **\n", point);
	y_text++;
	gotoxy(x_text, y_text);	//	printf("**�÷��� �ð� %-50s **\n", -time(NULL));
	printf("**                                                       **\n");
	y_text++;
	gotoxy(x_text, y_text);
		printf("**                                                       **\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("**���� ������ ����: %d ��                                **\n", jump_num);
	y_text++;
	gotoxy(x_text, y_text);
	printf("**                                                       **\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("**                                                       **\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("**���� ���� ������ ����:%d��                           **\n", freeze_num);
	y_text++;
	gotoxy(x_text, y_text);
	printf("**                                                       **\n");
	//printf("**                                                       **\n");
	y_text++;

	gotoxy(x_text, y_text);
	printf("**��� ���� %d                                           **\n",flag);
	//}	y_text++;
	y_text++;
	gotoxy(x_text, y_text);
	printf("**                                                       **\n");
	y_text++;

	gotoxy(x_text, y_text);
	printf("***********************************************************\n");
	y_text++;
	gotoxy(x_text, y_text);
	printf("***********************************************************\n");
	
}
