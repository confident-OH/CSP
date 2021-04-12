#include <iostream>

using namespace std;

int main()
{
    int n;
    int a;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a;
        int result = 0;
        while(a>0){
            if(a&1) result++;
            a = a>>1;
        }
        cout << result << " ";
    }
    return 0;
}
