#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int status = 0;
    long long second = 0;
    int level, i, N;
    cin >> N;
    for(i = 0; i<N; i++){
        cin >> level;
        if(level>status){
            second += 6*(level - status);
        }
        if(level<status){
            second+=4*(status - level);
        }
        status = level;
        second+=5;
    }
    cout << second;
    return 0;
}
