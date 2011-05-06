#ifndef STREAM_H_
#define STREAM_H_

#include <stdio.h>

typedef struct {
	FILE *fp;
	int fpos;
} Stream;

Stream *Stream_new(FILE *fp);
void Stream_delete(Stream *stream);
int Stream_eof(Stream *stream);
int Stream_getc(Stream *stream);
void Stream_ungetc(Stream *stream, int c);
int Stream_peekc(Stream *stream);

#endif
