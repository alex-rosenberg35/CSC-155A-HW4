#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
// #include "apue.h"

#define DEBUG 0

int main(int argc, char *argv[])
{
	// char str[] = "newest: ";
	// strcat(str, "$");
	
	struct stat buf;
	time_t newest_time = 0;
	int newest_idx = -1;
	
	#if defined DEBUG && DEBUG == 1
	for (unsigned int c=0; c<argc; c++)
	{
		printf("%u: %s\n", c, argv[c]);
	}
	printf("argc: %d\n", argc);
	#endif
	
	for (int i=1; i<argc; i++)
	{
		if (stat(argv[i], &buf) < 0) {
			perror("stat error");
			continue;
		}
		
		#if defined DEBUG && DEBUG == 1
		printf("%s: st_mtime = %d\n", argv[i], buf.st_mtime);
		#endif
		
		if (buf.st_mtime > newest_time) {
			newest_time = buf.st_mtime;
			newest_idx = i;
		}
	}
	
	if (newest_idx > 0) {
		printf("newest: %s\n", argv[newest_idx]);
	}
	
	exit(0);
}


