STL小结：

1. 优先队列默认为降序排列。

2. priority_queue<Type, Container, Functional>其中container只能为vector, deque.

3. greater<>，**基本类型可以用这个仿函数声明为升序排列。**

4. 结构体重载运算符的例子:

    ```c++
    struct node{
        ll x,y;
    };
    bool operator < (const node& a,const node& b)
    {
        if(a.x<b.x) return true;
        else if(a.x==b.x&&a.y<b.y) return true;
        else return false;
    }
    ```

5. vector排序后为升序排列：

    ```C++
    vector<int> h = {1, 4, 2, 43, 1, 9};
        sort(h.begin(), h.end());
    // 结果为1 1 2 4 9 43
    ```

6. 科学计数法：1e5 == 100000

7. set容器用法

    ```
    set的各成员函数列表如下:
    
    1. begin()--返回指向第一个元素的迭代器
    
    2. clear()--清除所有元素
    
    3. count()--返回某个值元素的个数
    
    4. empty()--如果集合为空，返回true
    
    5. end()--返回指向最后一个元素的迭代器
    
    6. equal_range()--返回集合中与给定值相等的上下限的两个迭代器
    
    7. erase()--删除集合中的元素
    
    8. find()--返回一个指向被查找到元素的迭代器
    
    9. get_allocator()--返回集合的分配器
    
    10. insert()--在集合中插入元素
    ```

8. map用法

    ```
    mapStudent.insert(map<int, string>::value_type (1, "student_one"));
    // 使用迭代器遍历
    map<int, string>::iterator  iter;  
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
    {  
          cout<<iter->first<<"   "<<iter->second<<endl;  
    }  
    //删除
    //如果要删除1,用迭代器删除  
           map<int, string>::iterator iter;  
           iter = mapStudent.find(1);  
           mapStudent.erase(iter);  
    //如果要删除1，用关键字删除  
           int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0 
    ```

9. std::ios::sync_with_stdio(false)



string 方法摘抄

string 初始化

```c++
string s1();  // si = ""
string s2("Hello");  // s2 = "Hello"
string s3(4, 'K');  // s3 = "KKKK"
string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
```

string 对象赋值

```c++
string s1;
s1 = "Hello";  // s1 = "Hello"
s2 = 'K';  // s2 = "K”
string s1("12345"), s2;
s3.assign(s1);  // s3 = s1
s2.assign(s1, 1, 2);  // s2 = "23"，即 s1 的子串(1, 2)
s2.assign(4, 'K');  // s2 = "KKKK"
s2.assign("abcde", 2, 3);  // s2 = "cde"，即 "abcde" 的子串(2, 3)
```

string 子串

```c++
string s1 = "this is ok";
string s2 = s1.substr(2, 4);  // s2 = "is i"
s2 = s1.substr(2);  // s2 = "is is ok"
```

string 查找字符串

```
string 类有一些查找子串和字符的成员函数，它们的返回值都是子串或字符在 string 对象字符串中的位置（即下标）。如果查不到，则返回 string::npos。string: :npos 是在 string 类中定义的一个静态常量。这些函数如下：

    find：从前往后查找子串或字符出现的位置。
    rfind：从后往前查找子串或字符出现的位置。
    find_first_of：从前往后查找何处出现另一个字符串中包含的字符。例如：
    s1.find_first_of("abc");  //查找s1中第一次出现"abc"中任一字符的位置
    find_last_of：从后往前查找何处出现另一个字符串中包含的字符。
    find_first_not_of：从前往后查找何处出现另一个字符串中没有包含的字符。
    find_last_not_of：从后往前查找何处出现另一个字符串中没有包含的字符。
```

string 转sstream

```c++
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string src("Avatar 123 5.2 Titanic K");
    istringstream istrStream(src); //建立src到istrStream的联系
    string s1, s2;
    int n;  double d;  char c;
    istrStream >> s1 >> n >> d >> s2 >> c; //把src的内容当做输入流进行读取
    ostringstream ostrStream;
    ostrStream << s1 << endl << s2 << endl << n << endl << d << endl << c <<endl;
    cout << ostrStream.str();
    return 0;
}
```

