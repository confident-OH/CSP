#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct node
{
    long long t; // 时间
    char updateModel; //  2为传播更新, 1 普通更新, 0 查询
    int b;   // 节点名
    int c;   // 新产生的快好
    unsigned d;   // 第d个查询
    vector<int> blocks;
    node(long long _t, char _updateModel, int _b, int _c)
    {
        t = _t;
        updateModel = _updateModel;
        b = _b;
        c = _c;
    }
    node(long long _t, char _updateModel, int _b, unsigned _d)
    {
        t = _t;
        d = _d;
        updateModel = _updateModel;
        b = _b;
    }
    node(long long _t, char _updateModel, int _b, vector<int> &a)
    {
        t = _t;
        updateModel = _updateModel;
        b = _b;
        blocks = a;
    }
}node;

bool operator < (const node &a, const node &b)
{
    if(a.t != b.t){
        return a.t>b.t;
    }
    if(a.updateModel != b.updateModel){
        return a.updateModel < b.updateModel;
    }
    if(a.updateModel == 0){
        return a.d > b.d;
    }
    return true;
}

priority_queue<node> head;

void testPrint(priority_queue<node> h)
{
    while(!h.empty()){
        node item = h.top();
        cout << "Debug t: " << item.t << " update: " << (int)item.updateModel << " nodeID: " << item.b;
        if(item.updateModel == 0){
            cout << " search id: " << item.d;
        }
        cout << endl;
        h.pop();
    }
}

const int MAXN = 10010;
int h[MAXN], ne[MAXN], e[MAXN], idx;
vector<int> jiedian[1000];

void addEdge(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void bfs(int start, node iitem)
{
    for(int i = h[start]; ~i; i = ne[i]){
        int des = e[i];
        iitem.b = des;
        head.push(iitem);
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    int m, n;
    cin >> n >> m;
    getchar();
    for(int i = 1; i<=n; i++){
        jiedian[i].push_back(0);
    }
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        getchar();
        addEdge(a, b);
        addEdge(b, a);
    }
    int t, k;
    cin >> t >> k;
    getchar();
    for(int i = 0; i<k; i++){
        char line[100];
        fgets(line, 100, stdin);
        string sline(line);
        int a, b, c;
        string::size_type pos;
        pos = sline.find(" ");
        a = atoi(sline.substr(0, pos).c_str());
        sline = sline.substr(pos+1);
        pos = sline.find(" ");
        if(pos == sline.npos){
            b = atoi(sline.c_str());
            head.push(node(b, 0, a, (unsigned)i));
        }
        else{
            b = atoi(sline.substr(0, pos).c_str());
            sline = sline.substr(pos+1);
            c = atoi(sline.c_str());
            head.push(node(b, 1, a, c));
            //cout << "-----3------" << endl;
        }
    }
    //testPrint(head);
    //cout << "Debug: results: " << endl;
    while(!head.empty()){
        node item = head.top();
        switch(item.updateModel)
        {
        case 0:{
            int num = jiedian[item.b].size();
            cout << num;
            for(int i = 0; i < num; i++){
                cout << " " << jiedian[item.b][i];
            }
            cout << endl;
            break;
        }
        case 1:{
            int id = item.b;
            jiedian[id].push_back(item.c);
            node iitem(item.t + t, (char)2, 0, jiedian[id]);
            bfs(id, iitem);
            break;
        }
        case 2:{
            int id = item.b;
            bool isChanged = false;
            if(item.blocks.size()>jiedian[id].size()){
                jiedian[id] = item.blocks;
                isChanged = true;
            }
            if(item.blocks.size() == jiedian[id].size() && item.blocks.back()<jiedian[id].back()){
                jiedian[id] = item.blocks;
                isChanged = true;
            }
            if(isChanged){
                node iitem(item.t + t, (char)2, 0, jiedian[id]);
                bfs(id, iitem);
            }
            break;
        }
        default:
            break;
        }
        head.pop();
    }
    return 0;
}
