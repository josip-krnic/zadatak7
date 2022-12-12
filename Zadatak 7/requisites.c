#include "requisites.h"
#include <stdio.h>
#include <string.h>

int readFromConsole(Position P)
{
	char command[MAX_COMMAND_LENGTH] = "\0";
	char directoryName[MAX_DIRECTORY_LENGTH] = "\0";
	char buffer[MAX_CHAR_NUMBERS] = {0};
	
	printf("%s/>", P->name);
	gets(buffer);
	sscanf(buffer, " %s %s", command, directoryName);
	
	if (!strcmp(command, "dir"))
	{
		printContent(P);
	}
	
	if (!strcmp(command, "exit"))
	{
		return 0;
	}
	
	else if (!strcmp(command, "md") || !strcmp(command, "mkdir"))
	{
		Directory A;
		Position Q = (Position)malloc(sizeof(Directory));
		strcpy(A.name, directoryName);
		A.child = NULL;
		A.sibling = NULL;
		Q = &A;
		P->child = makeDirectory(P->child, Q);
	}
	
	return 0;
}

Position makeDirectory(Position P, Position Q)
{
	if (P == NULL)
		return Q;

	if (strcmp(P->name, Q->name) > 0)
	{
		Q->sibling = P;
		return Q;
	}

	P->sibling = makeDirectory(P->sibling, Q);
	return P;
}

int printContent(Position P)
{
	Position Q = P->child;
	//Q = P;
	while (Q != NULL)
	{
		printf("\n %s\n", P->name);
		Q = Q->sibling;
	}

	return 0;
}
