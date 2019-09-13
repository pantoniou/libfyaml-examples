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
	struct fy_document *fyd = NULL;
	int rc, count, ret = EXIT_FAILURE;
	unsigned int invoice_nr;
	char given[256 + 1];

	/* parse the document in one go */
	fyd = fy_document_build_from_string(NULL, yaml);
	if (!fyd) {
		fprintf(stderr, "failed to build document");
		goto fail;
	}

	/* get the invoice number and the given name */
	count = fy_document_scanf(fyd,
			"/invoice %u "
			"/bill-to/given %256s",
			&invoice_nr, given);
	if (count != 2) {
		fprintf(stderr, "Failed to retreive the two items\n");
		goto fail;
	}

	/* print them as comments in the emitted YAML */
	printf("# invoice number was %u\n", invoice_nr);
	printf("# given name is %s\n", given);

	/* set increased invoice number (modify existing node) */
	rc = fy_document_insert_at(fyd, "/invoice",
			fy_node_buildf(fyd, "%u", invoice_nr + 1));
	if (rc) {
		fprintf(stderr, "failed to insert to document\n");
		goto fail;
	}

	/* add spouce (create new mapping pair) */
	rc = fy_document_insert_at(fyd, "/bill-to",
			fy_node_buildf(fyd, "spouse: %s", "Doris"));
	if (rc) {
		fprintf(stderr, "failed to insert to document\n");
		goto fail;
	}

	/* emit the document to stdout */
	rc = fy_emit_document_to_fp(fyd, FYECF_DEFAULT, stdout);
	if (rc) {
		fprintf(stderr, "failed to emit document to stdout");
		goto fail;
	}
	ret = EXIT_SUCCESS;

fail:
	fy_document_destroy(fyd);	/* NULL is OK */

	return ret;
}
