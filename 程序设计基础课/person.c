#include "person.h"

char NONE[5] = "NONE";
person GLASSMAN = {NONE, NONE, NONE, NONE, NONE};

person makePerson(char *name,
                  char *mobile_phone,
                  char *fixed_phone,
                  char *email,
                  char *address)
{
    person person =
        {
            .name = name,
            .fixed_phone = fixed_phone,
            .mobile_phone = mobile_phone,
            .address = address,
            .email = email};
    return person;
}