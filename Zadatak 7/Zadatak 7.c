#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "requisites.h"


int main()
{
    int choice;
    Position head;

    choice = 0;
    head = (Position)malloc(sizeof(Directory));
    head->child = NULL;
    head->sibling = NULL;
    strcpy(head->name, "C:");
    
    
    while (!choice)
        choice = readFromConsole(head);

    return 0;
}

