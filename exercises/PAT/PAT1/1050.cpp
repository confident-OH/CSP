#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ascii[300];
    memset(ascii, 0, sizeof(ascii));
    char b_sub[20000], sub[20000];
    fgets(b_sub, 20000, stdin);
    fgets(sub, 20000, stdin);
    for(int i = 0; sub[i]!='\n'; i++){
        ascii[sub[i]] = 1;
    }
    int i, j;
    for(i=0, j=0; b_sub[i]!='\n'; i++){
        if(!ascii[b_sub[i]]){
            b_sub[j] = b_sub[i];
            j++;
        }
    }
    b_sub[j] = '\0';
    printf("%s", b_sub);
    return 0;
}

// 注意空格也要减去
// 建立扫描数组的运算复杂度为O（n）
