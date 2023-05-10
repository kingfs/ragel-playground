# ragel graph

## 依赖

```bash
apt install -y graphviz
```

## 输出状态图

```bash
# output dot
ragel -V -p  -o foobar.dot foobar.rl

# generate png
dot -Tpng foobar.dot -o foobar.png
```
