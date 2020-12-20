#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> poly(1010, 0);
    vector<pair<int, double>> results;
    int a, n;
    double ai;
    cin >> a;
    for(int i = 0; i<a; i++){
        scanf("%d %lf", &n, &ai);
        poly[n]+=ai;
    }
    cin >> a;
    for(int i = 0; i<a; i++){
        scanf("%d %lf", &n, &ai);
        poly[n]+=ai;
    }
    pair<int, double> item;
    for(int i = 0; i<=1000; i++){
        if(poly[i]!=0.0){
            item.first = i;
            item.second = poly[i];
            results.push_back(item);
        }
    }
    printf("%d", results.size());
    while(!results.empty()){
        item = results.back();
        results.pop_back();
        printf("% d %0.1f", item.first, item.second);
    }
    return 0;
}
