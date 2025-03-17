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
double add(double a, double b);
double substraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double gatherInput(double * a, double * b);

// main fuction
int main(void) {
	double a, b;
	
	printf(WELCOMING);
	printf(PROMPT1);
	char ans = getchar();
	while(ans != 'q') {

		switch (tolower(ans))
		{
		case('a'):
			gatherInput(&a, &b);
			printf("Total: %.2lf\n", add(a, b));
			break;

		case('s'):
			gatherInput(&a, &b);
			printf("Total: %.2lf\n", substraction(a, b));
			break;

		case('m'):
			gatherInput(&a, &b);
			printf("Total: %.2lf\n", multiplication(a, b));
			break;

		case('d'):
			gatherInput(&a, &b);
			printf("Total: %.2lf\n", division(a, b));
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
double gatherInput(double * a, double * b) {
	printf(PROMPT_FIRSTVAL);
	FLUSH;
	scanf("%lf", a);
	printf(PROMPT_SECONDVAL);
	FLUSH;
	scanf("%lf", b);
	return 1;
}

double add(double a, double b) {
	return a + b;
}

double substraction(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

double division(double a, double b) {
	if (b != 0)
	return a / b;
printf("Division by 0 isn't possible");
return 0;
}
