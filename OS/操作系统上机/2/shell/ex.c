#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("ex process started\n");
    sleep(10); // 保持进程运行以便观察
    return 0;
}