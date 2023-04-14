#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
string a, b;
int editDist(string a, string b){
    int n = a.size();
    int m = b.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));

    //dp 테이블 초기 설정
    for(int i = 1;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j = 1;j<=m;j++){
        dp[0][j] = j;
    }
    //최소 편집 거리 계산
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}
int main(){
    
    cin >> a >> b;
    cout << editDist(a, b) << "\n";

    return 0;
}