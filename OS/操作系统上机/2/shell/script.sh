#!/bin/bash

# 编译程序
gcc m.c -o m
gcc ex.c -o ex

# 启动 m 并获取其 PID
./m &
m_pid=$!
echo "m 的 PID: $m_pid"

# 等待子进程启动
sleep 1

# 获取子进程的 PID（即 sub/ex 的 PID）
sub_pid=$(pgrep -P $m_pid)
if [ -z "$sub_pid" ]; then
    echo "未找到子进程"
    exit 1
fi

echo "sub 的 PID: $sub_pid"
echo "ex 的 PID: $sub_pid"

# 验证 ex 进程信息
ps -p $sub_pid -o comm=