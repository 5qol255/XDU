#include <stdio.h>

void cartesianProduct(char (*)[100], char (*)[200], int); // 求笛卡尔积函数
void output(char (*)[200], FILE *);                       // 输出4元集合的关系
void outputPlus(char (*)[200], int, FILE *);              // 可输出n元集合的关系

int main()
{
    char A[4][100];    // 集合A
    char AxA[16][200]; // 集合A的笛卡尔积
    char mark[16];
    int i, j;
    FILE *f; // 文件指针

    scanf("%s%s%s%s", A[0], A[1], A[2], A[3]); // 输入四个元素
    cartesianProduct(A, AxA, 4);               // 求笛卡尔积
    f = fopen("output.txt", "w");              // 创建并打开一个文件
    // output(AxA, f);
    outputPlus(AxA, 4, f); // 输出到文件
    fclose(f);             // 关闭文件
    return 0;
}

void cartesianProduct(char (*A)[100], char (*AxA)[200], int n)
{
    // 求笛卡尔积
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sprintf(AxA[i * n + j], "<%s,%s>", A[i], A[j]);
}

void output(char (*arr)[200], FILE *f)
{
    // 采用文件操作是因为6000多行输出到终端太慢了
    int i, j;
    for (i = 0xffff; i >= 0; i--) // 1111 1111 1111 1111到0000 0000 0000 0000
    {
        fprintf(f, "{");
        // 1到16位轮流从0变成1的过程
        for (j = 0; j < 16; j++)
        {
            if (i & (0x8000 >> j))         // 1000 0000 0000 0000
                fprintf(f, "%s,", arr[j]); // 写文件
        }
        // 非必要语句，不加的话有时候会多出来逗号，看着不舒服
        if (i != 0)
            fseek(f, -1, SEEK_CUR); // 文件指针前移一位，这样就会让后写的字符串覆盖掉逗号
        fprintf(f, "}\n");
    }
}

void outputPlus(char (*arr)[200], int n, FILE *f)
{ // 原理和output函数一样
    long long i, j;
    long long pn = n * n;
    for (i = (1 << pn) - 1; i >= 0; i--)
    {
        fprintf(f, "{");
        for (j = 0; j < pn; j++)
        {
            if (i & ((1 << pn - 1) >> j))
                fprintf(f, "%s,", arr[j]);
        }
        if (i != 0)
            fseek(f, -1, SEEK_CUR);
        fprintf(f, "}\n");
    }
}