/** 学习用栈来解决四则运算问题
 *
 */
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
struct node{
    double num;
    char ch;
    bool flag;
};

string str;
stack<node> s; // 运算符
queue<node> q; //后缀表达式
map<char, int> op; //符号优先级

void change()
{
    double num;
    node item;
    for(int i = 0; i<str.size();){
        if(str[i]>='0'&&str[i]<='9'){
            item.flag = true;
            item.num = str[i++] - '0';
            while(i<str.size()&&str[i]>='0'&&str[i]<='9'){
                item.num = item.num*10 + str[i] - '0';
                i++;
            }
            q.push(item);
        }
        else{
            item.flag = false;
            while(!s.empty()&& op[str[i]]<=op[s.top().ch]){
                q.push(s.top());
                s.pop();
            }
            item.ch = str[i];
            s.push(item);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double cal()
{
    double item1, item2;
    node cur, item;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag == true){
            s.push(cur);
        }
        else{
            item2 = s.top().num;
            s.pop();
            item1 = s.top().num;
            s.pop();
            item.flag = true;
            if(cur.ch == '+') item.num = item1+item2;
            if(cur.ch == '-') item.num = item1-item2;
            if(cur.ch == '*') item.num = item1*item2;
            if(cur.ch == '/') item.num = item1/item2;
            s.push(item);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = 1;
    op['-'] = 1;
    op['*'] = 2;
    op['/'] = 2;
    while(getline(cin, str), str!="0"){
        for(auto it = str.end(); it!=str.begin(); it--){
            if(*it == ' '){
                str.erase(it);
            }
        }
        while(!s.empty()){
            s.pop();
        }
        change();
        double result = cal();
        cout << result << endl;
    }
    return 0;
}
