#include "ÆÀÇÃ.h"

void text_print(char input[50], char prase1[50], char prase2[50], char prase3[50]) {


	int coordx_text = 0;
	int coordy_text = 30;

	strcpy(prase3, prase2);
	strcpy(prase2, prase1);


	gotoxy(coordx_text, coordy_text);
	strcpy(prase1, input);


	printf("***********************************************************\n");
	printf("***********************************************************\n");
	printf("**(1) %-50s **\n", prase1);
	printf("**                                                       **\n");
	printf("**                                                       **\n");
	printf("**(2) %-50s **\n", prase2);
	printf("**                                                       **\n");
	printf("**                                                       **\n");
	printf("**(3) %-50s **\n", prase3);
	printf("**                                                       **\n");
	printf("***********************************************************\n");
	printf("***********************************************************\n");



}
