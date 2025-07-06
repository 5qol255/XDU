#include <iostream>
#include <string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
    char *data;
    int len;
} Str;

int StrLength(Str &s);
int StrAssign(Str &s, const char *t);
Str StrConcat(Str &s1, Str &s2);
Str SubStr(Str &s, int i, int len);
int StrCmp(Str &s1, Str &s2);

int StrIndex(Str &s, Str &t, int pos);
int StrInsert(Str &s, int i, Str &t);
int StrDelete(Str &s, int i, int len);
void StrRep(Str &s, Str &t, Str &r);

int main()
{
    return 0;
}

int StrLength(Str &s)
{
    int i;
    for (i = 0; s.data[i] != '\0'; i++)
        ;
    s.len = i;
    return s.len;
}

int StrAssign(Str &s, const char *t)
{
    int len;
    for (len = 0; t[len] != '\0'; len++)
        ;
    s.len = len;
    s.data = new char[len + 10];
    memset(s.data, 0, sizeof(s.data));
    for (int i = 0; i < len; i++)
        s.data[i] = t[i];
    return len;
}

Str StrConcat(Str &s1, Str &s2)
{
    Str s;
    int len1 = StrLength(s1), len2 = StrLength(s2);
    s.len = len1 + len2;
    s.data = new char[s.len + 10];
    memset(s.data, 0, sizeof(s.data));
    int i;
    for (i = 0; i < len1; i++)
        s.data[i] = s1.data[i];
    for (; i < s.len; i++)
        s.data[i] = s2.data[i - len1];
    return s;
}

Str SubStr(Str &s, int i, int len)
{
    Str ns;
    ns.len = len;
    ns.data = new char[len + 10];
    memset(ns.data, 0, sizeof(ns.len));
    for (int j = 0; j < len; j++)
        ns.data[j] = s.data[i + j];
    return ns;
}

int StrCmp(Str &s1, Str &s2)
{
    int i;
    for (i = 0; s1.data[i] != '\0' && s2.data[i] != '\0'; i++)
        if (s1.data[i] < s2.data[i])
            return -1;
        else if (s1.data[i] > s2.data[i])
            return 1;
    if (s1.data[i] == '\0' && s2.data[i] == '\0')
        return 0;
    else if (s1.data[i] == '\0')
        return -1;
    return 1;
}

int StrInsert(Str &s, int i, Str &t)
{
    int lens = StrLength(s), lent = StrLength(t), len = lens + lent;
    if (i > lens || i < 0)
        return 0;
    char *newdata = new char[len + 10];
    int j, k;
    for (j = 0; j < i; j++)
        newdata[j] = s.data[j];
    for (k = 0; k < lent; k++)
        newdata[j + k] = t.data[k];
    for (; j < lens; j++)
        newdata[j + k] = s.data[j];
    s.len = lens + lent;
    char *tmp = s.data;
    s.data = newdata;
    delete tmp;
    return lent;
}

int StrDelete(Str &s, int i, int len)
{
    int lens = StrLength(s);
    if (i < 0 || i >= len || i + len - 1 >= lens)
        return 0;
    for (int j = 0; j < len; j++)
        s.data[i + j] = s.data[i + j + len];
    return len;
}

int StrIndex(Str &s, Str &t, int pos)
{
    int lens = StrLength(s), lent = StrLength(t);
    if (pos < 0 || pos >= lens)
        return -1;

    int i = pos, j = 0;
    while (i < lens && j < lent)
    {
        if (s.data[i] == t.data[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= lent)
        return i - lent;
    else
        return -1;
}

void StrRep(Str &s, Str &t, Str &r)
{
    int pos = StrIndex(s, t, 0), last = 0;
    if (pos == -1)
        return;
    Str ns, tmp;
    StrAssign(ns, "");
    while (pos != -1)
    {
        tmp = SubStr(s, last, pos - last + 1);
        ns = StrConcat(ns, tmp);
        ns = StrConcat(ns, r);
        last = pos + t.len;
        pos = StrIndex(s, t, pos);
        cout << ns.data;
    }
    delete s.data;
    s = ns;
}