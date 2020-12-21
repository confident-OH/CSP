#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool check(char c)
{
    if(c>='0'&&c<='9') return true;
    if(c>='A'&&c<='N') return true;
    return false;
}

bool check2(char c)
{
    if(c>='a'&&c<='z') return true;
    if(c>='A'&&c<='Z') return true;
    return false;
}

int main()
{
    char sum[8][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string str1, str2;
    int day, hour, minute;
    getline(cin, str1);
    getline(cin, str2);
    int i = 0;
    while(str1[i]!=str2[i] || str1[i]<'A' || str1[i]>'G')
        i++;
    day = str1[i++] - 'A';
    while(str1[i]!=str2[i] || !check(str1[i]))
        i++;
    if(str1[i]>='0'&&str1[i]<='9'){
        hour = str1[i] - '0';
    }
    else{
        hour = str1[i] - 'A' + 10;
    }
    getline(cin, str1);
    getline(cin, str2);
    i = 0;
    while(!check2(str1[i])||str1[i]!=str2[i]) i++;
    minute = i;
    cout << sum[day] << " " << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << endl;
    return 0;
}
