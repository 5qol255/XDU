#include <stdio.h>
#include <string.h>

#include "person.h"
#include "functions.h"

bool_ strEqual(char *a, char *b)
{
    if (strcmp(a, b) == 0)
        return True;
    return False;
}

int personEqual(person a, person b)
{
    if (strEqual(a.name, b.name))
        return True;
    return False;
}

void input(char *s, const char *tip)
{
    printf("%s", tip);
    scanf("%s", s);
    fflush(stdin);
}
