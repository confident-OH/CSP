// 13年第四题才是模拟题，所以这是第四题
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int height[1001][1001];

int main()
{
    char num[20];
    char label;
    fgets(num, 20, stdin);
    int item = 0;
    item += num[0] - '0';
    item += (num[2] - '0') * 2;
    item += (num[3] - '0') * 3;
    item += (num[4] - '0') * 4;
    item += (num[6] - '0') * 5;
    item += (num[7] - '0') * 6;
    item += (num[8] - '0') * 7;
    item += (num[9] - '0') * 8;
    item += (num[10] - '0') * 9;
    item = item % 11;
    if(item == 10) label = 'X';
    else label = item + '0';
    if (num[12] == label){
        cout << "Right";
    }
    else{
        num[12] = label;
        cout << num;
    }
    return 0;
}
