#include "Lexer.h"
#include "Block.h"
#include "TokenSet.h"
#include "Token.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int isopchar(unsigned char c) {
	char ops[] = "+-~.$=><&|!@%^*:?/";
	int i, opc = strlen(ops);
	for(i = 0; i < opc; i++) {
		if((unsigned char) ops[i] == c) {
			return 1;
		}
	}
	return 0;
}

TokenSet *Lexer_analyze(Block *code) {
	TokenSet *tokens = TokenSet_new();
	char buffer[256];
	int buffLen = 0;
	TokenType mode = DEFAULT;

	int i;
	unsigned char c;

	int done, decline, escaped;
	char flind; // character that indicated to switch from int to float literal

	for(i = Block_getc(code); i != EOF; i = Block_getc(code)) {
		c = (unsigned char) i;
		done = decline = 0;

		switch(mode) {
			case DEFAULT:
				switch(c) {
					case ' ':
					case '\t':
						mode = SPACE;
						break;
					case '\n':
						mode = PLINE;
						done = 1;
						break;
					case '(':
						mode = POPEN;
						done = 1;
						break;
					case ')':
						mode = PCLOSE;
						done = 1;
						break;
					case '[':
						mode = SQOPEN;
						done = 1;
						break;
					case ']':
						mode = SQCLOSE;
						done = 1;
						break;
					case '{':
						mode = BROPEN;
						done = 1;
						break;
					case '}':
						mode = BRCLOSE;
						done = 1;
						break;
					case ';':
						mode = SEMI;
						done = 1;
						break;
					case ',':
						mode = COMMA;
						done = 1;
						break;
					case '"':
					case '\'':
						mode = LSTRING;
						escaped = 0;
						break;
					case '#':
						mode = COMMENT;
						break;
					default:
						if(isdigit(c)) {
							mode = LINTEGER;
						} else if(isalpha(c) || c == '_') {
							mode = WORD;
						} else if(isopchar(c)) {
							mode = OPERATOR;
						} else {
							printf("ERROR: Unrecognized character '%c' (ASCII: %d)\n", c, c);
							exit(EXIT_FAILURE);
						}
				}
				break;
			case SPACE:
				if(c != ' ' && c != '\t') {
					decline = 1;
				}
				break;
			case LSTRING:
				if(c == '\\') {
					escaped = !escaped;
				} else if(c == buffer[0] && !escaped) {
					done = 1;
				} else {
					escaped = 0;
				}
				break;
			case LINTEGER:
				if(c == '.') {
					unsigned char next = (unsigned char) Block_peekc(code);
					if(isdigit(next)) {
						mode = LFLOAT;
						flind = '.';
					} else {
						decline = 1;
					}
				} else if(c == 'E') {
					mode = LFLOAT;
					flind = 'E';
				} else if(!isdigit(c)) {
					decline = 1;
				}
				break;
			case LFLOAT:
				if(c == 'E' && flind == '.' && buffer[buffLen-1] != '.') {
					flind = 'E';
				} else if(!isdigit(c)) {
					decline = 1;
				}
				break;
			case WORD:
				if(c != '_' && !isalnum(c)) {
					decline = 1;
					if(strcmp(buffer, "for") == 0) {
						mode = FOR;
					} else if(strcmp(buffer, "rof") == 0) {
						mode = ROF;
					} else if(strcmp(buffer, "in") == 0) {
						mode = IN;
					} else if(strcmp(buffer, "while") == 0) {
						mode = WHILE;
					} else if(strcmp(buffer, "elihw") == 0) {
						mode = ELIHW;
					} else if(strcmp(buffer, "def") == 0) {
						mode = DEF;
					} else if(strcmp(buffer, "fed") == 0) {
						mode = FED;
					} else if(strcmp(buffer, "class") == 0) {
						mode = CLASS;
					} else if(strcmp(buffer, "ssalc") == 0) {
						mode = SSALC;
					} else if(strcmp(buffer, "if") == 0) {
						mode = IF;
					} else if(strcmp(buffer, "fi") == 0) {
						mode = FI;
					} else if(strcmp(buffer, "elseif") == 0) {
						mode = ELSEIF;
					} else if(strcmp(buffer, "else") == 0) {
						mode = ELSE;
					} else if(strcmp(buffer, "true") == 0) {
						mode = LTRUE;
					} else if(strcmp(buffer, "false") == 0) {
						mode = LFALSE;
					} else if(strcmp(buffer, "null") == 0) {
						mode = LNULL;
					}
				}
				break;
			case OPERATOR:
				if(!isopchar(c)) {
					decline = 1;
				}
				break;
			case COMMENT:
				if(c == '\n') {
					decline = 1;
				}
				break;
			default:
				// should never get here
				printf("ERROR: Lexer problem. Should have never got here.\n");
				exit(EXIT_FAILURE);
				break;
		}

		if(decline) {
			Block_ungetc(code, i);
			done = 1;
		} else {
			buffer[buffLen++] = c;
			buffer[buffLen] = '\0';
		}

		if(done) {
			TokenSet_push(tokens, Token_new(mode, buffer));
			mode = DEFAULT;
			buffer[0] = '\0';
			buffLen = 0;
		}
	}

	return tokens;
}
