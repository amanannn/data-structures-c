# ========================================
# 数据结构学习系统 - Makefile (Linux)
# ========================================

# 编译器配置
CC = gcc
CFLAGS = -Wall -g -I./include -std=c99
LDFLAGS = 

# 目录配置
SRC_DIR = src
BUILD_DIR = build

# 源文件和目标文件
SRCS = $(wildcard $(SRC_DIR)/*.c) main.c
OBJS = $(SRCS:.c=.o)

# 可执行文件
TARGET = data_structures

# 默认目标
all: $(BUILD_DIR) $(TARGET)
	@echo "✅ 编译成功！可执行文件：$(TARGET)"

# 创建构建目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 链接所有目标文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# 编译源文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理构建文件
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BUILD_DIR)
	@echo "🧹 清理完成"

# 重新编译
rebuild: clean all

# 运行程序
run: $(TARGET)
	@echo "🚀 正在运行..."
	./$(TARGET)

# 帮助信息
help:
	@echo "========================================"
	@echo "  数据结构学习系统 - 编译选项"
	@echo "========================================"
	@echo "  make        - 编译项目"
	@echo "  make run    - 编译并运行"
	@echo "  make clean  - 清理构建文件"
	@echo "  make rebuild - 重新编译"
	@echo "  make help   - 显示帮助"
	@echo "========================================"

# 声明伪目标
.PHONY: all clean rebuild run help