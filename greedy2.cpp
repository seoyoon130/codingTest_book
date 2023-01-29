#include<iostream>
#include<algorithm>
using namespace std;
int result;
int n, m;
int main(){
    
    cin >> n >> m;
   
    for(int i = 0;i<n;i++){
        int min_value = 10001;
        for(int j = 0;j<m;j++){
            int x;
            cin >> x;
            min_value = min(min_value, x);
        }
        result = max(result,min_value);
    }
    cout << result << "\n";
    
    return 0;
}