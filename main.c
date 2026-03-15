#include <stdio.h>
#include "lexer.h"

int error_flag = 0;
int main(int argc, char* argv[])
{
    if(argc < 2)									
	{
		printf("Insufficient Number of Arguments\n");
		printf("Usage: ./a.out <sample.c file>\n");		
		return 0;
	}
	initializeLexer(argv);
	Token new_token;
	printf("\n\033[32m=====================================================================\n");
	printf("\033[33m%40s","LEXICAL ANALYZER\n");
	printf("\033[32m=====================================================================\033[0m\n");
	printf("--------------------------------------------------------------------\n");
	printf("| \033[1;36m%-5s\033[0m | \033[1;36m%-30s\033[0m | \033[1;36m%-23s\033[0m |\n", "Sl No", "Token", "Type");
	printf("--------------------------------------------------------------------\n");
	int i = 1;
	while ((new_token = getNextToken()).type != UNKNOWN)
	{
		printf("| \033[1;33m%-5d\033[0m | \033[1;37m%-30s\033[0m |", i++, new_token.lexi);
		switch (new_token.type)
		{
			case KEYWORD:
			{
				printf("\033[1;35m%-25s\033[0m|\n"," KEYWORD");
			}
			break;
			case OPERATOR:
			{
				printf("\033[1;33m%-25s\033[0m|\n"," OPERATOR");
			}
			break;
			case SPECIAL_CHARACTER:
			{
				printf("\033[1;36m%-25s\033[0m|\n"," SYMBOL");
			}
			break;
			case CONSTANT:
			{
				printf("\033[1;31m%-25s\033[0m|\n"," CONSTANT");
			}
			break;
			case LIBRARY_FUNCTION:
			{
				printf("\033[1;34m%-25s\033[0m|\n"," LIBRARY FUNCTION");
			}
			break;
			case IDENTIFIER:
			{
				printf("\033[1;32m%-25s\033[0m|\n"," IDENTIFIER");
			}
			break;
			default:
			{
				printf("\033[1;34mUNKNOWN\033[0m");
				error_flag = 1;
			}
		}
	}
	printf("--------------------------------------------------------------------\n");
    printf("\033[1;32mBuild Success\033[0m\n");
    return 0;
}