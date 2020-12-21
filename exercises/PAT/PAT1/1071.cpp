#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check(char a)
{
    if(a>='0'&&a<='9') return true;
    if(a>='a'&&a<='z') return true;
    if(a>='A'&&a<='Z') return true;
    return false;
}

int main()
{
    string ch;
    unordered_map<string, int> h;
    getline(cin, ch);
    int s = ch.size();
    int j;
    for(int i = 0; i<s; i++){
        string word;
        if(check(ch[i])){
            j = i;
            while(j<s&&check(ch[j]))
                word+=tolower(ch[j++]);
            h[word]++;
            i = j;
        }
    }
    string word;
    int cnt = -1;
    for(auto i : h){
        if(i.second>cnt || (i.second == cnt && i.first<word)){
            word = i.first;
            cnt = i.second;
        }
    }
    cout << word << " " << cnt;
    return 0;
}
