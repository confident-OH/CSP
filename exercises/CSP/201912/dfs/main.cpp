#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
    string word;
    struct node *next;
    node(){
        next = NULL;
    }
}node;

int n;

void printNode(node *head)
{
    while(head)
    {
        cout << "Debug item: " << head->word << endl;
        head = head->next;
    }
}

void delNode(node *head)
{
    node *cur = head->next;
    while(head){
        cur = head->next;
        delete head;
        head = cur;
    }
}

node* genNode(node *head, string &str)
{
    node *cur = NULL;
    node *start = NULL;
    cout << "Debug genNode: " << str << endl;
    while(head){
        if(head->word == str){
            head = head->next;
            continue;
        }
        if(!cur){
            cur = new node();
            start = cur;
            cur->word = head->word;
        }
        else{
            cur->next = new node();
            cur = cur->next;
            cur->word = head->word;
        }
        head = head->next;
    }
    return start;
}

int dfs(node *head, int wordSize, char ch)
{
    int result = wordSize;
    if(!head){
        return wordSize;
    }
    node *cur=head;
    vector<string> line;
    while(cur){
        cout << "Debug cur->word: " << cur->word << " Head is : " << ch << endl;
        if((cur->word)[0] == ch){
            line.push_back(cur->word);
            cout << "Debug " << cur->word << " we find!" << endl;
        }
        cur=cur->next;
    }
    while(!line.empty()){
        string ss = line.back();
        cout << "Debug ss: " << ss << endl;
        int item = ss.size() + wordSize - 1;
        char chNext = ss[ss.size()-1];
        cur = genNode(head, ss);
        cout << "Debug finished" << endl;
        result = max(result, dfs(cur, item, chNext));
        delNode(cur);
        line.pop_back();
    }
    return result;
}

int main()
{
    struct node *head = NULL;
    node *cur = head;
    cin >> n;
    getchar();
    for(int i = 0; i<n; i++){
        if(head == NULL){
            head = new node();
            cur = head;
            cin >> cur->word;
            getchar();
            //cout << "Debug: item = " << cur->word << endl;
        }
        else{
            cur->next = new node();
            cur = cur->next;
            cin >> cur->word;
            getchar();
            //cout << "Debug: item = " << cur->word << endl;
        }
    }
    //printNode(head);
    char start;
    cin >> start;
    //cout << "Debug: start = " << start << endl;
    int result = dfs(head, 1, start);
    cout << result;
    return 0;
}

/*
Debug cur->word: at
Debug cur->word: touch
Debug cur->word: cheat
Debug cur->word: choose
Debug cur->word: tact
Debug ss: at
*/
