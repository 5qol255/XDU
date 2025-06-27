#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "person.h"

typedef enum
{
    False,
    True
} bool_;

bool_ strEqual(char *, char *);
int personEqual(person, person);
void input(char *, const char *);
void setup();
void loop();

#endif