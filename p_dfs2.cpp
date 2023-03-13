#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int map[9][9];
queue<pair<int, int>> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void bfs(int start){
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            if(map[y][x] == 2){
                q.push(y, x);
            }
        }
    }
    while(!q.empty()){
        
    }
}
int main(){   
    cin >> n >> m;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> map[y][x];
        }
    }
    bfs(0);
    
    return 0;
}