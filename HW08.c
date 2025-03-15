#include <stdio.h>
#define welcoming "Welcome ot the calculator.\n"
#define prompt1 "What would you like to do? \n    (a) add, \n    (s) substraction \n    (m) multiplication \n    (d) division \n    (q) quit"

int add(int a, int b);
int substraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

int main(void) {
	printf(welcoming);
	printf(prompt1);
	char ans;
	while(runner(ans)); 
	return 1;
}
int runner(char ans ){
 	char ans = getchar();
	switch (ans)
	{
	case('a'):
		printf("aa");
		return 1;
	case('s'):
		printf("ss");
		return 1;
	case('m'):
		return 1;
	case('d'):
		return 1;
	case('q'):
		printf("Bye bye.");
		return 0;
	default:
		return 0;
	}
}

int add(int a, int b) {
	return a + b;
}

int substraction(int a, int b) {
	return a - b;
}

int multiplication(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	if (b != 0)
	return a / b;
printf("Division by 0 isn't possible");
return 0;
}
