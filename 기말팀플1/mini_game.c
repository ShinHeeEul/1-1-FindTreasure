#include "����.h"

#define TRY 7
void clean_game(void);

int baseball_game(int M[][30], int player_x, int player_y, int *point) {
	int x=62, y=18;
	int player_num[4] = { 0, };
	int cum_num[4] = { 0, };	// �ߺ����� �˻縦 ���ؼ� 1�� �ʱ�ȭ �Ͽ����ϴ�.
	int i_1, i_2, Try = 0, tmp;
	int ball = 0, strike = 0;

	for (i_1 = 0; i_1 < 4; i_1++) {
		cum_num[i_1] = 1 + rand() % 9;
	}
	// 1~9������ �����Ѽ��ڸ� ��ġ�� �ʰ� �����ϴ� �ڵ��Դϴ�.
	while (cum_num[0] == cum_num[1])
		cum_num[1] = 1 + (rand() % 9);
	while ((cum_num[0] == cum_num[2]) || (cum_num[1] == cum_num[2]))
		cum_num[2] = 1 + (rand() % 9);
	while ((cum_num[0] == cum_num[3]) || (cum_num[1] == cum_num[3]) || (cum_num[2] == cum_num[3]))
		cum_num[3] = 1 + (rand() % 9);

			//��ǻ�� ���ڿ��� Ȯ���ϱ� ���� �ڵ�
	//gotoxy(x, y);
	//y++;
	//for (i_1 = 0; i_1 < 4; i_1++) {
	//	printf("%d", cum_num[i_1]);
	//}
	//printf("\n");
	

	gotoxy(x, y);
	y++;
	printf("���ھ߱� Ǯ�̰���");


	while (Try < TRY) {

		ball = 0;			// ���� ��Ʈ����ũ ī��Ʈ�� �ʱ�ȭ �մϴ�.
		strike = 0;
		
		gotoxy(x, y);
		y++;
		printf("         (try %d)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", Try + 1);
		for (i_1 = 0; i_1 < 4; i_1++) {
			tmp = getchar();
			player_num[i_1] = tmp - '0';
		}
		tmp = getchar();				// ���ۿ� \n ���ſ��Դϴ�.

		for (i_1 = 0; i_1 < 4; i_1++)
			for (i_2 = 0; i_2 < 4; i_2++)
				if (cum_num[i_1] == player_num[i_2])
					ball++;
		for (i_1 = 0; i_1 < 4; i_1++) {
			if (cum_num[i_1] == player_num[i_1]) {
				strike++;
				ball--;
			}
		}
		if (strike == 4) {
			gotoxy(62, 19);
			y++;
			printf("�����Դϴ�.  �̵�Ƚ�� 5ȸ �߰�! ");
			clean_game();
			(*point) -= 5;
			return 1;
		}
		

		gotoxy(x, y);
		y++;
		printf("strike = %d  ball = %d", strike, ball);

		Try++;
	}

	gotoxy(62, 19);
	y++;
	printf("����!                               ");
	clean_game();

	return 0;
}

void clean_game(void) {
	int x1= 62, y1= 20, i;
	for (i = 0; i < 15; i++) {
		gotoxy(x1, y1);
		printf("                          ");
		y1++;
	}
	


}