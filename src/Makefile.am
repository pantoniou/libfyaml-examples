AM_CFLAGS = -std=gnu11 $(LIBFYAML_CFLAGS)
AM_LDFLAGS = $(LIBFYAML_LIBS)

bin_PROGRAMS = 
noinst_PROGRAMS =

bin_PROGRAMS += libfyaml-version

libfyaml_version_SOURCES = \
	version/version.c

bin_PROGRAMS += libfyaml-inprogram

libfyaml_inprogram_SOURCES = \
	inprogram/inprogram.c

bin_PROGRAMS += libfyaml-binary

libfyaml_binary_SOURCES = \
	binary/binary.c
