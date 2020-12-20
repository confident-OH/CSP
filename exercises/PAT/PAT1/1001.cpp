#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    stack<int> s;
    cin >> a >> b;
    int result = a+b;
    if(result<0){
        cout << "-";
        result = -result;
    }
    if(result == 0){
        printf("0\n");
        return 0;
    }
    while(result!=0){
        s.push(result%1000);
        result = result/1000;
    }
    int si = s.size();
    printf("%d", s.top());
    s.pop();
    if(si == 1){
        cout << endl;
        return 0;
    }
    cout << ',';
    for(int i = 1; i<si-1; i++){
        printf("%03d,", s.top());
        s.pop();
    }
    printf("%03d\n", s.top());
    return 0;
}

//学会了使用printf的输出格式