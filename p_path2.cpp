#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int map[501][501];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<501;i++){
        fill(map[i], map[i]+501, INF);
    }
    //자기 자신에서 자기자신으로 가는 비용 0으로 초기화
    for(int a = 1;a<=n;a++){
        for(int b = 1;b<=n;b++){
            if(a==b) map[a][b] = 0;
        }
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        //바로 그래프에 넣기
        map[a][b] = 1;
    }
    //플로이드 워셜 알고리즘 
    for(int k = 1;k<=n;k++){
        for(int a = 1;a<=n;a++){
            for(int b = 1;b<=n;b++){
                map[a][b] = min(map[a][b], map[a][k]+map[k][b]);
            }
        }
    }
    int result = 0;
    for(int i = 1;i<=n;i++){
        int cnt = 0;
        for(int j = 1;j<=n;j++){
            if(map[i][j]!=INF || map[j][i]!=INF){
                cnt+=1;
            }
        }
        if(cnt == n) {
            result+=1;
        }

    }
    cout << result << "\n";
    return 0;
}