// HW 08 Gabriel Cotua
 
// libraries
#include <stdio.h>
#include <ctype.h>
 
// macros
#define GABRIEL "\n\n|#####################|\n|HW #08, Gabriel Cotua|\n|#####################|\n\n"
#define WELCOMING "Welcome ot the calculator.\n"
#define PROMPT1 "What would you like to do? \n    (a) add \n    (s) substraction \n    (m) multiplication \n    (d) division \n    (q) quit\n"
#define PROMPT_FIRSTVAL "\nInsert first value: "
#define PROMPT_SECONDVAL "\nInsert second Value: "
#define FLUSH while(getchar() != '\n');
 
// functions declarations
int gatherInput(float * a, float * b, char operation);
void checkForInput(int val, float * pVal);
 
// main fuction
 
int main(void) {
	float a, b;

	printf(GABRIEL);
	printf(WELCOMING);
	printf(PROMPT1);
 
	char ans = getchar();
 
	while(ans != 'q') {
 
		switch (tolower(ans))
		{
 
		case('a'):
 
			gatherInput(&a, &b, 'a');
			printf("\n\n%.2lf + %.2lf = %.2lf\n", a, b, a + b);
			break;
 
		case('s'):
 
			gatherInput(&a, &b, 's');
			printf("\n\n%.2lf - %.2lf = %.2lf\n", a, b, a - b);
			break;
 
		case('m'):
 
			gatherInput(&a, &b, 'm');
			printf("\n\n%.2lf * %.2lf = %.2lf\n", a, b, a * b);
			break;
 
		case('d'):
 
			gatherInput(&a, &b, 'd');
			printf("\n\n%.2lf / %.2lf = %.2lf\n", a, b, a/b);
			break;

		case('q'):
 
			printf("\nBye bye.\n");
			return 1;

		default:
 
			printf("\nTry again, %c isn't a valid choice\n", ans);
			break;
 
		}
		printf("\n\n"PROMPT1);

		FLUSH;
	 	ans = getchar();
	}
	return 1;
}
 
// functions definitions
int gatherInput(float * a, float * b, char operation) {
 
	printf(PROMPT_FIRSTVAL);
	FLUSH;
 	checkForInput(scanf("%g", a), a);

	printf(PROMPT_SECONDVAL);
	FLUSH;
	checkForInput(scanf("%g", b), b);
 
	if (operation == 'd' && *b == 0) {

		while(*b == 0) {
 
			printf("\nDivision by 0 isn't possible, please try another number.\n");
			FLUSH;
			scanf("%g", b);
		}
	}
	return 1;
}
 
void checkForInput(int val, float * pVal) {
 
	if ( val == 0 ) {
 
		printf("\nInput not valid, please insert a number: ");
		FLUSH;

		while( scanf("%g", pVal) != 1) {
		printf("\nInput not valid, please insert a number: ");
		FLUSH;
		}
 
	}
 
}

/*
 * 		[Verification Plan]
 *
 * 	"," means new linee
 *
 *	[Input]			[expected output]
 *	a,			"insert first value: "
 *
 *	a, 12,			"Insert first value: 12, Insert second value: "
 *
 *	a, 12, 12,		"Insert first value: 12, Insert second value: 12, 12.00 + 12.00 = 24.00"
 *
 *	b,			"Try again, b ins't a valid choice"
 *				( loop until right input )
 *
 *	%,			"Try again, % ins't a valid choice"
 *				( loop until right input )
 *
 *	a, a,			"Insert first value: a, Input not valid, please insert a number: "
 *
 *	d, 10, 0,		"Insert first value: 10, Insert second value: 0, Division by 0 isn't possible, please try another number."
 *										( loop until right input )
 */
