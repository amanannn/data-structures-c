@echo off
chcp 65001 >nul
echo 🔧 正在编译数据结构程序...

mkdir build 2>nul

gcc -Wall -g -I./include -c src/array_list.c -o build/array_list.o
gcc -Wall -g -I./include -c src/linked_list.c -o build/linked_list.o
gcc -Wall -g -I./include -c src/stack.c -o build/stack.o
gcc -Wall -g -I./include -c src/queue.c -o build/queue.o
gcc -Wall -g -I./include -c src/binary_tree.c -o build/binary_tree.o
gcc -Wall -g -I./include -c src/bst.c -o build/bst.o
gcc -Wall -g -I./include -c src/heap.c -o build/heap.o
gcc -Wall -g -I./include -c src/hash_table.c -o build/hash_table.o
gcc -Wall -g -I./include -c src/graph.c -o build/graph.o
gcc -Wall -g -I./include -c src/sort.c -o build/sort.o
gcc -Wall -g -I./include -c main.c -o build/main.o

gcc -o data_structures.exe build/*.o

if %errorlevel% equ 0 (
    echo ✅ 编译成功！
    echo 🚀 正在运行...
    data_structures.exe
) else (
    echo ❌ 编译失败，请检查错误信息
)
pause