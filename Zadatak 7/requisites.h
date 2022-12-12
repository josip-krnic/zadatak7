#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHAR_NUMBERS 50
#define MAX_COMMAND_LENGTH 10
#define MAX_DIRECTORY_LENGTH 40
#define ERROR 1

typedef struct Directory* Position;

typedef struct Directory {
    char name[MAX_DIRECTORY_LENGTH];
    Position child;
    Position sibling;
} Directory;

// md, cd Directory, cd.., Directory, exit

int readFromConsole(Position P);
Position makeDirectory(Position P, Position Q);
int printContent(Position P);
int changeDirectory(const char* directoryName);
