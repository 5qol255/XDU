#pragma GCC optimize(2)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "person.h"
#include "address_book.h"
#include "functions.h"

node *addressBook;

int main()
{
    // 初始化
    setup();
    // 主循环
    loop();
    return 0;
}

void f1()
{ // 新建联系人
    char *name = (char *)calloc(32, sizeof(char));
    char *mobile_phone = (char *)calloc(16, sizeof(char));
    char *fixed_phone = (char *)calloc(16, sizeof(char));
    char *email = (char *)calloc(64, sizeof(char));
    char *address = (char *)calloc(128, sizeof(char));
    memset(name, 0, sizeof(name));
    memset(mobile_phone, 0, sizeof(mobile_phone));
    memset(fixed_phone, 0, sizeof(fixed_phone));
    memset(email, 0, sizeof(email));
    memset(address, 0, sizeof(address));
    input(name, "联系人姓名（必填）：");
    input(mobile_phone, "移动电话（可选）：");
    input(fixed_phone, "固定电话（可选）：");
    input(email, "电子邮箱（可选）：");
    input(address, "地址（可选）：");
    if (strlen(name) == 0)
    {
        printf("名字不能为空！\n");
        free(name);
        free(mobile_phone);
        free(fixed_phone);
        free(email);
        free(address);
        return;
    }
    if (strlen(mobile_phone) == 0)
        strcpy(mobile_phone, NONE);
    if (strlen(fixed_phone) == 0)
        strcpy(fixed_phone, NONE);
    if (strlen(email) == 0)
        strcpy(email, NONE);
    if (strlen(address) == 0)
        strcpy(address, NONE);
    node *temp = findNode(&addressBook, 1, name);
    if (temp == NULL)
    {
        person contact = makePerson(name, mobile_phone, fixed_phone, email, address);
        node *node = createNode(contact);
        tailInsert(&addressBook, node);
        printf("成功！\n");
        return;
    }
    while (True)
    {
        printf("%s已存在，是否更新信息？(Y/N)", name);
        free(name);
        char op;
        int check;
        check = scanf("%c", &op);
        fflush(stdin);
        if (check == 0)
            op = 0;
        if (op == 'y' || op == 'Y')
        {
            char *tmp = NULL;
            if (strcmp(mobile_phone, NONE) != 0)
            {
                tmp = temp->data.mobile_phone;
                temp->data.mobile_phone = mobile_phone;
                free(tmp);
                tmp = NULL;
            }
            else
                free(mobile_phone);
            if (strcmp(fixed_phone, NONE) != 0)
            {
                tmp = temp->data.fixed_phone;
                temp->data.fixed_phone = fixed_phone;
                free(tmp);
                tmp = NULL;
            }
            else
                free(fixed_phone);
            if (strcmp(email, NONE) != 0)
            {
                tmp = temp->data.email;
                temp->data.email = email;
                free(tmp);
                tmp = NULL;
            }
            else
                free(email);
            if (strcmp(address, NONE) != 0)
            {
                tmp = temp->data.address;
                temp->data.address = address;
                free(tmp);
            }
            else
                free(address);
            break;
        }
        else if (op == 'n' || op == 'N')
        {
            free(mobile_phone);
            free(fixed_phone);
            free(email);
            free(address);
            break;
        }
        else
            printf("无效输入！\n");
    }
}

void f2()
{ // 查找联系人
    printf("选择查找方式：\n1.按姓名查找\n2.按移动电话查找\n3.按固定电话查找\n4.按邮箱查找\n5.按地址查找\n");
    int op, check;
    check = scanf("%d", &op);
    fflush(stdin);
    if (check == 0)
    {
        printf("无效输入！\n");
        return;
    }
    char s[256];
    input(s, "输入：");
    node *temp = findNode(&addressBook, op, s);
    if (temp == NULL)
        printf("不存在该联系人，请检查输入或者添加。\n");
    else
    {
        printf("联系人：\n%s\n", temp->data.name);
        if (strlen(temp->data.mobile_phone) != 0)
            printf("移动电话：%s\n", temp->data.mobile_phone);
        if (strlen(temp->data.fixed_phone) != 0)
            printf("固定电话：%s\n", temp->data.fixed_phone);
        if (strlen(temp->data.email) != 0)
            printf("电子邮箱：%s\n", temp->data.email);
        if (strlen(temp->data.address) != 0)
            printf("地址：%s\n", temp->data.address);
    }
}

void f3()
{ // 修改联系人信息
    char *name = (char *)calloc(32, sizeof(char));
    input(name, "输入要修改的联系人姓名：");
    if (strlen(name) == 0)
    {
        printf("名字不能为空！\n");
        free(name);
        return;
    }
    node *temp = findNode(&addressBook, 1, name);
    if (temp == NULL)
        printf("不存在该联系人，请检查输入或者添加。\n");
    else
    {
        char *mobile_phone = (char *)calloc(16, sizeof(char));
        char *fixed_phone = (char *)calloc(16, sizeof(char));
        char *email = (char *)calloc(64, sizeof(char));
        char *address = (char *)calloc(128, sizeof(char));
        input(mobile_phone, "移动电话（可选）：");
        input(fixed_phone, "固定电话（可选）：");
        input(email, "电子邮箱（可选）：");
        input(address, "地址（可选）：");
        if (strlen(mobile_phone) == 0)
            strcpy(mobile_phone, NONE);
        if (strlen(fixed_phone) == 0)
            strcpy(fixed_phone, NONE);
        if (strlen(email) == 0)
            strcpy(email, NONE);
        if (strlen(address) == 0)
            strcpy(address, NONE);
        char *tmp = NULL;
        if (strcmp(mobile_phone, NONE) != 0)
        {
            tmp = temp->data.mobile_phone;
            temp->data.mobile_phone = mobile_phone;
            free(tmp);
            tmp = NULL;
        }
        else
            free(mobile_phone);
        if (strcmp(fixed_phone, NONE) != 0)
        {
            tmp = temp->data.fixed_phone;
            temp->data.fixed_phone = fixed_phone;
            free(tmp);
            tmp = NULL;
        }
        else
            free(fixed_phone);
        if (strcmp(email, NONE) != 0)
        {
            tmp = temp->data.email;
            temp->data.email = email;
            free(tmp);
            tmp = NULL;
        }
        else
            free(email);
        if (strcmp(address, NONE) != 0)
        {
            tmp = temp->data.address;
            temp->data.address = address;
            free(tmp);
        }
        else
            free(address);
        printf("成功！\n");
    }
}

void f5()
{ // 查看所有联系人
    node *head = addressBook;
    while (head->next != NULL)
    {
        head = head->next;
        printf("联系人：\n%s\n", head->data.name);
        printf("%s\n", head->data.mobile_phone);
        printf("%s\n", head->data.fixed_phone);
        printf("%s\n", head->data.email);
        printf("%s\n", head->data.address);
    }
}

void f4()
{ // 删除联系人
    char name[32];
    input(name, "输入要删除的联系人姓名：");
    node *cur = addressBook;
    node *prev = addressBook;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
        if (strcmp(cur->data.name, name) == 0)
        {
            printf("联系人：\n%s\n", cur->data.name);
            printf("%s\n", cur->data.mobile_phone);
            printf("%s\n", cur->data.fixed_phone);
            printf("%s\n", cur->data.email);
            printf("%s\n", cur->data.address);
            char op;
            int check;
            printf("是否删除该联系人？(Y/N)\n");
            check = scanf("%c", &op);
            fflush(stdin);
            if (check != 0 && (op == 'y' || op == 'Y'))
            {
                if (cur->next == NULL)
                    prev->next = NULL;
                else
                    prev->next = cur->next;
                free(cur->data.name);
                free(cur->data.mobile_phone);
                free(cur->data.fixed_phone);
                free(cur->data.email);
                free(cur->data.address);
                free(cur);
                printf("删除成功！\n");
                return;
            }
        }
    }
    printf("不存在该联系人，请检查输入！\n");
}

void f6()
{ // 保存
    saveData("address_book.csv", &addressBook);
    printf("保存成功！\n");
}

void f7()
{ // 退出
    char op;
    int check;
    printf("要在退出前保存吗？(Y/N)\n");
    check = scanf("%c", &op);
    if (check == 0)
        return;
    if (op == 'y' || op == 'Y')
        f6(); // 保存
    exit(0);
}

void setup()
{
    addressBook = loadData("address_book.csv");
    if (addressBook->next == NULL)
        printf("当前通讯录人数为0人\n");
}

void loop()
{
    int op, check;
    while (True)
    {
        printf("选择操作：\n1.新建联系人\n2.查找联系人\n3.修改联系人信息\n4.删除联系人\n5.查看所有联系人\n6.保存\n7.退出\n");
        check = scanf("%d", &op);
        fflush(stdin);
        if (check == 0)
            op = 0;
        switch (op)
        {
        case 1: // 新建联系人
            f1();
            break;
        case 2: // 查找联系人
            f2();
            break;
        case 3: // 修改联系人信息
            f3();
            break;
        case 4: // 删除联系人
            f4();
            break;
        case 5: // 查看所有联系人
            f5();
            break;
        case 6: // 保存
            f6();
            break;
        case 7: // 退出
            f7();
            break;
        default:
            printf("无效输入！\n");
        }
    }
}