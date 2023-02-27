#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int map[201][201];
int bfs(int y, int x){
    queue<pair<int, int> > q;
    q.push({y, x});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];

            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(map[ny][nx] == 0) continue;
            if(map[ny][nx] ==1){
                map[ny][nx]= map[ny][nx] +1;
                q.push({ny, nx});
            }
        }
    }
    return map[n-1][m-1];
}
int main(){
    cin >> n >> m ;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> map[y][x];
        }
    }
    cout << bfs(0, 0) << "\n";
    return 0;
}