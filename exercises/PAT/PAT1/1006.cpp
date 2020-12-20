#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct people
{
    string name;
    int time;
    int cover;
};

bool cmp(people x, people y)
{
    return x.time < y.time;
}

int main()
{
    people node;
    char nn[20];
    vector<people> arrays;
    vector<string> test;
    int area;
    int N, h1, h2, m1, m2, s1, s2;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%s %d:%d:%d %d:%d:%d", nn, &h1, &m1, &s1, &h2, &m2, &s2);
        node.name = string(nn);
        node.time = h1*10000 + m1*100 + s1;
        node.cover = 1;
        arrays.push_back(node);
        node.name = string(nn);
        node.time = h2*10000 + m2*100 + s2;
        node.cover = -1;
        arrays.push_back(node);
    }
    area = arrays.size();
    sort(arrays.begin(), arrays.end(), cmp);
    cout << arrays[0].name << " " << arrays[area - 1].name << endl;
    return 0;
}
