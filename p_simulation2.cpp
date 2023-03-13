#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<char> temp;
    int sum = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            temp.push_back(s[i]);
        }
        else {
            sum+=s[i]-'0';
        }
    }
    sort(temp.begin(), temp.end());
    for(int i = 0;i<temp.size();i++){
        cout<< temp[i];
    }
    if(sum!=0) cout << sum;
    cout << "\n";
    
    return 0;
}