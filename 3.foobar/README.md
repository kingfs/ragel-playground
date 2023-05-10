# atoi

## 说明

foobar项目，用于演示如何编写ragel代码，生产c代码，将判断输入字符串是否是`foo`或者`bar`

## 使用方法

### 编译

```bash
make
```

### 运行

```bash
./a.out [待验证字符串]
```

### 示例

```bash
# ./a.out foo
result = 1

# ./a.out bar
result = 1

# ./a.out barbar
result = 0

```
