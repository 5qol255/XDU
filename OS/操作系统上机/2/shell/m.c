#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execl("./ex", "ex", NULL); // 子进程替换为 ex 程序
        perror("execl failed");
        return 1;
    }
    else if (pid > 0)
    {
        wait(NULL); // 父进程等待子进程
    }
    else
    {
        perror("fork failed");
        return 1;
    }
    return 0;
}