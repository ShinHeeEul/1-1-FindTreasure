#include"����.h"


int monster(int M[][30], int *player_x, int *player_y, int level, int *monster_x, int *monster_y) {
	int i = 0;
	int x, y;
	int I_x, I_y;
		while (i < 2*(level)) {
			gotoxy(2 * (monster_x[i]), monster_y[i]);		// ���� ǥ�õǾ��� ���� �������ϴ�.
			
			printf("  ");
			//gotoxy(2 * (monster_x[i]), monster_y[i]);
			switch (M[monster_y[i]][monster_x[i]]) {		// ��� ��ġ�� ���Ͱ� ����� ����� �ٽ� ����ϱ����ؼ� switch���� �̿��߽��ϴ�.
			case '��':
				printf("��");
				M[monster_y[i]][monster_x[i]] = '��';		// ���ͳ��� ��ġ�� ��츦 üũ�ϱ� ���ؼ� �迭 M��
				break;										// �̿��߱� ������ �ٽ� ��߷� �ʱ�ȭ����
			case '��':
				printf("��");
				M[monster_y[i]][monster_x[i]] = '��';
				break;
			case '��':
				printf("��");
				M[monster_y[i]][monster_x[i]] = '��';
				break;
			case '��':
				M[monster_y[i]][monster_x[i]] = '  ';		// ���������� ��ĭ���� �ʱ�ȭ ����
				break;
			}
			// ��: ������� ��:�̴ϰ��� ��:��  ��:�÷��̾� ��:����

			I_x = monster_x[i];
			I_y = monster_y[i];

			x = abs(*player_x - monster_x[i]);			// ���Ϳ� �÷��̾��� �Ÿ��� �̿��Ͽ� 
			y = abs(*player_y - monster_y[i]);			// ���̵� ������ �̿��Ͽ����ϴ�.
				if ((x <= 5 + level) || (y <= 5 + level)) {			// �÷��̾�� ���Ͱ� ��������� �߰��� �����մϴ�.
					if (rand() % 2) {
						if (*player_x > monster_x[i]) {						// ���Ͱ� �����̴� �˰����� ��� �Ȱ����ϴ�.
							monster_x[i] ++;
							if (M[monster_y[i]][monster_x[i]] == '��')		// ��������������ϸ�
								monster_x[i] --;
							else if (M[monster_y[i]][monster_x[i]] == '��')	// ��ġ�� ���ϵ��� �ڵ��Ͽ����ϴ�.
								monster_x[i] --;
						}
						else if (*player_x < monster_x[i]) {
							monster_x[i] --;
							if (M[monster_y[i]][monster_x[i]] == '��')
								monster_x[i] ++;
							else if (M[monster_y[i]][monster_x[i]] == '��')
								monster_x[i] ++;
						}
					}
					else {
						if (*player_y > monster_y[i]) {
							monster_y[i]++;
							if (M[monster_y[i]][monster_x[i]] == '��')
								monster_y[i]--;
							else if (M[monster_y[i]][monster_x[i]] == '��')
								monster_y[i] --;
						}
						else if (*player_y < monster_y[i]) {
							monster_y[i]--;
							if (M[monster_y[i]][monster_x[i]] == '��')
								monster_y[i]++;
							else if (M[monster_y[i]][monster_x[i]] == '��')
								monster_y[i]++;
						}
					}
				}
				else {									// �Ÿ��� �ָ� �����ϰ� �����Դϴ�.
					switch (rand() % 4) {
					case 0:
						monster_x[i] ++;
						if (M[monster_y[i]][monster_x[i]] == '��')
							monster_x[i] --;
						else if (M[monster_y[i]][monster_x[i]] == '��')
							monster_x[i] --;
						break;
					case 1:
						monster_x[i] --;
						if (M[monster_y[i]][monster_x[i]] == '��')
							monster_x[i] ++;
						else if (M[monster_y[i]][monster_x[i]] == '��')
							monster_x[i] --;
						break;
					case 2:
						monster_y[i]++;
						if (M[monster_y[i]][monster_x[i]] == '��')
							monster_y[i]--;
						else if (M[monster_y[i]][monster_x[i]] == '��')
							monster_y[i]--;
						break;
					case 3:
						monster_y[i]--;
						if (M[monster_y[i]][monster_x[i]] == '��')
							monster_y[i]++;
						else if (M[monster_y[i]][monster_x[i]] == '��')
							monster_y[i]++;
						break;
					}
				}
			gotoxy(2 * (monster_x[i]), monster_y[i]);
			printf("��");
			if (M[monster_y[i]][monster_x[i]] == '  ')
				M[monster_y[i]][monster_x[i]] = '��';
			if ((monster_x[i] == *player_x) && (monster_y[i] == *player_y))
				return 1;
			
			i++;
			
		}
	
	return 0;
}