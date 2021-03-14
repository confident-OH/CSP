#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define x first
#define y second
using namespace std;
typedef unordered_map<string, int> MPSI;

MPSI dfs(string &str, int &u){
    MPSI result;
    while(u<str.size()){
        if(str[u] == '('){
            u++;
            MPSI res2 = dfs(str, u);
            u++;
            int cnt = 1;
            int j = u;
            while(j<str.size() && isdigit(str[j])) j++;
            if(j>u){
                cnt = stoi(str.substr(u, j - u));
                u = j;
            }
            for(auto c:res2){
                result[c.x] += c.y * cnt;
            }
        }
        else if(str[u] == ')') break;
        else{
            int k = u+1;
            while(k<str.size()&&str[k]>='a'&&str[k]<='z') k++;
            int j = k, cnt = 1;
            while(j<str.size()&& isdigit(str[j])) j++;
            if(j>k){
                cnt = stoi(str.substr(k, j-k));
            }
            result[str.substr(u, k-u)] += cnt;
            u = j;
        }
    }
    return result;
}

MPSI work(string str)
{
    MPSI result;
    int num = str.size();
    for (int i = 0; i<num; i++){
        int j = i+1;
        while(j<str.size() && str[j]!='+') j++;
        string item = str.substr(i, j - i);
        int k = 0;
        while(k<item.size()&&isdigit(item[k])){
            k++;
        }
        int cnt = 1;
        if(k){
            cnt = stoi(item.substr(0, k));
        }
        auto c = dfs(item, k);
        for(auto l:c){
            result[l.x] += l.y * cnt;
        }
        i = j;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    string str;
    for (int i = 0; i<n; i++){
        cin >> str;
        int k = str.find('=');
        auto left = work(str.substr(0, k));
        auto right = work(str.substr(k+1));
        if(right == left) puts("Y");
        else puts("N");
    }
    return 0;
}


/*
心得体会：统计字符串个数可以使用unordered_map, 该数据结果需要include <map>
unordered_map可以直接进行比较

很多计数函数比如：isdigist(), stoi()

取子串函数：string.substr()
*/
