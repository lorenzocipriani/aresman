/*
 * parse-args.c
 *
 *  Created on: 2017-09-29
 *      Author: Lorenzo Cipriani <lorenzo1974@gmail.com>
 *     Website: https://www.linkedin.com/in/lorenzocipriani
 *
 *  References: "The GNU C Library"
 */

#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

const char *argp_program_version = "aresman 0.1";
const char *argp_program_bug_address = "<lorenzo1974@gmail.com>";

static char doc[] = "Argp example with options and arguments";
static char args_doc[] = "ARG1 ARG2";

static struct argp_option options[] = {
		{ "daemon",  'd',      0, 0, "Run the process as a daemon" },
		{ "verbose", 'v',      0, 0,	"Produce verbose output" },
		{ "output",  'o', "FILE", 0, "Output to FILE instead of standard output" },
		{ 0 }
};

struct arguments {
	char *args[2];
	int daemon, verbose;
	char *output_file;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	/* Get the input argument from argp_parse, which we
	 know is a pointer to our arguments structure. */
	struct arguments *arguments = state->input;

	switch (key) {
	case 'd':
		arguments->daemon = 1;
		break;
	case 'v':
		arguments->verbose = 1;
		break;
	case 'o':
		arguments->output_file = arg;
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

int main(int argc, char **argv) {

	printf("This is parse-args!\n");

	struct arguments arguments;

	/* Default values. */
	arguments.daemon = 0;
	arguments.verbose = 0;
	arguments.output_file = "-";

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	printf("ARG1 = %s\nARG2 = %s\nOUTPUT_FILE = %s\nDAEMON = %s\nVERBOSE = %s\n",
			arguments.args[0], arguments.args[1], arguments.output_file,
			arguments.daemon ? "yes" : "no",
			arguments.verbose ? "yes" : "no");

	exit(0);
}
