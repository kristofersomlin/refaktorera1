#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include "print_functions.h"
void menu_1() {
	printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
	printf("g�nger Str�mmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
	double r=print_scan("Skriv resistans R < 20 000ohm:");
	while(r>20000) {
		r=print_scan("f\x94r högt v\x84rde, f\x94rsök igen: \n");
	}
	double i=print_scan("Skriv ström I < 440 Ampere: \n");
	while(i > 440) {
		i=print_scan("f\x94r högt v\x84rde, f\x94rsök igen: \n");
	}
	printf("%f V\n", multi(r, i));
}

void menu_2() {
		printf("Resistans sammankopplade i parallella kretsar \x84r lika med 1 delat Resistans R total \x84r lika med\n");
		printf("Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi högst anv\x84nder tre resistanser.\n\n");
		double r1 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r1 > 20000)		{
			r1 = print_scan("f\x94r högt v\x84rde, f\x94rsök igen: \n");
		}
		double r2 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r2 > 20000)		{
				r2 = print_scan("f\x94r högt v\x84rde, f\x94rsök igen: \n");
		}
		double r3 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r3 > 20000)		{
				r3 = print_scan("f\x94r högt v\x84rde, f\x94rsök igen: \n");
		}
		printf("%f Ohm\n", res_tot(r1, r2, r3));
}

void menu_3() {
	printf("Effektlagen enkel f\x94r likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
	printf("g�nger str�mmen I i Ampere(A): \n\n");
	double u = print_scan("Skriv spännngen U i volt(V): \n");
	double i = print_scan("Skriv str�m Ampere I < 440A: \n");
	while(i > 440)	{
		i = print_scan("f\x94r högt v�rde, f\x94rsök igen: \n");
	}
	printf("%f W\n", multi(u, i));
}
void menu_4() {
	printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med spänningen U i volt(V)\n");
	printf("g�nger str�mmen I i ampere(A)\n\n");
	double u = print_scan("Skriv spännngen U i volt(V): \n");
	double i = print_scan("Skriv str�m Ampere I < 440A: \n");
	while(i > 440)	{
		i = print_scan("f\x94r högt v�rde, f\x94rsök igen: \n");
	}
	printf("%f VA\n", multi(u, i));
}
void menu_5() {
	printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med spänningen U i volt(V) g�nger str�mmen I \n");
	printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
	double u = print_scan("Skriv spännngen U i volt(V): \n");
	double i = print_scan("Skriv str�m I: \n");
	while(i > 440){
			i = print_scan("f\x94r högt v�rde, f\x94rsök igen:\n");
	}
	double cos = print_scan("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
	while (cos < 0 && cos > 1) {
		cos = print_scan("Fel v�rde, f\x94rsök igen\n");
	}
	printf("%f W\n", aktiv_eff(u, i, cos));
}
void menu_6() {
				printf("3-fas skenbar effekt �r v�xelspänning �r skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
				printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
				double u = print_scan("Skriv spänning U i volt(V) < 400V: \n ");
				while(u > 400) {
						u = print_scan("f\x94r högt v�rde, f\x94rsök igen:\n");
				}
				double i = print_scan("Skriv str�m I i ampere < 440: \n");
				while(i > 440) {
						i = print_scan("f\x94r högt v�rde, f\x94rsök igen:\n");
				}
				printf("%f VA\n", sken_3fas(u, i));
}
void menu_7() {
	            printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med spänningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
	            printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
							double u = print_scan("Skriv spänningen U i volt(V): \n");
	            while(u > 400) {
	                u = print_scan("f\x94r högt v�rde, f\x94rsök igen:\n");
	            }
	            double i = print_scan("Skriv str�m I i ampere(A): \n");
	            while(i > 440) {
	                i = print_scan("f\x94r högt v�rde, f\x94rsök igen:\n");
	            }
							double cos = print_scan("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
							while (cos < 0 && cos > 1) {
								cos = print_scan("Fel v�rde, f\x94rsök igen\n");
							}
	            printf("%f W\n", aktiv_3fas(u ,i, cos));
}
void menu_0() {
	//run=0;
}
