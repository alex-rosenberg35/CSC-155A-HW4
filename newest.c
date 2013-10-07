#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DEBUG 1

int main(int argc, char *argv[])
{
	char str[] = "newest: ";
	strcat(str, "$");
	
	#ifdef DEBUG
	for (unsigned int c=0; c<argc; c++)
	{
		printf("%u: %s\n", c, argv[c]);
	}
	printf("argc: %d\n", argc);
	#endif
	
	printf("Not implemented\n");
	
	// perror("error");
	
	exit(0);
}
