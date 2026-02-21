# 📚 数据结构学习系统 (C 语言版)

> 一套完整的 C 语言数据结构实现，包含可视化演示、代码学习和练习系统，适合学习和面试准备。

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C Standard](https://img.shields.io/badge/C-C99-blue.svg)](https://en.cppreference.com/w/c)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-lightgrey.svg)](README.md)

---

## 📖 目录

- [项目介绍](#-项目介绍)
- [功能特性](#-功能特性)
- [项目结构](#-项目结构)
- [快速开始](#-快速开始)
- [使用示例](#-使用示例)
- [数据结构对比](#-数据结构对比)
- [学习建议](#-学习建议)
- [常见问题](#-常见问题)
- [贡献指南](#-贡献指南)
- [许可证](#-许可证)

---

## 🎯 项目介绍

这是一个用 **纯 C 语言** 实现的数据结构学习项目，涵盖了计算机科学中最常用的数据结构和算法。

**适合人群：**
- 🎓 计算机专业学生（课程学习/考试复习）
- 💼 求职者（面试准备/手写代码）
- 📖 自学者（零基础入门/循序渐进）
- 👨‍🏫 教师（教学演示/实验代码）

**核心目标：**
1. 提供清晰、规范的数据结构实现代码
2. 支持交互式学习和测试
3. 方便在 Linux/Windows 跨平台开发
4. 可作为面试手写代码的参考模板

---

## ✨ 功能特性

| 模块 | 功能 | 状态 |
|-----|------|------|
| **线性表** | 顺序表、单链表 | ✅ 完成 |
| **栈** | 顺序栈、链栈 | ✅ 完成 |
| **队列** | 循环队列、链队列 | ✅ 完成 |
| **树** | 二叉树、二叉搜索树 | ✅ 完成 |
| **堆** | 大顶堆、堆排序 | ✅ 完成 |
| **哈希表** | 链地址法解决冲突 | ✅ 完成 |
| **图** | 邻接矩阵、DFS、BFS、Dijkstra | ✅ 完成 |
| **排序** | 冒泡、选择、插入、快排、归并、堆排 | ✅ 完成 |
| **搜索** | 线性搜索、二分搜索 | ✅ 完成 |

---

## 📁 项目结构

```
data-structures-c/
├── .vscode/                    # VSCode 配置
│   ├── tasks.json              # 编译任务
│   ├── launch.json             # 调试配置
│   └── settings.json           # 工作区设置
├── include/                    # 头文件目录
│   ├── common.h                # 公共定义
│   ├── array_list.h            # 顺序表
│   ├── linked_list.h           # 链表
│   ├── stack.h                 # 栈
│   ├── queue.h                 # 队列
│   ├── binary_tree.h           # 二叉树
│   ├── bst.h                   # 二叉搜索树
│   ├── heap.h                  # 堆
│   ├── hash_table.h            # 哈希表
│   ├── graph.h                 # 图
│   └── sort.h                  # 排序算法
├── src/                        # 源文件目录
│   ├── array_list.c
│   ├── linked_list.c
│   ├── stack.c
│   ├── queue.c
│   ├── binary_tree.c
│   ├── bst.c
│   ├── heap.c
│   ├── hash_table.c
│   ├── graph.c
│   └── sort.c
├── main.c                      # 测试主程序
├── Makefile                    # 构建脚本
├── .gitignore                  # Git 忽略文件
└── README.md                   # 项目说明
```

---

## 🚀 快速开始

### 环境要求

| 系统 | 编译器 | 其他工具 |
|-----|-------|---------|
| **Linux** | GCC 7.0+ | make, gdb |
| **Windows** | MinGW-w64 / MSYS2 | make, gdb |
| **macOS** | Clang / GCC | make, lldb |

### 安装依赖

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install -y build-essential gdb make git
```

**CentOS/RHEL/Fedora:**
```bash
sudo dnf install -y gcc gdb make git
```

**macOS:**
```bash
xcode-select --install
```

### 编译运行

```bash
# 1. 克隆项目
git clone https://github.com/amanannn/data-structures-c.git
cd data-structures-c

# 2. 编译
make

# 3. 运行
./data_structures

# 4. 清理
make clean
```

### VSCode 开发

| 操作 | 快捷键 | 说明 |
|-----|-------|------|
| 编译 | `Ctrl+Shift+B` | 执行 make |
| 调试 | `F5` | 启动 GDB 调试 |
| 运行 | `Ctrl+F5` | 不调试直接运行 |
| 清理 | `Ctrl+Shift+P` → Tasks: Clean | 清理构建文件 |

---

## 💻 使用示例

### 示例 1：顺序表

```c
#include "include/array_list.h"

int main() {
    SeqList L;
    InitList(&L);
    
    // 插入元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);
    
    // 遍历打印
    ListTraverse(L);  // 输出：10 20 30
    
    // 查找元素
    int pos = LocateElem(L, 20);  // 返回：2
    
    // 删除元素
    ElemType e;
    ListDelete(&L, 2, &e);  // e = 20
    
    return 0;
}
```

### 示例 2：链表

```c
#include "include/linked_list.h"

int main() {
    LinkList L;
    InitList_LL(&L);
    
    // 头插法插入
    ListInsert_LL(L, 1, 10);
    ListInsert_LL(L, 1, 20);
    ListInsert_LL(L, 1, 30);
    
    // 遍历：30 20 10
    ListTraverse_LL(L);
    
    // 链表逆置
    ReverseList_LL(L);
    
    // 遍历：10 20 30
    ListTraverse_LL(L);
    
    DestroyList_LL(&L);
    return 0;
}
```

### 示例 3：二叉搜索树

```c
#include "include/bst.h"

int main() {
    BSTree T = NULL;
    
    // 插入节点
    InsertBST(&T, 50);
    InsertBST(&T, 30);
    InsertBST(&T, 70);
    InsertBST(&T, 20);
    InsertBST(&T, 40);
    
    // 中序遍历（有序输出）
    InOrderBST(T);  // 输出：20 30 40 50 70
    
    // 查找
    BSTree node = SearchBST(T, 30);  // 找到返回节点
    
    // 删除
    DeleteBST(&T, 30);
    
    return 0;
}
```

### 示例 4：排序算法

```c
#include "include/sort.h"

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("原数组: ");
    PrintArray(arr, n);
    
    // 快速排序
    QuickSort(arr, 0, n - 1);
    
    printf("排序后: ");
    PrintArray(arr, n);
    
    // 二分查找
    int idx = BinarySearch(arr, n, 25);
    printf("25 的位置: %d\n", idx);
    
    return 0;
}
```

---

## 📊 数据结构对比

| 数据结构 | 查找 | 插入 | 删除 | 空间 | 适用场景 |
|---------|------|------|------|------|---------|
| **顺序表** | O(1) | O(n) | O(n) | O(n) | 随机访问、少插入删除 |
| **链表** | O(n) | O(1)* | O(1)* | O(n) | 频繁插入删除 |
| **栈** | O(n) | O(1) | O(1) | O(n) | LIFO 场景、递归 |
| **队列** | O(n) | O(1) | O(1) | O(n) | FIFO 场景、缓冲 |
| **二叉搜索树** | O(log n) | O(log n) | O(log n) | O(n) | 有序数据、动态查找 |
| **堆** | O(n) | O(log n) | O(log n) | O(n) | 优先队列、TopK |
| **哈希表** | O(1)* | O(1)* | O(1)* | O(n) | 快速查找、去重 |
| **图** | O(V+E) | O(1) | O(E) | O(V²) | 网络、路径、关系 |

> *平均时间复杂度

---

## 📖 学习建议

### 学习路径

```
第 1 周：线性表
├── 顺序表（数组）
└── 链表（单链表、双链表）

第 2 周：栈和队列
├── 顺序栈、链栈
└── 循环队列、链队列

第 3 周：树
├── 二叉树遍历
└── 二叉搜索树

第 4 周：高级结构
├── 堆
├── 哈希表
└── 图

第 5 周：算法
├── 排序算法
└── 搜索算法
```

### 练习建议

1. **先理解原理**：画图理解指针变化和内存布局
2. **手打代码**：不要复制粘贴，亲手敲一遍加深理解
3. **调试跟踪**：使用 GDB 单步执行，观察变量变化
4. **扩展练习**：尝试实现双向链表、红黑树等进阶结构
5. **刷题巩固**：在 LeetCode/牛客网做相关题目

### 调试技巧

```bash
# 编译时添加调试信息
make clean && make

# 启动 GDB 调试
gdb ./data_structures

# GDB 常用命令
(gdb) break main          # 在 main 函数打断点
(gdb) run                 # 运行程序
(gdb) next                # 单步执行
(gdb) print variable      # 打印变量值
(gdb) continue            # 继续执行
(gdb) quit                # 退出
```

---

## ❓ 常见问题

### Q1: 编译时出现 `multiple definition` 错误
**A:** 检查是否有全局变量在多个文件中定义。使用 `extern` 在头文件中声明，在 `.c` 文件中定义。

### Q2: 中文输出乱码
**A:** 确保源文件保存为 UTF-8 编码，终端也设置为 UTF-8。
```bash
export LANG=zh_CN.UTF-8
```

### Q3: Makefile 不工作
**A:** 确保 Makefile 使用 Tab 缩进，不是空格。运行 `make clean` 后重试。

### Q4: GDB 无法命中断点
**A:** 确保编译时添加了 `-g` 标志（Makefile 中已包含）。

### Q5: Windows 下路径问题
**A:** Windows 路径使用 `\\` 或 `/`，Linux 使用 `/`。项目已配置跨平台兼容。

---

## 🤝 贡献指南

欢迎贡献代码！请遵循以下步骤：

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

**代码规范：**
- 遵循 C99 标准
- 函数必须有注释说明
- 变量命名清晰易懂
- 保持代码格式统一

---

## 📄 许可证

本项目采用 **MIT 许可证** - 查看 [LICENSE](LICENSE) 文件了解详情。

---

## 📬 联系方式

- **作者**: amanannn
- **GitHub**: [@amanannn](https://github.com/amanannn/data-structures-c)
- **问题反馈**: 请在 Issues 中提交

---

## 🙏 致谢

感谢以下资源：
- [菜鸟教程](https://www.runoob.com) - 学习资料参考
- [GeeksforGeeks](https://www.geeksforgeeks.org) - 算法实现参考
- 《数据结构与算法分析》- 理论参考

---

