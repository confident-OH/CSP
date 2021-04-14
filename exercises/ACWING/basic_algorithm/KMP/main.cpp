#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 100010, M = 1000010;
char big[M], small[N];
int ne[N];
int n, m;
int result[1000010], result_n;

int main()
{
    scanf("%d", &n);
    getchar();
    fgets(small+1, 100010, stdin);
    scanf("%d", &m);
    getchar();
    fgets(big+1, 1000010, stdin);
    int len = strlen(small+1);
    small[len] = '\0';
    len = strlen(big+1);
    big[len] = '\0';
    // build array: ne;
    for(int i = 2, j = 0; i<=n; i++){
        while(j && small[i]!=small[j+1]) j = ne[j];
        if(small[i] == small[j+1]) j++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i<=m; i++){
        while(j && big[i]!=small[j+1]) j = ne[j];
        if(big[i]==small[j+1]) j++;
        if(j == n){
            result[result_n++] = i-n;
            j = ne[j];
        }
    }
    for(int i = 0; i<result_n; i++){
        printf("%d ", result[i]);
    }
    return 0;
}
