#ifndef _ADDRESS_BOOK_H_
#define _ADDRESS_BOOK_H_

#include "person.h"

typedef struct node
{
    person data;
    struct node *next;
} node;

node *createNode(person);
node *findNode(node **, int, char *);
void headInsert(node **, node *);
void tailInsert(node **, node *);
int removeNode(node **, person);
node *loadData(const char *);
void saveData(const char *, node **);

#endif