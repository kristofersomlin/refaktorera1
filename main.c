#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
//gcc -o main main.c menu.c calc.c print_functions.c
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
