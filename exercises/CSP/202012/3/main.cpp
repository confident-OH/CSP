#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;

struct node
{
    bool fileEl; // 1为目录
    ll LD; //目录配液
    ll LR; //后代配额
    ll LDNow; //目录大小
    ll LRNow; //后代大小
    string name;
};
const int M = 1000010, N = 10000010;
int ne[N], e[N], head[M], ind = 0;
int Hne[N], He[N], Hhead[M], Hind = 0;
string fileName[M];
bool fileE1[M];
ll LD[M], LR[M], LDNow[M], LRNow[M];
int fileInd = 0;

void add_edge(int s, int d)
{
    ne[ind] = head[s];
    head[s] = ind;
    e[ind++] = d;
}

int next_file(string name)
{
    int len = name.size();
    for(int i = 0; i<len; i++){
        if(name[i] == '/') return i;
    }
    return len;
}

int find_N(string name, int ind)
{
    for(int i = head[ind]; i!=-1; i = ne[i]){
        if(name == fileName[e[i]]){
            if(fileE1[e[i]]){
                return e[i];
            }
            else{
                return -2;
            }
        }
    }
    return -1;
}

void init()
{
    fileInd = 1;
}

int main()
{
    int num;
    char instruct;
    string filePath0,filePath;
    ll fileSize, fileLD, fileLR;
    init();
    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> instruct;
        switch(instruct)
        {
        case 'C':
            {
                cin >> filePath0 >> fileLR;
                bool success = true;
                filePath = string(filePath0.substr(1));
                int nend = next_file(filePath);
                int blockInd1 = 0, blockInd2;
                while(nend != filePath.size()){
                    string name = string(filePath.substr(0, nend));
                    blockInd2 = find_N(name, blockInd1);
                    if(blockInd2 == -2){
                        // 直接错误
                        cout << 'N' << endl;
                        success = false;
                        break;
                    }
                    if(blockInd2 == -1){
                        add_edge(blockInd1, fileInd);
                        blockInd1 = fileInd++;
                    }
                    else{
                        blockInd1 = blockInd2;
                    }
                    filePath = string(filePath.substr(nend + 1));
                    nend = next_file(filePath);
                }
                if(!success){
                    break;
                }
                blockInd2 = find_N(filePath, blockInd1);
                if(blockInd2 == -1){
                    add_edge(blockInd1, fileInd);
                    fileName[fileInd] = filePath;

                    fileInd++;
                }
                else{
                    cout << 'N' << endl;
                }
                break;
            }
        case 'R':
            {
                cin >> filePath;
                break;
            }
        case 'Q':
            {
                cin >> filePath >> fileLD >> fileLR;
                break;
            }
        }
    }
    return 0;
}
