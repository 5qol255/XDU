#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct
{
    char *name;
    char *mobile_phone;
    char *fixed_phone;
    char *email;
    char *address;
} person;

extern char NONE[5];
extern person GLASSMAN;
person makePerson(char *, char *, char *, char *, char *);

#endif