#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    return a.first < b.first;
}

int main(void)
{
    pair<int, double> x_n;
    vector<pair<int, double>> poly_in1, poly_in2, poly_out;
    int n, x;
    double a;
    cin >> n;
    for (int i = 0; i<n ;i++){
        cin >> x >> a;
        x_n.first = x;
        x_n.second = a;
        poly_in1.push_back(x_n);
    }
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> x >> a;
        x_n.first = x;
        x_n.second = a;
        poly_in2.push_back(x_n);
    }
    for(auto i=poly_in1.begin(); i!=poly_in1.end(); i++){
        for(auto j=poly_in2.begin(); j!=poly_in2.end(); j++){
            x_n.first = i->first + j->first;
            x_n.second = i->second * j->second;
            poly_out.push_back(x_n);
        }
    }
    sort(poly_out.begin(), poly_out.end(), cmp);
    auto p = poly_out.begin();
    vector<pair<int,double>> poly_r;
    x = p->first;
    a = p->second;
    p++;
    int nums = 0;
    while(p!=poly_out.end()){
        if(p->first == x){
            a+=p->second;
        }
        else{
            x_n.first = x;
            x_n.second = a;
            poly_r.push_back(x_n);
            nums++;
            x = p->first;
            a = p->second;
       }
       p++;
    }
    x_n.first = x;
    x_n.second = a;
    poly_r.push_back(x_n);
    nums++;
    p = poly_r.end()-1;
    cout << nums;
    while(p!=poly_r.begin()){
        printf(" %d %0.1f", p->first, p->second);
        p--;
    }
    printf(" %d %0.1f", p->first, p->second);
    return 0;
}
