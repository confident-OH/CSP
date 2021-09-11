#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct rules
{
    string name;
    int id;
    rules(string _name, int _id)
    {
        name = _name;
        id = _id;
    }
}rules;

vector<rules> domain;
vector<rules> roles[100];
vector<string> roleNames;
vector<rules> users[100];
vector<string> userNames;

int num_domain, num_roles, num_users, num_query;

int main()
{
    char exeline[1000];
    int role_exe_num;
    int user_exe_num;
    string item;
    int num_item;
    string::size_type position = 0;
    scanf("%d", &num_domain);
    getchar();
    for(int i = 0; i<num_domain; i++){
        fgets(exeline, 1000, stdin);
        item = string(exeline);
        position = item.find(":");
        if(position == item.npos){
            domain.push_back(rules(item, -1));
        }
        else{
            num_item = atoi(item.substr(position+1).c_str());
            item = item.substr(0, position);
            domain.push_back(rules(item, num_item));
        }
    }
    scanf("%d", &num_roles);
    getchar();
    for(int i = 0; i<num_roles; i++){
        scanf("%s %d", exeline, &role_exe_num);
        roleNames.push_back(string(exeline));
        for(int j = 0; j<role_exe_num; j++){
            bool is_in = false;
            scanf("%s", exeline);
            item = string(exeline);
            position = item.find(":");
            if(position == item.npos){
                num_item = -1;
            }
            else{
                num_item = atoi(item.substr(position+1).c_str());
                item = item.substr(0, position);
            }
            for(int k = 0; k<roles[i].size(); k++){
                if(roles[i][k].name == item){
                    is_in = true;
                    roles[i][k].id = max(roles[i][k].id, num_item);
                    break;
                }
            }
            if(!is_in){
                roles[i].push_back(rules(item, num_item));
            }
        }
    }
    scanf("%d", &num_users);
    for(int i = 0; i<num_users; i++){
        scanf("%s %d", exeline, &user_exe_num);
        userNames.push_back(string(exeline));
        for(int j = 0; j<user_exe_num; j++){
            scanf("%s", exeline);
            item = string(exeline);
            int role2id = 0;
            while(role2id<num_roles){
                if(roleNames[role2id] == item) break;
                else role2id++;
            }
            for(rules k:roles[role2id]){
                // 将权限转移过来
                bool is_in = false;
                for(int l = 0; l < users[i].size(); l++){
                    if(users[i][l].name == k.name){
                        is_in = true;
                        users[i][l].id = max(users[i][l].id, k.id);
                        break;
                    }
                }
                if(!is_in){
                    users[i].push_back(k);
                }
            }
        }
    }
    scanf("%d", &num_query);
    string q_name, q_rule;
    int q_lev, q_label;
    for(int i = 0; i<num_query; i++){
        scanf("%s", exeline);
        q_name = string(exeline);
        scanf("%s", exeline);
        q_rule = string(exeline);
        position = q_rule.find(":");
        if(position == q_rule.npos){
            q_label = 1; // 无等级查询
            int userId;
            for(userId = 0; userId<num_users; userId++){
                if(userNames[userId] == q_name) break;
            }
            if(userId == num_users){
                cout << "false" << endl;
                continue;
            }
            int j;
            for(j = 0; j<users[userId].size(); j++){
                if(users[userId][j].name == q_rule){
                    if(users[userId][j].id == -1){
                        cout << "true" << endl;
                    }
                    else{
                        cout << users[userId][j].id << endl;
                    }
                    break;
                }
            }
            if(j == users[userId].size()) cout << "false" << endl;
        }
        else{
            // 有等级查询
            q_label = 2;
            q_lev = atoi(q_rule.substr(position+1).c_str());
            q_rule = q_rule.substr(0, position);
            int userId;
            for(userId = 0; userId<num_users; userId++){
                if(userNames[userId] == q_name) break;
            }
            if(userId == num_users){
                cout << "false" << endl;
                continue;
            }
            int j;
            for(j = 0; j<users[userId].size(); j++){
                if(users[userId][j].name == q_rule && users[userId][j].id >= q_lev){
                    cout << "true" << endl;
                    break;
                }
            }
            if(j == users[userId].size()) cout << "false" << endl;
        }
    }
    return 0;
}
