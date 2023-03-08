#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int sum = 0;
    int mid = str.size()/2;
    for(int i = 0;i<mid;i++){
        sum += str[i] -'0';
    }
    for(int i = mid; i<str.size();i++){
        sum -=str[i] - '0';
    }
    if(sum == 0) cout << "LUCKY" << "\n";
    else cout << "READY" << "\n";
    return 0;
}