#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    while(n>=k){
        //나누어 떨어지지 않는 경우
        if(n%k!=0){
            n-=1;
            cnt++;
        }
        n = n/k;
        cnt++;

    }
    while(n>1){
        n--;
        cnt++;
    }
    cout << cnt;
    return 0;
}