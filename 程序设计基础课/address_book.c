#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "address_book.h"
#include "person.h"
#include "functions.h"

node *createNode(person data)
{
    node *temp = (node *)malloc(sizeof(node));
    memset(temp, 0, sizeof(temp));
    if (temp == NULL)
        return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void tailInsert(node **pointerToHead, node *Node)
{
    // 寻找
    node *head = *pointerToHead;
    while (head->next != NULL)
        head = head->next;
    // 插入
    head->next = Node;
}

void headInsert(node **pointerToHead, node *Node)
{
    node *head = *pointerToHead;
    Node->next = head->next;
    head->next = Node;
}

node *findNode(node **pointerToHead, int w, char *s)
{
    node *head = *pointerToHead;
    if (w == 1)
        while (head->next != NULL)
        {
            head = head->next;
            if (strEqual(head->data.name, s))
                return head;
        }
    else if (w == 2)
        while (head->next != NULL)
        {
            head = head->next;
            if (strEqual(head->data.mobile_phone, s))
                return head;
        }
    else if (w == 3)
        while (head->next != NULL)
        {
            head = head->next;
            if (strEqual(head->data.fixed_phone, s))
                return head;
        }
    else if (w == 4)
        while (head->next != NULL)
        {
            head = head->next;
            if (strEqual(head->data.email, s))
                return head;
        }
    else if (w == 5)
        while (head->next != NULL)
        {
            head = head->next;
            if (strEqual(head->data.address, s))
                return head;
        }
    return NULL;
}

int removeNode(node **pointerToHead, person data)
{
    node *cur = *pointerToHead;
    node *prev = *pointerToHead;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
        if (personEqual(cur->data, data))
        {
            if (cur->next == NULL)
                prev->next = cur->next;
            else
                prev->next = NULL;
            free(cur->data.name);
            free(cur->data.mobile_phone);
            free(cur->data.fixed_phone);
            free(cur->data.email);
            free(cur->data.address);
            free(cur);
            return 1;
        }
    }
    return 0;
}

void saveData(const char *path, node **A)
{
    FILE *f;
    f = fopen(path, "w");
    node *head = *A;
    while (head->next != NULL)
    {
        head = head->next;
        fprintf(f, "%s,%s,%s,%s,%s\r\n",
                head->data.name, head->data.mobile_phone,
                head->data.fixed_phone, head->data.email, head->data.address);
    }
    fclose(f);
}

node *loadData(const char *path)
{
    node *A = (node *)malloc(sizeof(node));
    memset(A, 0, sizeof(A));
    A->data = GLASSMAN;
    A->next = NULL;
    FILE *f;
    f = fopen(path, "r");
    if (f == NULL)
    {
        fclose(f);
        return A;
    }
    char str[540];
    char *temp = NULL;
    while (fgets(str, 540, f) != NULL)
    {
        char *name = (char *)malloc(64 * sizeof(char));
        char *fixed_phone = (char *)malloc(32 * sizeof(char));
        char *mobile_phone = (char *)malloc(32 * sizeof(char));
        char *email = (char *)malloc(128 * sizeof(char));
        char *address = (char *)malloc(256 * sizeof(char));
        memset(name, 0, sizeof(name));
        memset(mobile_phone, 0, sizeof(mobile_phone));
        memset(fixed_phone, 0, sizeof(fixed_phone));
        memset(email, 0, sizeof(email));
        memset(address, 0, sizeof(address));
        temp = strtok(str, ",");
        strcpy(name, temp);
        temp = strtok(NULL, ",");
        strcpy(mobile_phone, temp);
        temp = strtok(NULL, ",");
        strcpy(fixed_phone, temp);
        temp = strtok(NULL, ",");
        strcpy(email, temp);
        temp = strtok(NULL, ",");
        strcpy(address, temp);
        temp = strrchr(address, '\n');
        *temp = '\0';
        temp = strrchr(address, '\r');
        *temp = '\0';
        person person = makePerson(name, mobile_phone, fixed_phone, email, address);
        node *node = createNode(person);
        tailInsert(&A, node);
    }
    fclose(f);
    return A;
}