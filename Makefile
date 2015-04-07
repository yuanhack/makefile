# 通用Makefile

CC   := gcc
# 相关源码目录
DIRS := src .
# 相关链接库
LIBS := -lpthread
# 相关编译参数
CFLAGS := -g -Wall

# 可执行程序
EXEC := main

# 搜索所有源码目录里的源文件
SRCS:=$(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
# .c文件所对应的.o文件
OBJS:=$(SRCS:.c=.o)

# 重建隐含规则
%o:%c
	$(CC) -o $@ -c $< $(CFLAGS)

# 作用同上的后缀规则
.c.o:
	$(CC) -o $@ -c $< $(CFLAGS)

all: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)

clean:
	rm -rf $(EXEC) $(OBJS) 
