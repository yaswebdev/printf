#include "../main.h"

extern int errno;

void start_capture()
{
	freopen("./test/.tmp_stdout.txt", "w", stdout);
}

char *end_capture()
{
	char *buffer = 0;
	long length;
	FILE *f;

	freopen("/dev/tty", "w", stdout);

	f = fopen("./test/.tmp_stdout.txt", "rb");
	if (f == NULL)
	{
		perror("Could not open .tmp_stdout.txt");
		exit(errno);
	}

	fseek (f, 0, SEEK_END);
	length = ftell(f);
	fseek (f, 0, SEEK_SET);
	buffer = malloc(length + 1);
	if (buffer == NULL)
	{
		perror("Could not allocate memory");
		exit(errno);
	}
	fread(buffer, 1, length, f);
	fclose (f);

	buffer[length + 1] = '\0';

	return (buffer);
}
