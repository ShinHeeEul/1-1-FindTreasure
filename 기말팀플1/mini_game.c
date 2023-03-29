#include "팀플.h"

#define TRY 7
void clean_game(void);

int baseball_game(int M[][30], int player_x, int player_y, int *point) {
	int x=62, y=18;
	int player_num[4] = { 0, };
	int cum_num[4] = { 0, };	// 중복숫자 검사를 위해서 1로 초기화 하였습니다.
	int i_1, i_2, Try = 0, tmp;
	int ball = 0, strike = 0;

	for (i_1 = 0; i_1 < 4; i_1++) {
		cum_num[i_1] = 1 + rand() % 9;
	}
	// 1~9사이의 랜덤한숫자를 겹치지 않게 생성하는 코드입니다.
	while (cum_num[0] == cum_num[1])
		cum_num[1] = 1 + (rand() % 9);
	while ((cum_num[0] == cum_num[2]) || (cum_num[1] == cum_num[2]))
		cum_num[2] = 1 + (rand() % 9);
	while ((cum_num[0] == cum_num[3]) || (cum_num[1] == cum_num[3]) || (cum_num[2] == cum_num[3]))
		cum_num[3] = 1 + (rand() % 9);

			//컴퓨터 문자열을 확인하기 위한 코드
	//gotoxy(x, y);
	//y++;
	//for (i_1 = 0; i_1 < 4; i_1++) {
	//	printf("%d", cum_num[i_1]);
	//}
	//printf("\n");
	

	gotoxy(x, y);
	y++;
	printf("숫자야구 풀이공간");


	while (Try < TRY) {

		ball = 0;			// 볼과 스트라이크 카운트를 초기화 합니다.
		strike = 0;
		
		gotoxy(x, y);
		y++;
		printf("         (try %d)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", Try + 1);
		for (i_1 = 0; i_1 < 4; i_1++) {
			tmp = getchar();
			player_num[i_1] = tmp - '0';
		}
		tmp = getchar();				// 버퍼에 \n 제거용입니다.

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
			printf("정답입니다.  이동횟수 5회 추가! ");
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
	printf("실패!                               ");
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