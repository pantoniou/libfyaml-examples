/*
 * binary.c - libfyaml binary YAML example
 *
 * Copyright (c) 2020 Pantelis Antoniou <pantelis.antoniou@konsulko.com>
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
	static const uint8_t binary_data[] = {
		0x00, 0x01, 0x02, 0x03,
		0x40, 0x41, 0x43, 0x44,
		0xfc, 0xfd, 0xfe, 0xff
	};
	struct fy_document *fyd = NULL;
	struct fy_node *fyn;
	int rc, ret = EXIT_FAILURE;

	fyd = fy_document_create(NULL);
	if (!fyd) {
		fprintf(stderr, "failed to create document");
		goto fail;
	}

	fyn = fy_node_create_scalar(fyd, (const char *)binary_data, sizeof(binary_data));
	if (!fyn) {
		fprintf(stderr, "failed to create binary data scalar node");
		goto fail;
	}

	rc = fy_document_set_root(fyd, fyn);
	if (rc) {
		fprintf(stderr, "failed to set document root\n");
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
