#include "../main.h"

#define N_TESTS (12)

void dbgprintout(char *s)
{
	int i;

	printf("----------\n|");
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 32 && s[i] <= 126)
			printf("%c", s[i]);
		else
			printf("!!%d!!", s[i]);
	}
	
	printf("|\n----------\n");	
}

int main(void)
{
	char *input[N_TESTS];
	char *output[N_TESTS];
	char *_output[N_TESTS];
	int count[N_TESTS];
	int _count[N_TESTS];

	int i = 0;

	printf("\n");

	/**/
	input[i] = "printf(\"H\")";

	start_capture();
	count[i] = printf("H");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("H");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"Hello world!\")";

	start_capture();
	count[i] = printf("Hello world!");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("Hello world!");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"Hello world!\\n\")";

	start_capture();
	count[i] = printf("Hello world!\n");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("Hello world!\n");
	_output[i] = end_capture();
	/**/



	/**/
	i++;
	input[i] = "printf(\"%c\"), 'C'";

	start_capture();
	count[i] = printf("%c", 'C');
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c", 'C');
	_output[i] = end_capture();
	/**/

	
	/**/
	i++;
	input[i] = "printf(\"d%cd\")";

	start_capture();
	count[i] = printf("d%cd");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("d%cd");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%s\", \"Hello world!\n\")";

	start_capture();
	count[i] = printf("%s", "Hello world!\n");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%s", "Hello world!\n");
	_output[i] = end_capture();
	/**/



	/**/
	i++;
	input[i] = "printf(\"%s\", NULL)";

	start_capture();
	count[i] = printf("%s", NULL);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%s", NULL);
	_output[i] = end_capture();
	/**/


	/**/
	/*i++;
	input[i] = "printf(\"%s\")";*/

	/*printf("\%s: |");
	int x = printf("%s");
	printf("|, %d\n", x);*/

	/*start_capture();
	count[i] = printf("%s");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%s");
	_output[i] = end_capture();*/
	/**/

	/**/
	/*i++;
	input[i] = "printf()";

	start_capture();
	count[i] = printf();
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf();
	_output[i] = end_capture();*/
	/**/
	
	/**/
	i++;
	input[i] = "printf(NULL)";

	start_capture();
	count[i] = printf(NULL);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf(NULL);
	_output[i] = end_capture();
	/**/
	
	/**/
	i++;
	input[i] = "printf(\"%%\")";

	start_capture();
	count[i] = printf("%%");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%%");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%d\")";

	start_capture();
	count[i] = printf("%d");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%d");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%d\"), 99";

	start_capture();
	count[i] = printf("%d", 99);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%d", 99);
	_output[i] = end_capture();
	/**/



	/**/
	i++;
	input[i] = "printf(\"%z\")";

	start_capture();
	count[i] = printf("%z");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%z");
	_output[i] = end_capture();
	/**/



	if (i != (N_TESTS - 1))
	{
		printf(RED_TEXT "!!ERROR!!: i !== N_TESTS\n" RESET_TEXT);
		exit(1);
	}


	for (i = 0; i < N_TESTS; i++)
	{
		printf("%s\n", input[i]);
		printf("\tBytes written (return value): %s\n\t\t printf: %d\n\t\t_printf: %d\n\n", count[i] == _count[i] ? "==" : "!=", count[i], _count[i]);
		printf("\tStr cmp: %s\n\n ", strcmp(output[i], _output[i]) == 0 ? "==" : "!=");

		if (count[i] != _count[i])
		{
			printf(RED_TEXT "\t\t\t !!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!!\n");
			/*printf("printf:\n----------\n|%s|\n----------\n\n", output[i]);*/
			printf("printf:\n");
			dbgprintout(output[i]);
			printf("_printf:\n");
			dbgprintout(_output[i]);
			printf("" RESET_TEXT);
		}
	}

	return (0);
}
