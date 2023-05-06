# The Blocks Problem

## 题面翻译

初始时从左到右有 $n$ 个木块，编号为 $0 \ldots n-1$,要求实现下列四种操作：

- `move a onto b` : 把 $a$ 和 $b$ 上方的木块归位，然后把 $a$ 放到 $b$ 上面。
- `move a over b` : 把 $a$ 上方的木块归位，然后把 $a$ 放在 $b$ 所在木块堆的最上方。
- `pile a onto b` : 把 $b$ 上方的木块归位，然后把 $a$ 及以上的木块坨到 $b$ 上面。
- `pile a over b` : 把 $a$ 及以上的木块坨到 $b$ 的上面。
- 一组数据的结束标志为 `quit`，如果有非法指令（如 $a$ 与 $b$ 在同一堆），无需处理。

输出:所有操作输入完毕后，从左到右，从下到上输出每个位置的木块编号。


## 题目描述

[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37


![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/4657c698576c8c299dbbf5655d7dbe63bf148978.png)

## 输入格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/0a0a9b4a15235d9e81d83d5d31ee89ce48870fed.png)

## 输出格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/ca24bcd0ff3af9dc6c1fcefd73c87532e9e05bd4.png)

## 样例 #1

### 样例输入 #1

```
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
```

### 样例输出 #1

```
0: 0
1: 1 9 2 4
2:
3: 3
4:
5: 5 8 7 6
6:
7:
8:
9:
```