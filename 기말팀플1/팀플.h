#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS
#define L_x 32

struct rank {
	char name[3];
	int point;
};

void gotoxy(int x, int y);
int sub_main(int* level, struct rank r[12]);
void map( int M[][30], int *player_x, int *player_y, int level, int *monster_x, int *monster_y);
int player(int M[][30], int *user_x, int* user_y, int* monster, int input_text[60], char prase1[60], char prase2[60], char prase3[60], int *jump_num, int *freeze_num, int *point);
int flag(int M[][30], int *player_x, int *player_y, int *num_T, int input_text[50], char prase1[50], char prase2[50], char prase3[50], int *point);
int monster(int M[][30], int *player_x, int *player_y, int level, int *monster_x, int *monster_y);
int baseball_game(int M[][30], int player_x, int player_y, int *point );

void status_print(int jump_num, int freeze_num,int flag,int point);
void text_print(char input[50], char prase1[50], char prase2[50], char prase3[50]);
void die();
//#define level_1 3
//#define level_2 5
//#define level_3 7