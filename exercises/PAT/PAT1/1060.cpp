#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string str1, str2;
    cin >> N >> str1 >> str2;
    int n1 = 0, n2 = 0;
    for(int i = 0; i<N; i++){
        n1 *= 10;
        n2 *= 10;
        n1 += str1[i] - '0';
        n2 += str2[i] - '0';
    }
    if(str1[i]>='5') n1++;
    if(str2[i]>='5') n2++;
    if(n1 == n2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
