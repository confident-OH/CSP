#include <iostream>
#include <cstring>
#include <cstdlib>
#define Directory true
#define NormalFile false
using namespace std;

typedef struct files
{
    long long houdai;
    long long haizi;
    long long daiP;
    long long ziP;
    long long mysize;
    struct files *next, *son;
    string name;
    bool flag;
    files(bool l)
    {
        houdai = 0;
        mysize = 0;
        haizi = 0;
        daiP = 0;
        ziP = 0;
        flag = l;
        next = NULL;
        son = NULL;
    }
}wenjian;

string Fbuild = string("C"), Fremove = string("R"), Fset = string("Q");
wenjian *root = new wenjian(Directory);

long long int addTheCha(wenjian *start)
{
    long long int result= 0;
    if(start->flag == NormalFile){
        result = start->mysize;
        delete start;
        return result;
    }
    wenjian *cur = start->son;
    while(cur){
        wenjian *nn = cur->next;
        result+=addTheCha(cur);
        cur = nn;
    }
    delete start;
    return result;
}

void RemoveFile(string &load, bool isBuild, long long int chae, wenjian *onefather)
{
    wenjian *head = root;
    string item = load.substr(1);
    string Fitem;
    string::size_type pos;
    if(!isBuild){
        wenjian *cur = NULL;
        pos = item.find("/");
        wenjian *daishan = NULL;
        while(pos!=item.npos){
            Fitem = item.substr(0, pos);
            item = item.substr(pos+1);
            cur = head->son;
            if(cur == NULL || cur->flag == NormalFile){
                return;
            }
            while(cur->name!=Fitem && cur->next != NULL){
                cur = cur->next;
            }
            if(cur->name == Fitem){
                head = cur;
            }
            else{
                return;
            }
            pos = item.find("/");
            if(pos == item.npos){

            }
        }
        if(head->son == NULL){
            return;
        }
        onefather = head;
        if(onefather->son->name == item){
            daishan = onefather->son;
            onefather->son = daishan->next;
            daishan->next = NULL;
            chae = addTheCha(daishan);
        }
        else{
            cur = onefather->son;
            while(cur->next!=NULL && cur->next->name!=item){
                cur = cur->next;
            }
            if(cur->next==NULL){
                return;
            }
            daishan = cur->next;
            cur->next = daishan->next;
            daishan->next = NULL;
            // 删除cur->next指向的文件
            chae = addTheCha(daishan);
            //删除完成.
        }
    }
    head = root;
    head->houdai -= chae;
    item = load.substr(1);
    onefather->haizi -= chae;
    pos = item.find("/");
    while(pos!=item.npos){
        Fitem = item.substr(0, pos);
        item = item.substr(pos+1);
        wenjian *cur = head->son;
        while(cur->name != Fitem){
            cur = cur->next;
        }
        cur->houdai -= chae;
        head = cur;
        pos = item.find("/");
    }
}

bool BuildFile(string &load, long long int Fsize)
{
    wenjian *head = root;
    string item = load.substr(1);
    string Fitem;
    string::size_type pos;
    long long int chae;
    pos = item.find("/");
    while(pos!=item.npos){
        Fitem = item.substr(0, pos);
        if(head->son == NULL){
            head->son = new wenjian(Directory);
            head = head->son;
            head->name = Fitem;
        }
        else{
            wenjian *cur = head->son;
            while(cur->name != Fitem && cur->next!=NULL){
                cur = cur->next;
            }
            if(cur->name == Fitem){
                if(cur->flag == NormalFile) return false;
                head = cur;
            }
            else{
                cur->next = new wenjian(Directory);
                head =cur->next;
                head->name = Fitem;
            }
        }
        item = item.substr(pos+1);
        pos = item.find("/");
    }
    if(head->son == NULL){
        head->son = new wenjian(NormalFile);
        head = head->son;
        head->name = item;
        chae = Fsize;
        head->mysize = Fsize;
    }
    else{
        wenjian *cur = head->son;
        while(cur->name != item && cur->next!=NULL){
            cur = cur->next;
        }
        if(cur->name == item){
            if(cur->flag == Directory) return false;
            chae = Fsize - cur->mysize;
            head = cur;
            cur->mysize = Fsize;
        }
        else{
            cur->next = new wenjian(NormalFile);
            head = cur->next;
            head->name = item;
            chae = Fsize;
            head->mysize = Fsize;
        }
    }// 至此创建成功
    bool isSuccess = true;
    head = root;
    item = load.substr(1);
    pos = item.find("/");
    root->houdai += chae;
    wenjian *ddd = NULL;
    if(root->daiP){
        if(root->daiP<root->houdai){
            isSuccess = false;
        }
    }
    if(pos == item.npos){
        root->haizi+=chae;
        if(root->ziP){
            if(root->ziP<root->haizi){
                isSuccess = false;
            }
        }
    }
    // 开始检查父目录们的配额
    while(pos!=item.npos){
        Fitem = item.substr(0, pos);
        item = item.substr(pos+1);
        wenjian *cur = head->son;
        while(cur->name != Fitem){
            cur = cur->next;
        }
        cur->houdai += chae;
        if(cur->daiP){
            if(cur->daiP<cur->houdai){
                isSuccess = false;
            }
        }
        head = cur;
        pos = item.find("/");
        if(pos==item.npos){
            ddd = cur;
            cur->haizi+=chae;
            if(cur->ziP){
                if(cur->ziP<cur->haizi){
                    isSuccess =  false;
                }
            }
        }
    }
    if(!isSuccess){
        RemoveFile(load, true, chae, ddd);
        return false;
    }
    return true;
}

bool SetFile(string &load, long long LD, long long LR)
{
    if(load.size() == 1){
        if(LD !=0){
            if(root->haizi>LD) return false;
        }
        if(LR != 0){
            if(root->houdai>LR) return false;
        }
        root->ziP = LD;
        root->daiP = LR;
        return true;
    }
    string item = load.substr(1);
    string Fitem;
    wenjian *head = root;
    string::size_type pos;
    pos = item.find("/");
    while(pos != item.npos){
        Fitem = item.substr(0, pos);
        item = item.substr(pos+1);
        wenjian *cur = head->son;
        while(cur != NULL && cur->name != Fitem){
            cur = cur->next;
        }
        if(cur == NULL){
            return false;
        }
        head = cur;
        pos = item.find("/");
    }
    head = head->son;
    while(head && head->name != item){
        head = head->next;
    }
    if(head == NULL){
        return false;
    }
    if(head->flag == NormalFile){
        return false;
    }
    if(LD!=0 && head->haizi > LD){
        return false;
    }
    if(LR!=0 && head->houdai > LR){
        return false;
    }
    head->ziP = LD;
    head->daiP = LR;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string exe, load;
    long long Fsize, LD, LR;
    bool label;
    for(int i = 0; i<n; i++){
        cin >> exe;
        if(exe == Fbuild){
            cin >> load >> Fsize;
            label = BuildFile(load, Fsize);
        }
        if(exe == Fremove){
            cin >> load;
            RemoveFile(load, false, 0, NULL);
            label = true;
        }
        if(exe == Fset){
            cin >> load >> LD >> LR;
            label = SetFile(load, LD, LR);
        }
        if(label){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
    return 0;
}


//R /6oYL/8aUL/zik/7cA
