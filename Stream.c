#include "Stream.h"
#include "NodeSet.h"
#include "Scope.h"
#include "Lexer.h"
#include <stdlib.h>
#include <stdio.h>

Stream *Stream_new(FILE *fp) {
	Stream *stream = malloc(sizeof(Stream));
	stream->fp = fp;
	return stream;
}

void Stream_delete(Stream *stream) {
	free(stream);
}

int Stream_eof(Stream *stream) {
	return feof(stream->fp);
}

int Stream_getc(Stream *stream) {
	return fgetc(stream->fp);
}

void Stream_ungetc(Stream *stream, int c) {
	ungetc(c, stream->fp);
}

int Stream_peekc(Stream *stream) {
	int c = fgetc(stream->fp);
	ungetc(c, stream->fp);
	return c;
}
