#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str;
int main(void) {
    cin >> str;
    long long result = str[0] - '0';
    for(int i = 0;i<str.size();i++){
        int num = str[i] - '0';
        if(num<=1 || result <=1){
            result += num;
        }
        else {
            result *= num;
        }
    }
    cout << result << "\n";
   return 0;
}