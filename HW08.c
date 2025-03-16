// libraries
#include <stdio.h>
#include <ctype.h>

// macros
#define WELCOMING "Welcome ot the calculator.\n"
#define PROMPT1 "What would you like to do? \n    (a) add \n    (s) substraction \n    (m) multiplication \n    (d) division \n    (q) quit\n"
#define PROMPT_FIRSTVAL "\nInsert first value: "
#define PROMPT_SECONDVAL "\nInsert second Value: "
#define FLUSH while(getchar() != '\n');

// functions headers
int add(int a, int b);
int substraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int gatherInput(int * a, int * b);

// main fuction
int main(void) {
	int a, b;
	printf(WELCOMING);
	printf(PROMPT1);
	char ans = getchar();
	while(ans != 'q') {

		switch (tolower(ans))
		{
		case('a'):
			gatherInput(&a, &b);
			printf("Total: %d\n", add(a, b));
			break;

		case('s'):
			gatherInput(&a, &b);
			printf("Total: %d\n", substraction(a, b));
			break;

		case('m'):
			gatherInput(&a, &b);
			printf("Total: %d\n", multiplication(a, b));
			break;

		case('d'):
			gatherInput(&a, &b);
			printf("Total: %d\n", division(a, b));
			break;

		case('q'):
			printf("Bye bye.");
			return 1;

		default:
			printf("Try again, %c isn't a valid choice", ans);
			break;
		}
		printf("\n\n"PROMPT1);
		FLUSH;
	 	ans = getchar();
	}
	return 1;
}

// functions bodies
int gatherInput(int * a, int * b) {
	printf(PROMPT_FIRSTVAL);
	FLUSH;
	scanf("%d", a);
	printf(PROMPT_SECONDVAL);
	FLUSH;
	scanf("%d", b);
	return 1;
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
