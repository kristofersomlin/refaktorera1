#include <stdio.h>
int menu_root() {
	int val;
	printf("\n");
	printf("V\x84lj vilka storheter du vill ber\x84kna:\n");
	printf("V\x84lj 1 f\x94r: OHMS LAG\n");
	printf("V\x84lj 2 f\x94r: Rtot\n");
	printf("V\x84lj 3 f\x94r: EFFEKTLAGEN ENKEL\n");
	printf("V\x84lj 4 f\x94r: SKENBAR EFFEKT ENFAS\n");
	printf("V\x84lj 5 f\x94r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
	printf("V\x84lj 6 f\x94r: SKENBAR EFFEKT 3-FAS\n");
	printf("V\x84lj 7 f\x94r: AKTIV EFFEKT 3-FAS\n");
	printf("V\x84lj 0 f\x94r: ATT AVSLUTA\n");
	scanf("%d", &val);
	return val;
}

double print_scan(char text[300]) {
	double num;
	printf("%s", text);
	scanf(" %lf", &num);
	return num;
}
