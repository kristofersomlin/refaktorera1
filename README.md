# Files
- main.c : Just the main() loop with a function-pointer with the help of an array of void pointers
- calc.c : All the different calculations
- print_functions.c : All the functions to print text, both the menu and the input for menu

# Functions
- double multi(double x, double y);
- double res_tot(double r1, double r2, double r3);
- double aktiv_eff(double u, double i, double cos);
- double sken_3fas(double u, double i);
- double aktiv_3fas(double u, double i, double cos);
- void (*menupicker)();
- void menu_1();
- void menu_2();
- void menu_3();
- void menu_4();
- void menu_5();
- void menu_6();
- void menu_7();
- void menu_0();
- int menu_root();
- double print_scan(char text[300]);

# Makefile
TARGET = main (setting the name for the file)
LIBS = -lm (lm is the math library)
CC = gcc (what to compile with)
CFLAGS = -g -Wall (wall command will enable compiler warnings)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
