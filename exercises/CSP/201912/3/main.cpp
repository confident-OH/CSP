#include <iostream>

using namespace std;

typedef struct chnode
{
    string name;
    int num;
    struct chnode *next;
    node(){num = 0; next = NULL;}
}node;

void funcDel(node *start)
{
    node *current = start->next;
    while(current){
        free(start);
        start = current;
        current = current->next;
    }
    free(start);
}

bool chcmp(node *a, node *b)
{
    if(a == NULL && b == NULL){
        return true;
    }
    if(a == NULL || b == NULL){
        return false;
    }
    node *cur = NULL;
    while(b){
        cur = a;
        while(cur && cur->name!=b->name){
            cur = cur->next;
        }
        if(!cur){
            return false;
        }
        if(cur->num == b->num) cur->num = 0;
        else{
            return false;
        }
        b = b->next;
    }
    cur = a;
    while(cur){
        if(cur->num != 0){
            return false;
        }
        cur = cur->next;
    }
    return true;
}

int numFind(string &str)
{
    int num = 0;
    //cout << "Debug num : " << str << endl;
    while(str[0]>='0' && str[0]<='9'){
        num *= 10;
        num += (str[0] - '0');
        str = str.substr(1);
    }
    //cout << "Debug num find: " << num << endl;
    return num;
}

string eleFind(string &str)
{
    string::size_type pos = 1;
    while(pos < str.size() && str[pos]>='a' && str[pos]<='z'){
        pos++;
    }
    string result = str.substr(0, pos);
    if(pos == str.size()) str.clear();
    else str = str.substr(pos);
    //cout << "Debug we find: " << result << endl;
    return result;
}

void chmerge(node **head, node *item)
{
    node *cur;
    while(item){
        if(!(*head)){
            (*head) = new node();
            (*head)->name = item->name;
            (*head)->num = item->num;
        }
        else{
            cur = *head;
            while(cur){
                if(cur->name == item->name){
                    cur->num = cur->num + item->num;
                    break;
                }
                if(cur->next) cur = cur->next;
                else{
                    cur->next = new node();
                    cur->next->name = item->name;
                    cur->next->num = item->num;
                    break;
                }
            }
        }
        item = item->next;
    }
}

node* dfs(int para, string &exe)
{
    if(para == 0) para = 1;
    node *start = NULL;
    while(!exe.empty()){
        //cout << "Debug exe: " << exe << endl;
        if(exe[0] == ')'){
            exe = exe.substr(1);
            int bpara = numFind(exe);
            node *cur = start;
            while(cur && bpara!=0){
                cur->num = cur->num * bpara;
                cur = cur->next;
            }
            return start;
        }
        if(exe[0] == '('){
            exe = exe.substr(1);
            node *item = dfs(para, exe);
            chmerge(&start, item);
            funcDel(item);
            continue;
        }
        string itemName = eleFind(exe);
        int itemNum = numFind(exe);
        if(itemNum == 0) itemNum = 1;
        node *cur = start;
        if(start == NULL){
            start = new node();
            start->name = itemName;
            start->num = itemNum * para;
            continue;
        }
        while(cur){
            if(cur->name == itemName){
                cur->num = cur->num + itemNum * para;
                break;
            }
            if(cur->next) cur = cur->next;
            else{
                cur->next = new node();
                cur->next->name = itemName;
                cur->next->num = itemNum * para;
                break;
            }
        }
    }
    return start;
}

node* funcCal(string &exe)
{
    node *head = NULL;
    string::size_type pos;
    pos = exe.find("+");
    while(pos != exe.npos){
        string item = exe.substr(0, pos);
        //cout << "Debug item: " << item << endl;
        exe = exe.substr(pos+1);
        int t = numFind(item);
        if(t == 0) t = 1;
        node *cur = dfs(t, item);
        chmerge(&head, cur);
        funcDel(cur);
        pos = exe.find("+");
    }
    int t = numFind(exe);
    node *cur = dfs(t, exe);
    chmerge(&head, cur);
    return head;
}



int main()
{
    ios::sync_with_stdio(false);
    //string test = "My";
    //string eleTest = eleFind(test);
    //cout << "eleFind test: " << eleTest << endl;
    //string test = "2";
    //int numTest = numFind(test);
    int n;
    cin >> n;
    string chemf, chleft, chright;
    node *left_num, *right_num;
    string::size_type pos;
    for(int i = 0; i<n; i++){
        cin >> chemf;
        pos = chemf.find("=");
        chleft = chemf.substr(0, pos);
        chright = chemf.substr(pos+1);
        left_num = funcCal(chleft);
        right_num = funcCal(chright);
        if(chcmp(left_num, right_num)){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
        funcDel(left_num);
        funcDel(right_num);
    }
    return 0;
}



/*
node* dfs(倍数, 字符串引用 str)
if(str[0] == ')'){
    find_num();
    倍增;
    return;
}
while(!str.empty()){
    if(str[0] == ' '){
        str = str.substr(1);
        continue;
    }
    if(str[0] == '('){
        str = str.substr(1);
        dfs(倍数, str);
        merge();

11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl

*/
