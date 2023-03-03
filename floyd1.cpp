#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, m;
int x, k;
int map[101][101];

int main(){
    cin >> n >> m;
    for(int i = 0;i<101;i++){
        fill(map[i], map[i]+101, INF);
    }

    for(int i = 0;i<m;i++){
        int s, e;
        cin >> s >> e;
        map[s][e] = 1;
        map[e][s] = 1;
    }
    cin >> x >> k;
    //자기자신은 0으로 채우기
    for(int y=1;y<=n;y++){
        for(int x = 1;x<=n;x++){
            if(y==x) {
                map[y][x] = 0;
            }
        }
    }
    //점화식
    for(int k = 1;k<=n;k++){
        for(int a = 1;a<=n;a++){
            for(int b= 1;b<=n;b++){
                map[a][b] = min(map[a][b], map[a][k]+map[k][b]);
            }
        }
    }
    int dis = map[1][k] + map[k][x];
    if(dis >= INF){
        cout << "-1" << "\n";
    }
    else {
        cout << dis << "\n";
    }
    return 0;
}