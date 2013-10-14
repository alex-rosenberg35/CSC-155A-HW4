#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include "apue.h"

#define DEBUG 1

/**
 * The lstat function is similar to stat, but when the named file is
 * a symbolic link, lstat returns information about the symbolic link,
 * not the file referenced by the symbolic link.
 */
 
// int stat(const char *restrict pathname, struct stat *restrict buf);
// int lstat(const char *restrict pathname, struct stat *restrict buf);

// based on Figure 4.3
int main(int argc, char *argv[])
{
	// char str[] = "newest: ";
	// strcat(str, "$");
	
	struct stat buf;
	char *ptr;
	
	#ifdef DEBUG
	for (unsigned int c=0; c<argc; c++)
	{
		printf("%u: %s\n", c, argv[c]);
	}
	printf("argc: %d\n", argc);
	#endif
	
	for (int i=1; i<argc; i++)
	{
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			perror("lstat error");
			continue;
		}
		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "** unknown mode **";
		printf("%s\n", ptr);
	}
	
	exit(0);
}

