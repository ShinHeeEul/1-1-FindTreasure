#include "����.h"


char found[50] = "������ ã�Ҵ�!";
char baseball_start[50] = "���ھ߱� ������ �����մϴ�";
char fire[50] = "�߸��� ������ ã�Ҿ����";
int flag(int M[][30], int *player_x, int *player_y,int *num_T, int input_text[50], char prase1[50], char prase2[50], char prase3[50], int *point) {
	int r;

	if (M[*player_y][*player_x] == '��') {
		strcpy(input_text, found);
		text_print(input_text, prase1, prase2, prase3);
		M[*player_y][*player_x] = '  ';
		(*num_T)--;
		if (*num_T == 0)
			return 2;
	}
	if (M[*player_y][*player_x] == '��') {
		strcpy(input_text,baseball_start);
		text_print(input_text, prase1, prase2, prase3);
		M[*player_y][*player_x] = '  ';
		r = baseball_game(M, player_x, player_y, &(*point));
		if (r == 1)
			M[*player_y][*player_x] = '  ';
		return r;
	}	
	if (M[*player_y][*player_x] == '��') {
	
		strcpy(input_text, fire);
		text_print(input_text, prase1, prase2, prase3);
		M[*player_y][*player_x] = '  ';
	}
	return 0;
}