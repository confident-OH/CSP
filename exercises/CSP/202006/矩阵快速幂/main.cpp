#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n,k;
vector<vector<int>> A, result, r;
vector<int> q;

void quick_m(int mi)
{
    if(mi == 1){
        result = A;
    }
    else{
        quick_m(mi/2);
        if(mi%2 == 1){

        }
        else{
            for(int i = n; )
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    int item;
    for(int i = 0; i<n;i++){
        A.push_back(q);
        for(int i = 0; i<n; i++){
            scanf("%d", &item);
            A.back().push_back(item);
        }
    }
    quick_m(k);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        puts("");
    }
    return 0;
}
