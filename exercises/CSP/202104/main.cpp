#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;
const int M = 100010, N = 1010;
int board[N];
bool th[M];
int n;
vector<int> q[M];
ll cnt, f[N], mod = (1e9) + 7;

int main()
{
    for(int i = 1; i<M; i++){
        for(int j = 2*i; j<M; j += i){
            q[j].push_back(i);
        }
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &board[i]);
    }
    f[0] = 1;
    for(int i = 1; i<n; i++){
        memset(th, 0, sizeof(th));
        for(int j = i-1; j>=0; j--){
            int d = board[i] - board[j];
            cnt = 0;
            for(int k:q[d]){
                if(th[k]){
                    continue;
                }
                else{
                    th[k] = true;
                    cnt++;
                }
            }
            th[d] = true;
            f[i] = (f[i] + (ll) cnt * f[j]) % mod;
        }
    }
    cout << f[n - 1];
    return 0;
}
