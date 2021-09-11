#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define LL long long int

using namespace std;
const int M = 14, N = 12, st = 1<<12;
int n, m;
int corn_map[M];
LL corn_status[M][M*N][st];
vector<int> status;

bool check(int s)
{
    if((s<<1)&s){
        return false;
    }
    return true;
}

int BitCount(int state)
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += state >> i & 1;
    return res;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        int item;
        for(int j = 0; j<n; j++){
            cin >> item;
            corn_map[i] = corn_map[i] << 1;
            corn_map[i] += item;
        }
    }
    corn_map[m] = -1;
    for(int i = 0; i<(1<<n); i++){
        if(check(i)){
            status.push_back(i);
            //cout << i << endl;
        }
    }
    /*for(int i = 0; i<status.size(); i++){
        cout << "status" << i << ": " << status[i] << endl;
    }*/
    for(int i = 0; i<status.size(); i++){
        if((corn_map[0]&status[i])!=status[i]) continue;
        int j = BitCount(status[i]);
        corn_status[0][j][status[i]]++;
    }
    int bc;
    for(int i = 1; i<m+1; i++){
        for(int j = 0; j<=n*m; j++){
            for(int k = 0; k<status.size(); k++){
                for(int l = 0; l<status.size(); l++){
                    if((status[l]&corn_map[i]) != status[l]) continue;
                    if(status[l]&status[k]) continue;
                    bc = BitCount(status[l]);
                    corn_status[i][j+bc][status[l]] += corn_status[i-1][j][status[k]];
                    corn_status[i][j+bc][status[l]] %= 100000000;
                }
            }
        }
    }
    LL result = 0;
    for(int i = 0; i<=m*n; i++){
        result += corn_status[m][i][0];
        result %= 100000000;
        //cout << corn_status[m][i][0] << endl;
    }
    cout << result;
    return 0;
}
