#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int SMax = 10010, NMax = 520, EMax = 100010;
int edge[EMax], head[NMax], vnext[EMax], eCount;
int num_in[NMax];
char name[NMax];
bool out[SMax][NMax], in_v[NMax][5];
string allGate[6] = {string("NOT"), string("AND"), string("OR"), string("XOR"), string("NAND"), string("NOR")};
int M, N;

void add_edge(int source, int dest)
{
    vnext[eCount] = head[source];
    head[source] = eCount;
    edge[eCount] = dest;
    eCount++;
}

bool BFS(int i)
{

    return true;
}

void init()
{
    eCount = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, 0, sizeof(head));
    memset(vnext, 0, sizeof(vnext));
    memset(num_in, 0, sizeof(num_in));
    memset(in_v, 0, sizeof(in_v));
    memset(out, 0, sizeof(out));
}

int main()
{
    int Q = 0, S = 0;
    cin >> Q;
    while(Q > 0){
        init();
        cin >> M >> N;
        string gateName;
        string inGate;
        int gateNum;
        for(int i = 0; i<N; i++){
            cin >> gateName >> gateNum;
            for(int i = 1; i<=6; i++){
                if(gateName == allGate[i]){
                    name[M+i] = i;
                    break;
                }
            }
            num_in[M+i] = gateNum;
            for(int j = 0; j<gateNum; j++){
                cin >> inGate;
                if(inGate[0] == 'I'){
                    add_edge(atoi(inGate.substr(1).c_str()) - 1, M+i);
                }
                else{
                    add_edge(atoi(inGate.substr(1).c_str()) + M - 1, M+i);
                }
            }
        }
        //完成导入电路图
        //判断是否出现环路
        if(!BFS(M)){
            printf("LOOP\n");
            continue;
        }
        //导入每次测试数据
        cin >> S;
        for(int i = 0; i<S; i++){
            for(int j = 0; j<M; j++){
                cin >> out[i][j];
            }
        }
        for(int i = 0; i<S; i++){
            memset(in_v, 0, sizeof(in_v));
        }

        Q--;
    }
    return 0;
}
