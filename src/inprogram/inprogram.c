/*
 * inprogram.c - libfyaml inprogram YAML example
 *
 * Copyright (c) 2019 Pantelis Antoniou <pantelis.antoniou@konsulko.com>
 *
 * SPDX-License-Identifier: MIT
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <libfyaml.h>

int main(int argc, char *argv[])
{
	static const char *yaml = 
		"invoice: 34843\n"
		"date   : !!str 2001-01-23\n"
		"bill-to: &id001\n"
		"    given  : Chris\n"
		"    family : Dumars\n"
		"    address:\n"
		"        lines: |\n"
		"            458 Walkman Dr.\n"
		"            Suite #292\n";
	struct fy_document *fyd;
	int rc;

	fyd = fy_document_build_from_string(NULL, yaml);
	if (!fyd) {
		fprintf(stderr, "failed to build document");
		return EXIT_FAILURE;
	}

	/* emit the document to stdout */
	rc = fy_emit_document_to_fp(fyd, FYECF_DEFAULT, stdout);
	if (rc)
		fprintf(stderr, "failed to emit document to stdout");

	fy_document_destroy(fyd);

	return !rc ? EXIT_SUCCESS : EXIT_FAILURE;
}
