#include"팀플.h"


int monster(int M[][30], int *player_x, int *player_y, int level, int *monster_x, int *monster_y) {
	int i = 0;
	int x, y;
	int I_x, I_y;
		while (i < 2*(level)) {
			gotoxy(2 * (monster_x[i]), monster_y[i]);		// 원래 표시되었던 몬스터 지웠습니다.
			
			printf("  ");
			//gotoxy(2 * (monster_x[i]), monster_y[i]);
			switch (M[monster_y[i]][monster_x[i]]) {		// 깃발 위치에 몬스터가 간경우 깃발을 다시 출력하기위해서 switch문을 이용했습니다.
			case '♥':
				printf("♥");
				M[monster_y[i]][monster_x[i]] = '♥';		// 몬스터끼리 겹치는 경우를 체크하기 위해서 배열 M을
				break;										// 이용했기 때문에 다시 깃발로 초기화해줌
			case '♡':
				printf("♥");
				M[monster_y[i]][monster_x[i]] = '♡';
				break;
			case '▷':
				printf("♥");
				M[monster_y[i]][monster_x[i]] = '▷';
				break;
			case '◇':
				M[monster_y[i]][monster_x[i]] = '  ';		// 마찬가지로 빈칸으로 초기화 해줌
				break;
			}
			// ♥: 보물깃발 ♡:미니게임 ▷:꽝  ◆:플레이어 ◇:몬스터

			I_x = monster_x[i];
			I_y = monster_y[i];

			x = abs(*player_x - monster_x[i]);			// 몬스터와 플래이어의 거리를 이용하여 
			y = abs(*player_y - monster_y[i]);			// 난이도 조절에 이용하였습니다.
				if ((x <= 5 + level) || (y <= 5 + level)) {			// 플래이어와 몬스터가 가까워지면 추격을 시작합니다.
					if (rand() % 2) {
						if (*player_x > monster_x[i]) {						// 몬스터가 움직이는 알고리즘은 모두 똑같습니다.
							monster_x[i] ++;
							if (M[monster_y[i]][monster_x[i]] == '■')		// 벽을통과하지못하며
								monster_x[i] --;
							else if (M[monster_y[i]][monster_x[i]] == '◇')	// 겹치지 못하도록 코딩하였습니다.
								monster_x[i] --;
						}
						else if (*player_x < monster_x[i]) {
							monster_x[i] --;
							if (M[monster_y[i]][monster_x[i]] == '■')
								monster_x[i] ++;
							else if (M[monster_y[i]][monster_x[i]] == '◇')
								monster_x[i] ++;
						}
					}
					else {
						if (*player_y > monster_y[i]) {
							monster_y[i]++;
							if (M[monster_y[i]][monster_x[i]] == '■')
								monster_y[i]--;
							else if (M[monster_y[i]][monster_x[i]] == '◇')
								monster_y[i] --;
						}
						else if (*player_y < monster_y[i]) {
							monster_y[i]--;
							if (M[monster_y[i]][monster_x[i]] == '■')
								monster_y[i]++;
							else if (M[monster_y[i]][monster_x[i]] == '◇')
								monster_y[i]++;
						}
					}
				}
				else {									// 거리가 멀면 랜덤하게 움직입니다.
					switch (rand() % 4) {
					case 0:
						monster_x[i] ++;
						if (M[monster_y[i]][monster_x[i]] == '■')
							monster_x[i] --;
						else if (M[monster_y[i]][monster_x[i]] == '◇')
							monster_x[i] --;
						break;
					case 1:
						monster_x[i] --;
						if (M[monster_y[i]][monster_x[i]] == '■')
							monster_x[i] ++;
						else if (M[monster_y[i]][monster_x[i]] == '◇')
							monster_x[i] --;
						break;
					case 2:
						monster_y[i]++;
						if (M[monster_y[i]][monster_x[i]] == '■')
							monster_y[i]--;
						else if (M[monster_y[i]][monster_x[i]] == '◇')
							monster_y[i]--;
						break;
					case 3:
						monster_y[i]--;
						if (M[monster_y[i]][monster_x[i]] == '■')
							monster_y[i]++;
						else if (M[monster_y[i]][monster_x[i]] == '◇')
							monster_y[i]++;
						break;
					}
				}
			gotoxy(2 * (monster_x[i]), monster_y[i]);
			printf("◇");
			if (M[monster_y[i]][monster_x[i]] == '  ')
				M[monster_y[i]][monster_x[i]] = '◇';
			if ((monster_x[i] == *player_x) && (monster_y[i] == *player_y))
				return 1;
			
			i++;
			
		}
	
	return 0;
}