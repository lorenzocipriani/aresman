/*
 * sysconf.c
 *
 *  Created on: 2017-10-03
 *      Author: Lorenzo Cipriani <lorenzo1974@gmail.com>
 *     Website: https://www.linkedin.com/in/lorenzocipriani
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	int value_SC_CHILD_MAX = sysconf(_SC_CHILD_MAX);
	if (value_SC_CHILD_MAX < 0)
		printf("CHILD_MAX error: %s\n", strerror(errno));
	printf("CHILD_MAX: %d\n", value_SC_CHILD_MAX);

	int value_SC_OPEN_MAX = sysconf(_SC_OPEN_MAX);
	if (value_SC_OPEN_MAX < 0)
		printf("OPEN_MAX error: %s\n", strerror(errno));
	printf("OPEN_MAX: %d\n", value_SC_OPEN_MAX);

	int value_SC_STREAM_MAX = sysconf(_SC_STREAM_MAX);
	if (value_SC_STREAM_MAX < 0)
		printf("STREAM_MAX error: %s\n", strerror(errno));
	printf("STREAM_MAX: %d\n", value_SC_STREAM_MAX);

	int value_SC_NGROUPS_MAX = sysconf(_SC_NGROUPS_MAX);
	if (value_SC_NGROUPS_MAX < 0)
		printf("NGROUPS_MAX error: %s\n", strerror(errno));
	printf("NGROUPS_MAX: %d\n", value_SC_NGROUPS_MAX);

	int value_SC_SAVED_IDS = sysconf(_SC_SAVED_IDS);
	if (value_SC_SAVED_IDS < 0)
		printf("SAVED_IDS error: %s\n", strerror(errno));
	printf("SAVED_IDS: %d\n", value_SC_SAVED_IDS);

	int value_SC_VERSION = sysconf(_SC_VERSION);
	if (value_SC_VERSION < 0)
		printf("VERSION error: %s\n", strerror(errno));
	printf("VERSION: %d\n", value_SC_VERSION);

	int value_SC_FSYNC = sysconf(_SC_FSYNC);
	if (value_SC_FSYNC < 0)
		printf("FSYNC error: %s\n", strerror(errno));
	printf("FSYNC: %d\n", value_SC_FSYNC);

	int value_SC_MAPPED_FILES = sysconf(_SC_MAPPED_FILES);
	if (value_SC_MAPPED_FILES < 0)
		printf("MAPPED_FILES error: %s\n", strerror(errno));
	printf("MAPPED_FILES: %d\n", value_SC_MAPPED_FILES);

	int value_SC_MEMLOCK_RANGE = sysconf(_SC_MEMLOCK_RANGE);
	if (value_SC_MEMLOCK_RANGE < 0)
		printf("MEMLOCK_RANGE error: %s\n", strerror(errno));
	printf("MEMLOCK_RANGE: %d\n", value_SC_MEMLOCK_RANGE);

}
