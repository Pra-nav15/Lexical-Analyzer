#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"

static char *res_kwords_data[] = { "const","volatile","extern","auto","register","static","signed","unsigned","short","long","double","char","int","float","struct","union","enum","void","typedef",NULL};
static char *res_kwords_non_data[] = { "goto","return","continue","break","if","else","for","while","switch","case","default","sizeof","do",NULL};
static char operators[] = { '/', '+', '*', '-', '%', '=', '<', '>', '~', '&', '!', '^', '|'};
static char symbols[]   = { '(', ')', '{', '}', '[', ']', ':', ',', ';'};
Token token_list[MAX_TOKEN_SIZE];
int token_count = 0;
int token_index = 0;

Token* token;

void initializeLexer(char* argv[])
{
    token = malloc(sizeof(Token));
    char* extn = strstr(argv[1], ".c");
    if (extn != NULL && strcmp(extn, ".c") == 0)
    {
        strcpy(token->filename, argv[1]);
        token->fptr_file = fopen(token->filename, "r");
        if (token->fptr_file == NULL)
        {
            perror("fopen");
            fprintf(stderr, "ERROR: Unable to open the sample file %s\n", token->filename);
        }
    }
    else
    {
        fprintf(stderr, "ERROR: sample file should have .c extension only\n");
        return;
    }
}

Token getNextToken(void)
{
    static int initialized = 0;
    Token t;
    if (!initialized)
    {
        categorizeToken(token);
        initialized = 1;
    }
    if (token_index < token_count)
    {
        return token_list[token_index++];
    }
    t.type = UNKNOWN;
    strcpy(t.lexi, "");
    return t;
}

void categorizeToken(Token* token)
{
    int i = 0;
    char ch;
    while (fread(&ch, 1, 1, token->fptr_file) == 1)
    {
        if(ch == '#')								
		{
            while (fread(&ch, 1, 1, token->fptr_file) == 1 && ch != '\n');
            continue;
        }
        if (ch == '"')
        {
            token->lexi[i++] = ch;
            while (fread(&ch, 1, 1, token->fptr_file) == 1)
            {
                token->lexi[i++] = ch;
                if (ch == '"')
                {
                    break;
                }
            }
            token->lexi[i] = '\0';
            if (token_count >= MAX_TOKEN_SIZE)
            {
                printf("Token buffer overflow\n");
                return;
            }
            strcpy(token_list[token_count].lexi, token->lexi);
            token_list[token_count].type = CONSTANT;
            token_count++;
            i = 0;
            continue;
        }
        if (!isspace(ch) && !strchr(operators, ch) && !strchr(symbols, ch))
        {
            token->lexi[i++] = ch;
        }
        else
        {
            if (i > 0)
            {
                token->lexi[i] = '\0';
                strcpy(token_list[token_count].lexi, token->lexi);
                if (isKeyword(token->lexi))
                {
                    token_list[token_count].type = KEYWORD;
                }
                else if (isOperator(token->lexi))
                {
                    token_list[token_count].type = OPERATOR;
                }
                else if (isSpecialCharacter(token->lexi))
                {
                    token_list[token_count].type = SPECIAL_CHARACTER;
                }
                else if (isConstant(token->lexi))
                {
                    token_list[token_count].type = CONSTANT;
                }
                else if (isIdentifier(token->lexi))
                {
                    token_list[token_count].type = IDENTIFIER;
                }
                else
                {
                    token_list[token_count].type = UNKNOWN;
                }
                token_count++;
                i = 0;
            }
        }
    }
}

int isKeyword(char *str)
{
    int i = 0;
    while (res_kwords_data[i] != NULL)
    {
        if (strcmp(str, res_kwords_data[i]) == 0)
        {
            return KEYWORD;
        }
        i++;
    }
    i = 0;
    while (res_kwords_non_data[i] != NULL)
    {
        if (strcmp(str, res_kwords_non_data[i]) == 0)
        {
            return KEYWORD;
        }
        i++;
    }
    return 0;
}

int isOperator(char *str)
{
    if (strlen(str) != 1)
    {
        return 0;
    }
    for (int i = 0; i < sizeof(operators)/sizeof(char); i++)
    {
        if (str[0] == operators[i])
        {
            return OPERATOR;
        }
    }
    return 0;
}

int isSpecialCharacter(char *str)
{
    if (strlen(str) != 1)
    {
        return 0;
    }
    for (int i = 0; i < sizeof(symbols)/sizeof(char); i++)
    {
        if (str[0] == symbols[i])
        {
            return SPECIAL_CHARACTER;
        }
    }
    return 0;
}

int isConstant(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return CONSTANT;
}

int isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }

    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }
    return IDENTIFIER;
}
