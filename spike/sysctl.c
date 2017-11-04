/*
 * sysctl.c
 *
 *  Created on: 2017-10-04
 *      Author: Lorenzo Cipriani <lorenzo1974@gmail.com>
 *     Website: https://www.linkedin.com/in/lorenzocipriani
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <unistd.h> */
#include <sys/sysctl.h>

int main(int argc, char **argv) {

	/* Hold relevant information from sysctl items */
	struct list {
		char *name;
		struct ctlname *list;
		int size;
		int index;
	};

	struct ctlname kernNames[] = CTL_KERN_NAMES;
	struct ctlname vmNames[] = CTL_VM_NAMES;
	struct ctlname hwNames[] = CTL_HW_NAMES;
	struct ctlname userNames[] = CTL_USER_NAMES;

	int lists = 4;
	struct list sysctlItems[4] = {
			{ "kern", kernNames, KERN_MAXID, CTL_KERN },
			{ "vm", vmNames, VM_MAXID, CTL_VM },
			{ "hw", hwNames, HW_MAXID, CTL_HW },
			{ "user", userNames, USER_MAXID, CTL_USER }
	};

	int i, j, error;
	char buffer[BUFSIZ];
	/* Cycle through each sysctl group */
	for (i = 0; i < lists; i++) {

		printf("Parse sysctl group: %s (%d items)\n", sysctlItems[i].name, sysctlItems[i].size);

		for (j = 1; j < sysctlItems[i].size; j++) {
			/* get the type of data */
			int type = sysctlItems[i].list[j].ctl_type;
			/*
			 There are 5 sysctl types of data
			 CTLTYPE_INT/STRING/QUAD are simple data types that can be printed as is
			 CTLTYPE_NODE/OPAQUE are complex data types that require specific parsing
			 */
			if ((type == CTLTYPE_INT) || (type == CTLTYPE_STRING) || (type == CTLTYPE_QUAD)) {

				/* Create a Management Information Base (MIB) to hold sysctl data */
				int mib[2] = { sysctlItems[i].index, j };
				size_t size = BUFSIZ;

				/* Read a sysctl item */
				error = sysctl(mib, 2, buffer, &size, NULL, 0);
				printf("%s.%s = ", sysctlItems[i].name, sysctlItems[i].list[j].ctl_name);
				if (error) {
					printf("[Error: %s] ", strerror(error));
				}

				/* store the values according to their data types */
				if (type == CTLTYPE_INT) {
					printf("%u\n", *(int *) buffer);
				} else if (type == CTLTYPE_STRING) {
					printf("%s\n", buffer);
				} else if (type == CTLTYPE_QUAD) {
					printf("%qd\n", *(quad_t *) buffer);
				}
			} else if (type == CTLTYPE_NODE) {
				printf("%s.%s = CTLTYPE_NODE\n", sysctlItems[i].name, sysctlItems[i].list[j].ctl_name);

			} else if (type == CTLTYPE_OPAQUE) {
				printf("%s.%s = CTLTYPE_OPAQUE\n", sysctlItems[i].name, sysctlItems[i].list[j].ctl_name);
			}
		}
		printf("\n");
	}

	exit(0);
}
