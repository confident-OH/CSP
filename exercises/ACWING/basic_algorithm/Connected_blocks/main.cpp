#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 100010;
int bnums[N];
int t[N];

void init()
{
    for(int i = 0; i<N; i++){
        t[i] = i;
        bnums[i] = 1;
    }
}

int findfa(int a)
{
    if(t[a] == a){
        return a;
    }
    else{
        int fa = findfa(t[a]);
        t[a] = fa;
        return fa;
    }
}

void update(int a, int b)
{
    int fa = findfa(a);
    int fb = findfa(b);
    if(fa == fb) return;
    t[fa] = fb;
    bnums[fb] += bnums[fa];
}

int main()
{
    init();
    int n, m;
    cin >> n >> m;
    string op;
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> op;
        if(op == "C"){
            cin >> a >> b;
            if(a != b) update(a, b);
        }
        else{
            if(op == "Q1"){
                cin >> a >> b;
                if(findfa(a) == findfa(b)){
                    cout << "Yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
            else{
                cin >> a;
                int item = findfa(a);
                cout << bnums[item] << endl;
            }
        }
    }
    return 0;
}
