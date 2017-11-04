/*
 * subprocess.c
 *
 *  Created on: 2017-09-30
 *      Author: Lorenzo Cipriani <lorenzo1974@gmail.com>
 *     Website: https://www.linkedin.com/in/lorenzocipriani
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	char* args[] = {"", NULL};
	int subproc;

	printf("This is subprocess that runs: %s\n", argv[1]);
	printf("Arguments: %d\n", argc);

	if (argc > 2) {
		int j = 0;
		for (int i=1; i<argc; i++) {
			args[j++] = argv[i];
		}
	}
	subproc = execvp(argv[1], args);
	printf("Exit: %s\n", strerror(subproc));
	return subproc;

}
