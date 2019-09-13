/*
 * fy-version.c - libfyaml version example
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

#include <libfyaml.h>

int main(int argc, char *argv[])
{
	printf("%s\n", fy_library_version());
	return EXIT_SUCCESS;
}
