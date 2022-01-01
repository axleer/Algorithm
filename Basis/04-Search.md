# 查找

## 哈希表

### 基本问题

1. 哈希函数将键映射为数组的索引.
2. 处理碰撞冲突.

### 常见数据类型的哈希函数

#### 整数

```cpp
int hash(int key, int bound) {
    return key % bound;
}
```

#### 浮点型

```cpp
int hash(double key, int bound) {
    int result = 0;
    auto bytes = reinterpret_cast<char*>(&key); // 将浮点数看作二进制数进行处理.
    for (int i = 0; i < sizeof(key); i++) {
        result = (result * 131 + bytes[i]) % bound; // 权值131来自GCC的源码的实现.
    }
    return result;
}
```

#### 字符串

```cpp
int hash(string key, int bound) {
    int result = 0;
    for (int i = 0; i < key.size(); i++) {
        result = (result * 31 + key[i]) % bound; // 权值31来自Algorithm作者的建议.
    }
    return result;
}
```
