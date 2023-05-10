# clang

## 说明

来源：[clang](https://github.com/adrian-thurston/ragel/blob/ragel-6.10/examples/clang.rl)

官方用于模拟统计c代码

## 使用方法

### 编译

```bash
make
```

### 运行

```bash
./a.out 
```

### 示例

```bash
# ./a.out < test.c 
endline(2): #include <stdio.h>
  word: #include
  word: <stdio.h>
endline(0): 
endline(2): int main(){
  word: int
  word: main(){
endline(1):     printf("helloworld!\n");
  word: printf("helloworld!\n");
endline(1): }
  word: }

```
