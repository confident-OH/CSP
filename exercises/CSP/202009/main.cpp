#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, s;
const int SMax = 10010, NMax = 3010, EMax = 5*NMax;
int e[EMax], ne[EMax], head[NMax], ind;
int d[NMax], q[NMax];
char gatename[NMax];
int gatestate[NMax];
vector<int> in[SMax], out[SMax];

void add_edge(int source, int dest)
{
    e[ind] = dest;
    ne[ind] = head[source];
    head[source] = ind++;
}

bool topsort()
{
    int hh = 0, tt = -1, edg;
    for(int i = 1; i<=m+n; i++){
        if(!d[i]) q[++tt] = i;
    }
    while(hh<=tt){
        int t = q[hh++];
        for(int i = head[t]; i!=-1; i = ne[i]){
            edg = e[i];
            d[edg]--;
            if(!d[edg]) q[++tt] = edg;
        }
    }
    return tt == n + m-1;
}

char gate_name(char *str){
    string gates[] = {
        "NOT", "AND", "OR", "XOR", "NAND", "NOR"
    };
    for(int i = 0; i<6; i++){
        if(string(str) == gates[i]){
            return i+1;
        }
    }
    return -1;
}

void calculate()
{
    for(int i = 0; i<m+n; i++){
        int t = q[i];
        for(int j = head[t]; j!=-1; j = ne[j]){
            int edg = e[j];
            switch (gatename[edg])
            {
            case 1:
                gatestate[edg] = !gatestate[t];
                break;
            case 2:
                gatestate[edg] &= gatestate[t];
                break;
            case 3:
                gatestate[edg] |= gatestate[t];
                break;
            case 4:
                gatestate[edg] ^= gatestate[t];
                break;
            case 5:
                gatestate[edg] |= !gatestate[t];
                break;
            case 6:
                gatestate[edg] &= !gatestate[t];
                break;
            default:
                break;
            }
        }
    }
}

void init(){
    memset(head, -1, sizeof (head));
    memset(ne, -1, sizeof (ne));
    ind = 0;
    memset(e, 0, sizeof (e));
    memset(d, 0, sizeof(d));
}

int main()
{
    int Q;
    scanf("%d", &Q);
    char str[100];
    int num;
    while(Q--){
        init();
        scanf("%d %d", &m, &n);
        for(int i = 1; i<=n; i++){
            scanf("%s %d", str, &d[m+i]);
            gatename[m+i] = gate_name(str);
            for(int j = 0; j<d[m+i]; j++){
                scanf("%s", str);
                num = atoi(str+1);
                if(str[0] == 'I'){
                    add_edge(num, m+i);
                }else{
                    add_edge(num+m, m+i);
                }
            }
        }
        scanf("%d", &s);
        for(int i = 0; i<s; i++){
            in[i].clear();
            for(int j = 0; j<m; j++){
                scanf("%d", &num);
                in[i].push_back(num);
            }
        }
        for(int i = 0; i<s; i++){
            out[i].clear();
            int cnt;
            scanf("%d", &cnt);
            for(int j = 0; j<cnt; j++){
                scanf("%d", &num);
                out[i].push_back(num);
            }
        }
        //进行拓扑排序
        if(!topsort()){
            printf("LOOP\n");
        }else{
            for(int i = 0; i<s; i++){
                for(int j = 1; j<=m; j++){
                    gatestate[j] = in[i][j - 1];
                }
                for(int j = m+1;j<=n+m; j++){
                    if(gatename[j] == 2 || gatename[j] == 6) gatestate[j] = 1;
                    else gatestate[j] = 0;
                }
                //完成初始化
                calculate();
                for(auto x:out[i]){
                    printf("%d ", gatestate[m+x]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

/*
总结：邻接表模板+拓扑序模板
有向图是否成环可以使用拓扑序判定
*/
