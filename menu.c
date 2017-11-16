#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include "print_functions.h"
extern int run;
void menu_1() {
	printf("Ohms lag sp\x86nningen(volt/V) bet""\x86""ckning U lika med Resistansen(Ohm) betäckning R \n");
	printf("g\x86""nger Str""\x94""mmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
	double r=print_scan("Skriv resistans R < 20 000ohm:");
	while(r>20000) {
		r=print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
	}
	double i=print_scan("Skriv str\x94m I < 440 Ampere: \n");
	while(i > 440) {
		i=print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
	}
	printf("%f V\n", multi(r, i));
}

void menu_2() {
		printf("Resistans sammankopplade i parallella kretsar \x84r lika med 1 delat Resistans R total \x84r lika med\n");
		printf("Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi h\x94gst anv\x84nder tre resistanser.\n\n");
		double r1 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r1 > 20000)		{
			r1 = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
		}
		double r2 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r2 > 20000)		{
				r2 = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
		}
		double r3 = print_scan("Skriv resistans R1 < 20 000ohm: \n");
		while(r3 > 20000)		{
				r3 = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
		}
		printf("%f Ohm\n", res_tot(r1, r2, r3));
}

void menu_3() {
	printf("Effektlagen enkel f\x94r likstr\x94m \x84r effekten P i Watt (W) lika med sp\x84nningen U i volt(V)\n");
	printf("g�nger str�mmen I i Ampere(A): \n\n");
	double u = print_scan("Skriv sp\x84nnngen U i volt(V): \n");
	double i = print_scan("Skriv str\x94m Ampere I < 440A: \n");
	while(i > 440)	{
		i = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
	}
	printf("%f W\n", multi(u, i));
}
void menu_4() {
	printf("Skenbar effekt enfas r\x84knas med storheten VA(VoltAmpere) som \x84r lika med sp\x84nningen U i volt(V)\n");
	printf("g\x86nger str\x94mmen I i ampere(A)\n\n");
	double u = print_scan("Skriv sp\x84nnngen U i volt(V): \n");
	double i = print_scan("Skriv str\x94m Ampere I < 440A: \n");
	while(i > 440)	{
		i = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen: \n");
	}
	printf("%f VA\n", multi(u, i));
}
void menu_5() {
	printf("Aktiv medelefdekt enfas \x84r lika med effekt P i watt(W) lika med sp\x84nningen U i volt(V) g\x86nger str\x94mmen I \n");
	printf("i Ampere g\x86nger cosinus fi/efkektfaktor < 1:\n\n");
	double u = print_scan("Skriv sp\x84nnngen U i volt(V): \n");
	double i = print_scan("Skriv str\x94m I: \n");
	while(i > 440){
			i = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen:\n");
	}
	double cos = print_scan("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
	while (cos < 0 && cos > 1) {
		cos = print_scan("Fel v�rde, f\x94rs\x94k igen\n");
	}
	printf("%f W\n", aktiv_eff(u, i, cos));
}
void menu_6() {
				printf("3-fas skenbar effekt \x84r v\x84xelsp\x84nning \x84r skenbar effekt S i voltampere(VA) lika med sp\x84nningen U i volt(V) \n");
				printf("g\x86nger str\x94mmen I i ampere(A) g\x86nger roten ur 3 SQRT(3).\n\n");
				double u = print_scan("Skriv sp\x84nning U i volt(V) < 400V: \n ");
				while(u > 400) {
						u = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen:\n");
				}
				double i = print_scan("Skriv str\x94m I i ampere < 440: \n");
				while(i > 440) {
						i = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen:\n");
				}
				printf("%f VA\n", sken_3fas(u, i));
}
void menu_7() {
	            printf("3-fas aktiv effekt \x84r effekten P i Watt(W) lika med sp\x84nningen U i volt(V) g\x86nger str\x94mmen I i ampere(A)\n");
	            printf("g\x86nger cos < 1 && cos > 0 g\x86nger roten ur 3 SQRT(3).\n\n");
							double u = print_scan("Skriv sp\x84nningen U i volt(V): \n");
	            while(u > 400) {
	                u = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen:\n");
	            }
	            double i = print_scan("Skriv str\x94m I i ampere(A): \n");
	            while(i > 440) {
	                i = print_scan("f\x94r h\x94gt v\x84rde, f\x94rs\x94k igen:\n");
	            }
							double cos = print_scan("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
							while (cos < 0 && cos > 1) {
								cos = print_scan("Fel v\x84rde, f\x94rs\x94k igen\n");
							}
	            printf("%f W\n", aktiv_3fas(u ,i, cos));
}
void menu_0() {
	run=0;
}
