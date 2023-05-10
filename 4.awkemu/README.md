# awkemu

## 说明

来源：[awkemu](https://github.com/adrian-thurston/ragel/blob/ragel-6.10/examples/awkemu.rl)

官方用于模拟awk，对比与awk的性能差异

核心用于统计文本中的单词数量

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
# ./a.out  < test.case 
endline(4): a b ab abc
  word: a
  word: b
  word: ab
  word: abc

```
