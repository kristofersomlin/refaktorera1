#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
int run=1;

int menu_root() {
	int val;
	printf("\n");
	printf("V\x84lj vilka storheter du vill ber�kna:\n");
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

double ohms_lag(double r, double i){
    double u = i * r;
    return u;
}

double res_tot(double r1, double r2, double r3){
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

double eff_enk(double u, double i){
    double p = u * i;
    return p;
}

double sken_eff(double u, double i){
    double s = u * i;
    return s;
}

double aktiv_eff(double u, double i, double cos){
    double p = u * i * cos;
    return p;
}

double sken_3fas(double u, double i){
    double s = u * i * sqrt(3);
    return s;
}

double aktiv_3fas(double u, double i, double cos){
    double p = u * i * sqrt(3) * cos;
    return p;
}

void (*menupicker)();
void menu_1() {
	printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
	printf("g�nger Str�mmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
	double r=0, i=0;
	printf("Skriv resistans R < 20 000ohm: \n ");
	scanf("%lf", &r);

	while(r>20000 || r==0) {
		printf("f\x94r högt v\x84rde, f\x94rsök igen: \n");
		scanf("%lf", &r);
	}
	printf("Skriv str�m I < 440 Ampere: \n");
	scanf("%lf", &i);
	while(i > 440) {
			printf("f\x94r högt v\x84rde, f\x94rsök igen: \n");
			scanf("%lf", &i);
	}
	printf("%f V\n", ohms_lag(r, i));
}

void menu_2() {
		printf("Resistans sammankopplade i parallella kretsar \x84r lika med 1 delat Resistans R total \x84r lika med\n");
		printf("Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi högst anv\x84nder tre resistanser.\n\n");
		double r1,r2,r3;
		printf("Skriv resistans R1 < 20 000ohm: \n");
		scanf("%lf", &r1);
		while(r1 > 20000)
		{
				printf("f\x94r högt v\x84rde, f\x94rsök igen: \n");
				scanf("%lf", &r1);
		}
		printf("Skriv resistans R2 < 20 000ohm: \n");
		scanf("%lf", &r2);
		while(r2 > 20000)
		{
				printf("f\x94r högt v�rde, f\x94rsök igen: \n");
				scanf("%lf", &r2);

		}
		printf("Skriv resistans R3 < 20 000ohm: \n ");
		scanf("%lf", &r3);
		while(r3 > 20000)
		{
				printf("f\x94r högt v�rde, f\x94rsök igen: \n");
				scanf("%lf", &r3);

		}
		printf("%f Ohm\n", res_tot(r1, r2, r3));
}

void menu_3() {
	            printf("Effektlagen enkel f\x94r likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
	            printf("g�nger str�mmen I i Ampere(A): \n\n");
	            double u, i;
	            printf("Skriv spännngen U i volt(V): \n ");
	            scanf("%lf", &u);
	            printf("Skriv str�m Ampere I < 440A: \n");
	            scanf("%lf", &i);
	            while(i > 440)
	            {
	                printf("f\x94r högt v�rde, f\x94rsök igen: \n");
 								scanf("%lf", &i);
	            }
	            printf("%f W\n", eff_enk(u, i));
}
void menu_4() {

	            printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med spänningen U i volt(V)\n");
	            printf("g�nger str�mmen I i ampere(A)\n\n");
	            double u, i;
	            printf("Skriv spänningen U i volt: \n ");
	            scanf("%lf", &u);
	            printf("Skriv str�m I < 440A: \n");
	            scanf("%lf", &i);
	            while(i > 440)
	            {
	                printf("f\x94r högt v�rde, f\x94rsök igen: \n");
									scanf("%lf", &i);
	            }
	            printf("%f VA\n", sken_eff(u, i));
}
void menu_5() {
	printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med spänningen U i volt(V) g�nger str�mmen I \n");
	printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
	double u, i, cos;
	printf("Skriv spänning U i volt: \n ");
	scanf("%lf", &u);
	printf("Skriv str�m I: \n");
	scanf("%lf", &i);
	while(i > 440){
			printf("f\x94r högt v�rde, f\x94rsök igen:\n");
			scanf("%lf", &i);
	}
	printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
	scanf("%lf", &cos);
	while (cos < 0 && cos > 1)
	{
			printf("Fel v�rde, f\x94rsök igen\n");
			scanf("%lf", &cos);
	}
	printf("%f W\n", aktiv_eff(u, i, cos));
}
void menu_6() {

				printf("3-fas skenbar effekt �r v�xelspänning �r skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
				printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
				double u, i;
				printf("Skriv spänning U i volt(V) < 400V: \n ");
				scanf("%lf", &u);
				while(u > 400)
				{
						printf("f\x94r högt v�rde, f\x94rsök igen: \n");
						scanf("%lf", &u);
				}

				printf("Skriv str�m I i ampere < 440: \n");
				scanf("%lf", &i);
				while(i > 440)
				{
						printf("f\x94r högt v�rde, f\x94rsök igen: \n");
						scanf("%lf", &i);
				}
				printf("%f VA\n", sken_3fas(u, i));
}
void menu_7() {

	            printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med spänningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
	            printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
	            double u, i, cos;
	            printf("Skriv spänningen U i volt(V): \n ");
	            scanf("%lf", &u);
	            while(u > 400)
	            {
	                printf("f\x94r högt v�rde, f\x94rsök igen.\n");
	                scanf("%lf", &u);
	            }
	            printf("Skriv str�m I i ampere(A): \n");
	            scanf("%lf", &i);
	            while(i > 440)
	            {
	                printf("f\x94r högt v�rde, f\x94rsök igen.\n");
	                 scanf("%lf", &i);
	            }
	            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
	            scanf("%lf", &cos);
	            while (cos < 0 && cos > 1)
	            {
	                printf("f\x94r högt v�rde, f\x94rsök igen: \n");
	                scanf("%lf", &cos);
	            }
	            printf("%f W\n", aktiv_3fas(u ,i, cos));
}
void menu_0() {
	run=0;
}
int main() {
	system("cls");
	while (run)	{
		int val=menu_root();
		void *menu_list[8]={menu_0,menu_1,menu_2,menu_3,menu_4,menu_5,menu_6,menu_7};
		while(val>7 || val<0){
			printf("error, fel meny!\n\n");
			val=menu_root();
		}
		menupicker=menu_list[val];
		menupicker();
	}
  return 0;
}
