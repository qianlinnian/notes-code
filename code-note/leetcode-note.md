1. 哈希
    unordered_set

2. 字符串 
    stringstream 把字符串改变为了流
    ```cpp
    stringstream ss(paragraph); //便于 识别 单词
    ```

    1. 查找和截取
        - `substr(pos, len)` - 从位置 pos 开始，截取 len 个字符（默认到末尾）
        - `find(str)` - 返回子串首次出现的位置，未找到返回 string::npos
        - `find(str, pos)` - 从位置 pos 开始查找子串
        - `rfind(str)` - 从后向前查找子串

    2. 长度和容量
        - `length()` 或 `size()` - 返回字符串长度
        - `empty()` - 检查字符串是否为空
        - `capacity()` - 返回分配的容量

    3. 添加和删除
        - `push_back(ch)` - 末尾添加字符
        - `pop_back()` - 删除末尾字符
        - `append(str)` - 末尾追加字符串
        - `insert(pos, str)` - 在位置 pos 插入字符串
        - `erase(pos, len)` - 删除从 pos 开始的 len 个字符
        - `clear()` - 清空字符串

    4. 比较和替换
        - `compare(str)` - 字符串比较，返回 0/正数/负数
        - `replace(pos, len, str)` - 替换从 pos 开始的 len 个字符为 str

    5. 访问
        - `at(index)` 或 `[index]` - 访问指定位置的字符（at 会检查越界）

    6. 转换函数
        - `stoi(str)` - 字符串转整数
        - `stof(str)` 或 `stod(str)` - 字符串转浮点数
        - `to_string(num)` - 数字转字符串
        - `tolower(ch)` - 字符转小写
        - `toupper(ch)` - 字符转大写
    7. 增删改查
        - `insert(pos, str)` - 在位置 pos 插入字符串
        - `erase(pos, len)` - 删除从 pos 开始的 len 个字符
        - `replace(pos, len, str)` - 替换从 pos 开始的 len 个字符为 str
        - `find(str)` - 查找子串位置
        - `substr(pos, len)` - 截取子串
        - `pop_back()` - 删除末尾字符
        - `push_back(ch)` - 末尾添加字符
    8. 
        -
 
        ```