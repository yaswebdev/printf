#include "../main.h"

#define N_TESTS (34)

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
	void *addr = (void *)0x7ffe637541f0;

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
	input[i] = "printf(\"%C\", 'C')";

	start_capture();
	count[i] = printf("%C", 'C');
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%C", 'C');
	_output[i] = end_capture();
	/**/


	/**/
	i++;
	input[i] = "printf(\"%c\", 'C')";

	start_capture();
	count[i] = printf("%c", 'C');
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c", 'C');
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%c\", 0)";

	start_capture();
	count[i] = printf("%c", 0);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c", 0);
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%c\", 5)";

	start_capture();
	count[i] = printf("%c", 5);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c", 5);
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%c\", 101)";

	start_capture();
	count[i] = printf("%c", 101);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c", 101);
	_output[i] = end_capture();
	/**/

	
	/**/
	i++;
	input[i] = "printf(\"%c\")";

	start_capture();
	count[i] = printf("%c");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%c");
	_output[i] = end_capture();
	/**/

	/*************************(%s)*********************************/
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

	/*printf("Hlwqdqwd:\n|");
	_printf("%s");
	printf("|\n");*/

	/*start_capture();
	count[i] = printf("%s");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%s");
	_output[i] = end_capture();*/
	/**/

	/********************************************************************/
	
	/*******************************(%s)*********************************/
	i++;
	input[i] = "printf(\"%S\", \"Hello world!\n\")";

	start_capture();
	count[i] = printf("%S", "Hello world!\n");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%S", "Hello world!\n");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%S\", NULL)";

	start_capture();
	count[i] = printf("%S", NULL);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%S", NULL);
	_output[i] = end_capture();
	/**/

	/********************************************************************/

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
	/*printf("printf %%:\n");
	printf("%");
	printf("printf %% over\n");
	printf("_printf %%:\n");
	_printf("%");
	printf("_printf %% over\n");*/
	i++;
	input[i] = "printf(\"%\")";

	start_capture();
	count[i] = printf("%");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"% \")";

	start_capture();
	count[i] = printf("% ");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("% ");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"% w\")";

	start_capture();
	count[i] = printf("% w");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("% w");
	_output[i] = end_capture();
	/**/


	/*******************(%d)************************/
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
	input[i] = "printf(\"%d\", 90809)";

	start_capture();
	count[i] = printf("%d", 90809);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%d", 90809);
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%d\", -12)";

	start_capture();
	count[i] = printf("%d", -12);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%d", -12);
	_output[i] = end_capture();
	/**/

	/*************************(%u)************************/
	/**/
	i++;
	input[i] = "printf(\"%u\")";

	start_capture();
	count[i] = printf("%u");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%u");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%u\", 90809)";

	start_capture();
	count[i] = printf("%u", 90809);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%u", 90809);
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%u\", -12)";

	start_capture();
	count[i] = printf("%u", -12);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%u", -12);
	_output[i] = end_capture();
	/**/

	/******************************(%b)********************/
	/**/
	i++;
	input[i] = "printf(\"%b\")";

	start_capture();
	count[i] = printf("%b");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%b");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%b\", 90809)";

	start_capture();
	count[i] = printf("%b", 90809);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%b", 90809);
	_output[i] = end_capture();
	/**/

	/******************************(%p)********************/
	/**/
	i++;
	input[i] = "printf(\"%p\")";

	start_capture();
	count[i] = printf("%p");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%p");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%p\", addr)";

	start_capture();
	count[i] = printf("%p", addr);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%p", addr);
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%p\", NULL)";

	start_capture();
	count[i] = printf("%p", NULL);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%p", NULL);
	_output[i] = end_capture();
	/**/


	/******************************(%o)********************/
	/**/
	i++;
	input[i] = "printf(\"%o\")";

	start_capture();
	count[i] = printf("%o");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%o");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%o\", 90809)";

	start_capture();
	count[i] = printf("%o", 90809);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%o", 90809);
	_output[i] = end_capture();
	/**/

	/******************************(%x)********************/
	/**/
	i++;
	input[i] = "printf(\"%x\")";

	start_capture();
	count[i] = printf("%x");
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%x");
	_output[i] = end_capture();
	/**/

	/**/
	i++;
	input[i] = "printf(\"%x\", 90809)";

	start_capture();
	count[i] = printf("%x", 90809);
	output[i] = end_capture();

	start_capture();
	_count[i] = _printf("%x", 90809);
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



	if (i + 1 != (N_TESTS))
	{
		printf(RED_TEXT "!!ERROR!!: i(%d) !== N_TESTS(%d)\n" RESET_TEXT, i + 1, N_TESTS);
		exit(1);
	}


	for (i = 0; i < N_TESTS; i++)
	{
		printf("%s\n", input[i]);
		printf("\tBytes written (return value): %s\n\t\t printf: %d\n\t\t_printf: %d\n\n", count[i] == _count[i] ? "==" : "!=", count[i], _count[i]);
		printf("\tStr cmp: %s\n\n ", strcmp(output[i], _output[i]) == 0 ? "==" : "!=");

		if (count[i] != _count[i] || strcmp(output[i], _output[i]) != 0)
		{
			printf(RED_TEXT "\t\t\t !!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!!\n");
			/*printf("printf:\n----------\n|%s|\n----------\n\n", output[i]);*/
			printf("printf:\n");
			dbgprintout(output[i]);
			printf("_printf:\n");
			/*printf("_printf:\n_output[i]=%s\n", _output[i]);*/
			dbgprintout(_output[i]);
			printf("" RESET_TEXT);
		}
	}

	return (0);
}
