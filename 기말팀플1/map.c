#include "팀플.h"

// 쉬움 : 레벨 1
// 보통 : 레벨 2
// 어려움 : 레벨 3
// 헬 : 레벨 4

// 기본 난이도 쉬움

// flag 생성 공식 = 
//	일반 깃발 : 2 * level
//	미니 게임 깃발 : 2 * level - 1
//	꽝 깃발 : level

// monster 생성 공식 = 2 * level

void map(int M[][30], int *player_x, int *player_y, int level, int *monster_x, int *monster_y) {

	int x, y;
	int i = 0;
	system("cls");

	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");//1
	printf("■                          ■                            ■\n");//2
	printf("■  ■■■■■■■■■■■  ■  ■■■■■■■■■■  ■  ■\n");//3
	printf("■  ■                      ■  ■                    ■  ■\n");//4
	printf("■  ■  ■■■■■■■■■  ■  ■  ■■■■■■■■  ■  ■\n");//5
	printf("■  ■                      ■  ■                    ■  ■\n");//6
	printf("■  ■  ■■■■■■■■■  ■  ■  ■■■■■■■■  ■  ■\n");//7
	printf("■  ■                                                    ■\n");//8
	printf("■  ■  ■■■■■■■■■■  ■■■■■■■■■■■■■  ■\n");//9
	printf("■                                                  ■■  ■\n");//10
	printf("■■  ■■■■  ■■■■■  ■■■■■  ■■■■■    ■  ■\n");//11
	printf("■                                              ■■      ■\n");//12
	printf("■  ■■■  ■■■■■  ■  ■■■  ■■■■■  ■■■■  ■\n");//13
	printf("■  ■                                                ■  ■\n");//14
	printf("■  ■  ■■■■■■■■■■  ■■■■■■■■■■■  ■  ■\n");//15
	printf("■  ■  ■■■■■■■■■■  ■■■■■■■■■■■  ■  ■\n");//16
	printf("■  ■                                                ■  ■\n");//17
	printf("■  ■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■  ■\n");//18
	printf("■      ■■                                              ■\n");//19
	printf("■  ■    ■■■■■  ■■■■■  ■■■■■  ■■■■  ■■\n");//20
	printf("■  ■■                                                  ■\n");//21
	printf("■  ■■■■■■■■■■■■■■■■■■■■■■■■  ■  ■\n");//22
	printf("■                                                    ■  ■\n");//23
	printf("■  ■  ■■■■■■■■  ■  ■  ■■■■■■■■■  ■  ■\n");//24
	printf("■  ■                    ■  ■                      ■  ■\n");//25
	printf("■  ■  ■■■■■■■■  ■  ■  ■■■■■■■■■  ■  ■\n");//26
	printf("■  ■                    ■  ■                      ■  ■\n");//27
	printf("■  ■  ■■■■■■■■■■  ■  ■■■■■■■■■■■  ■\n");//28
	printf("■                            ■                          ■\n");//29
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");//30
											   // ♥: 보물깃발 ♡:미니게임 ▷:꽝  ◆:플레이어 ◇:몬스터



											   // 깃발 생성
	for (i = 0; i < 2 * level; i++) {
		while (1) {
			x = rand() % 30;
			y = rand() % 30;
			if ((M[y][x] != '■') && (M[y][x] != '◆') && (M[y][x] != '♥')) {
				M[y][x] = '♥';
				gotoxy(2 * (x), y);
				printf("♥");
				break;
			}
		}
	}

	// 미니 게임깃발

	for (i = 0; i < 2 * level - 1; i++) {
		while (1) {
			x = rand() % 30;
			y = rand() % 30;
			if ((M[y][x] != '■') && (M[y][x] != '◆') && (M[y][x] != '♥') && (M[y][x] != '♡')) {
				M[y][x] = '♡';
				gotoxy(2 * (x), y);
				printf("♡");
				break;
			}
		}
	}

	// 꽝 깃발
	for (i = 0; i < level; i++) {
		while (1) {
			x = rand() % 30;
			y = rand() % 30;
			if ((M[y][x] != '■') && (M[y][x] != '◆') && (M[y][x] != '♥') && (M[y][x] != '♡') && (M[y][x] != '▷')) {
				M[y][x] = '▷';
				gotoxy(2 * (x), y);
				printf("♥");
				break;
			}
		}
	}
	// 몬스터
	for (i = 0; i < 2 * (level); i++) {
		while (1) {
			x = rand() % 30;
			y = rand() % 30;
			if ((M[y][x] != '■') && (M[y][x] != '◆') && (M[y][x] != '♥') && (M[y][x] != '♡') && (M[y][x] != '▷')) {
				monster_x[i] = x;
				monster_y[i] = y;
				M[y][x] = '◇';
				gotoxy(2 * (x), y);
				printf("◇");
				break;
			}
		}
	}




}