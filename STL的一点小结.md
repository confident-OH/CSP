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

