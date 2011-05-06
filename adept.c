#include "Block.h"
#include "Scope.h"
#include "hash.h"
#include <stdio.h>

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
			//Scope *gs = Scope_new();
			Block *code = Block_new(fp, 0, 0);
			TokenSet *tokens = Lexer_analyze(code);
			while(TokenSet_length(tokens) > 0) {
				Token *token = TokenSet_shift(tokens);
				printf("%d: %s\n", token->type, token->value);
				Token_delete(token);
			}
			TokenSet_delete(tokens);
			//Block_eval(code, gs);
			Block_delete(code);
			//Scope_delete(gs);
			fclose(fp);
		} else {
			printf("ERROR: File does not exist.\n");
		}
	} else {
		printf("ERROR: No input file specified.\n");
	}
	return 0;
}
