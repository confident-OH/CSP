#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

char gateLabel[1010];
bool gateState[1010];
int M, N, S;
int h[1010], e[1010], ne[1010], idx;
int q[1010], d[1010];

void addEdge(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void initGate(string &fun, int ID)
{
    if(fun == "NOT"){
        gateLabel[ID] = 1;
        gateState[ID] = 0;
        return;
    }
    if(fun == "AND"){
        gateLabel[ID] = 2;
        gateState[ID] = 1;
        return ;
    }
    if(fun == "OR"){
        gateLabel[ID] = 3;
        gateState[ID] = 0;
        return ;
    }
    if(fun == "XOR"){
        gateLabel[ID] = 4;
        gateState[ID] = 0;
        return ;
    }
    if(fun == "NAND"){
        gateLabel[ID] = 5;
        gateState[ID] = 0;
        return ;
    }
    if(fun == "NOR"){
        gateLabel[ID] = 6;
        gateState[ID] = 1;
        return ;
    }
}

bool topsort(int n)
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    return tt == n - 1;
}

void allInit()
{
    idx = 0;
    memset(h, -1, sizeof(h));
    memset(gateLabel, 0, sizeof(gateLabel));
    memset(gateState, 0, sizeof(gateState));
    memset(q, 0, sizeof(q));
    memset(d, 0, sizeof(d));
}

int main()
{
    std::ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q>0){
        Q--;
        allInit();
        string fun, gateItem;
        int k, idInput;
        cin >> M >> N;
        for(int i = 1; i<=N; i++){
            cin >> fun;
            cin >> k;
            initGate(fun, i+M);
            for(int j = 0; j<k; j++){
                cin >> gateItem;
                if(gateItem[0] == 'I'){
                    idInput = atoi(gateItem.substr(1).c_str());
                }
                else{
                    idInput = M + atoi(gateItem.substr(1).c_str());
                }
                addEdge(idInput, M+i);
                d[M+i]++;
            }
        }
        if(!topsort(N+M)){
            cout << "LOOP" << endl;
            continue;
        }
        cin >> S;
        vector<int> question[10001];
        vector<int> gateinput[10001];
        int turnItem;
        for(int i = 0; i<S; i++){
            for(int j = 0; j<M; j++){
                cin >> turnItem;
                gateinput[i].push_back(turnItem);
            }
        }
        for(int i = 0; i<S; i++){
            int num;
            cin >> num;
            for(int j = 0; j<num; j++){
                cin >> turnItem;
                question[i].push_back(turnItem);
            }
        }
        for(int i = 0; i<S; i++){
            bool nowGateStatus[1010];
            memcpy(nowGateStatus, gateState, sizeof(gateState));
            for(int j = 1; j<=M; j++){
                nowGateStatus[j] = gateinput[i][j-1];
            }
            for(int j = 0; j<M+N; j++){
                int node = q[j];
                for(int k = h[node]; ~k; k = ne[k]){
                    int edge = e[k];
                    switch(gateLabel[edge]){
                        case 1:{
                        nowGateStatus[edge] = !nowGateStatus[node];
                        break;
                        }
                        case 2:{
                        nowGateStatus[edge] &= nowGateStatus[node];
                        break;
                        }
                        case 3:{
                        nowGateStatus[edge] |= nowGateStatus[node];
                        break;
                        }
                        case 4:{
                        nowGateStatus[edge] ^= nowGateStatus[node];
                        break;
                        }
                        case 5:{
                        nowGateStatus[edge] = !(!nowGateStatus[edge] & nowGateStatus[node]);
                        break;
                        }
                        case 6:{
                        nowGateStatus[edge] = !(!nowGateStatus[edge] | nowGateStatus[node]);
                        break;
                        }
                    }
                }
            }
            for(int resId:question[i]){
                cout << nowGateStatus[M+resId] << " ";
            }
            cout << endl;
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
