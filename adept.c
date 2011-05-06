#include "Stream.h"
#include "Scope.h"
#include "hash.h"
#include <stdio.h>
#include "Block.h"

#include "ForInNode.h"
#include "RangeNode.h"
#include "CallNode.h"
#include <stdbool.h>

#include "TokenSet.h"
#include "Token.h"
#include "Lexer.h"

int main(int argc, char *argv[]) {
	if(argc > 1) {
		FILE *fp = fopen(argv[1], "r");
		if(fp != NULL) {
			Stream *code = Stream_new(fp);
			TokenSet *tokens = Lexer_analyze(code);
			Stream_delete(code);
			fclose(fp);


			Block *block = Block_new(tokens);
			Scope *global = Scope_new();
			Block_eval(block, global);
			Scope_delete(global);
			Block_delete(block);

			/*
			while(TokenSet_length(tokens) > 0) {
				Token *token = TokenSet_shift(tokens);
				printf("%d: %s\n", token->type, token->value);
				Token_delete(token);
			}
			TokenSet_delete(tokens);
			*/
		} else {
			printf("ERROR: File does not exist.\n");
		}
	} else {
		printf("ERROR: No input file specified.\n");
	}
	return 0;
}
