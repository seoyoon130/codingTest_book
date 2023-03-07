#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int d[1001];
    d[1] = 1;
    d[2] = 3;
    for(int i = 3;i<=n;i++){
        d[i] = (d[i-1]+2*d[i-2])%796796;
    }
    cout << d[n] << '\n';
    return 0;
}