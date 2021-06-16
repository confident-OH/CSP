#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
const int N = 3100010;
int trie[N][2], idx;
int a[N];

void myInsert(int a)
{
    int p = 0;
    int la = 1<<30;
    int item;
    for(int i = 0; i<31; i++){
        item = (la & a)>>30;
        if(!trie[p][item]) trie[p][item] = ++idx;
        a = a<<1;
        p = trie[p][item];
    }
}

int mysearch(int a)
{
    int p = 0, la = 1<<30, item;
    int result = 0;
    for(int i = 0; i<31; i++){
        item = a & la;
        item = !item;
        if(!trie[p][item]){
            item = !item;
            p = trie[p][item];
            result = result << 1;
        }
        else{
            p = trie[p][item];
            result = (result << 1) + 1;
        }
        a = a<<1;
    }
    return result;
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
        myInsert(a[i]);
    }
    int result = 0;
    for(int i = 0; i<n; i++){
        result = max(result, mysearch(a[i]));
    }
    cout << result;
    return 0;
}
