#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*가장 긴 증가하는 부분 수열 찾기*/
int main(){
    int n;
    vector<int> v;
    int dp[2001];
    
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = 0;i<2001;i++){
        dp[i] = 1;

    }
    reverse(v.begin(), v.end());
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int maxValue = 0;
    for(int i = 0;i<n;i++){
        maxValue = max(maxValue, dp[i]);
    }
    cout << n-maxValue << "\n";
    return 0;
}