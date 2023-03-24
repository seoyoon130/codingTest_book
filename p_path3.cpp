#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int main(){
    int t;
    cin >> t;
    int map[126][126];
    int dp[126][126];
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    while(--t){
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            fill(dp[i], dp[i]+126, INF);
        }
        //시작 위치는 0, 0
        int y = 0, x = 0;
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({-map[y][x], {0, 0}});
        dp[y][x] = map[x][y];

        while(!pq.empty()){
            int dist = -pq.top().first;
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            pq.pop();
            if(dp[y][x]<dist) continue;
            for(int i = 0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                int cost = dist+map[y][x];
                //현재 노드를 거쳐, 다른 노드로 이동하는 거리가 더 짧은 경우
                if(cost<dp[ny][nx]){
                    dp[ny][nx] = cost;
                    pq.push({-cost, {ny, nx}});
                }
            }
        }
        cout << dp[n-1][n-1] << "\n";
    }
    
    return 0;
}