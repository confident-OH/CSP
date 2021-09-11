#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> inputsText;
vector<int> inputLabel;
string result;

int main()
{
    char exeline[101];
    while(fgets(exeline, 101, stdin)){
        int len = strlen(exeline);
        exeline[len - 1] = '\0';
        string lineItem = string(exeline);
        string::size_type Spos = 0, Epos = 0, Epos2 = 0;
        while(Spos<lineItem.size()){
            if(lineItem[Spos] != '_'){
                Spos++;
                continue;
            }
            Epos = Spos+1;
            while(Epos<lineItem.size()){
                if(lineItem[Epos] != '_'){
                    Epos++;
                    continue;
                }
                break;
            }
            if(Epos == lineItem.size()){
                break;
            }
            string itemM = lineItem.substr(Spos+1, Epos-Spos-1);
            string itemE = lineItem.substr(Epos+1);
            lineItem = lineItem.substr(0, Spos);
            lineItem += string("<em>") + itemM + string("</em>") + itemE;
            Spos = Epos+8;
        }
        Spos = 0, Epos = 0;
        Spos = lineItem.find("[");
        while(Spos!=lineItem.npos){
            string item2 = lineItem.substr(Spos+1);
            Epos = item2.find("](");
            if(Epos!= item2.npos){
                string item3 = item2.substr(Epos+2);
                Epos2 = item3.find(")");
                if(Epos2 != item3.npos){
                    lineItem = lineItem.substr(0, Spos);
                    lineItem += string("<a href=\"");
                    lineItem += item3.substr(0, Epos2);
                    lineItem += string("\">") + item2.substr(0, Epos) + string("</a>") + item3.substr(Epos2+1);
                    Spos = lineItem.find("[");
                }
                else{
                    break;
                }
            }
            break;
        }
        inputsText.push_back(string(lineItem));
        if(exeline[0] == '\0'){
            inputLabel.push_back(0);   // 空行
            continue;
        }
        if(exeline[0] == '#'){
            for(int i = 0; i<strlen(exeline); i++){
                if(exeline[i] != '#'){
                    if(exeline[i] == ' '){
                        inputLabel.push_back(2); // 标题
                    }
                    else{
                        inputLabel.push_back(1); // 普通文字
                    }
                    break;
                }
            }
            continue;
        }
        if(exeline[0] == '*' && exeline[1] == ' '){
            inputLabel.push_back(3);    // 列表
            continue;
        }
        inputLabel.push_back(1);   // 普通文字
    }
    int lineNum = inputLabel.size();

    for(int i = 0; i<lineNum; i++){
        if(inputLabel[i] == 0) continue;
        if(inputLabel[i] == 2){
            if(i == lineNum - 1 || inputLabel[i+1] == 0){
                int lev = 0;
                while(inputsText[i][lev]=='#'){
                    lev++;
                }
                int pos = lev;
                lev = min(lev, 6);
                char num[2] = "0";
                num[0] += lev;
                while(inputsText[i][pos]==' ') pos++;
                string item = inputsText[i].substr(pos);
                result += string("<h") + string(num) + string(">") + item + string("</h") + string(num) + string(">\n");
                continue;
            }
        }
        if(inputLabel[i] == 3){
            int line = i;
            while(inputLabel[line] == 3 && line < lineNum){
                line++;
            }
            if(inputLabel[line] == 0 || line == lineNum){
                // 真的是列表
                result += string("<ul>\n");
                for(;i<line; i++){
                    result += string("<li>");
                    for(int pos = 1; pos<inputsText[i].size(); pos++){
                        if(inputsText[i][pos] != ' '){
                            result += inputsText[i].substr(pos);
                            break;
                        }
                    }
                    result += string("</li>\n");
                }
                result += string("</ul>\n");
                continue;
            }
        }
        //剩下的就是普通行
        int line = i;
        while(inputLabel[line] != 0 && line<lineNum){
            line++;
        }
        result += string("<p>");
        while(i < line - 1){
            result += inputsText[i] + string("\n");
            i++;
        }
        result += inputsText[i] + string("</p>\n");
    }
    cout << result;
    return 0;
}
