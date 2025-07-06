#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct Node
{
    char c;
    float weight;
    int parent, Lchild, Rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;

void CreatHuffmanTree(HuffmanTree &H, int n);
void CreatHuffmanCode(const HuffmanTree &H, HuffmanCode &HC, int n);
void SelectNode(HuffmanTree &H, int n, int &s1, int &s2);

HuffmanTree H;
HuffmanCode HC;
FILE *fin, *fout1, *fout2;

int main()
{
    int n;
    fin = fopen("CharWeight.txt", "r");
    fout1 = fopen("TreeFile.txt", "w");
    fout2 = fopen("CodeFile.txt", "w");

    fscanf(fin, "%d", &n);
    CreatHuffmanTree(H, n);
    CreatHuffmanCode(H, HC, n);
    fclose(fin);
    fclose(fout1);
    fclose(fout2);
    return 0;
}

void CreatHuffmanCode(const HuffmanTree &H, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';
    int start, c, f;
    for (int i = 1; i <= n; i++)
    {
        start = n - 1;
        c = i;
        f = H[i].parent;
        while (f != 0)
        {
            --start;
            if (H[f].Lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = H[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[] cd;
    for (int i = 1; i <= n; i++)
        fprintf(fout2, "%s\n", HC[i]);
}

void CreatHuffmanTree(HuffmanTree &H, int n)
{
    if (n <= 1)
        return;
    H = new HTNode[2 * n];
    for (int i = 1; i <= 2 * n; i++)
        H[i].c = H[i].parent = H[i].Lchild = H[i].Rchild = 0;
    // for (int i = 1; i <= n; i++)
    //     fscanf(fin, "%c %f", &H[i].c, &H[i].weight);
    for (int i = 1; i <= 2 * n; i++)
    {
        char s;
        float t;
        fscanf(fin, "%c%f", &s, &t);
        if (i % 2 == 0)
            H[i / 2].c = s, H[i / 2].weight = t;
    }

    for (int i = n + 1; i < 2 * n; i++)
    {
        int s1, s2;
        SelectNode(H, i - 1, s1, s2);
        H[s1].parent = H[s2].parent = i;
        H[i].Lchild = s1;
        H[i].Rchild = s2;
        H[i].weight = H[s1].weight + H[s2].weight;
    }
    for (int i = 1; i < 2 * n; i++)
        fprintf(fout1, "%c %.2f %d %d %d\n", H[i].c, H[i].weight, H[i].parent, H[i].Lchild, H[i].Rchild);
}

void SelectNode(HuffmanTree &H, int n, int &s1, int &s2)
{
    float m1 = 1e5, m2 = 1e5;
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++)
        if (H[i].parent == 0)
            if (H[i].weight < m1)
            {
                m2 = m1;
                m1 = H[i].weight;
                s2 = s1;
                s1 = i;
            }
            else if (H[i].weight < m2 && H[i].weight != m1)
            {
                m2 = H[i].weight;
                s2 = i;
            }
}