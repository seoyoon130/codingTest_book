#include <iostream>
#define MAX 1001
using namespace std;
int map[MAX][MAX];
int n, m;
int res = 0;
bool dfs(int y, int x){
    //범위를 벗어나면 즉시 종료
   if(x<=-1||x>=n||y<=-1||y>=m){
        return false;
   }
   if(map[y][x] == 0){
        map[y][x] = 1;
        dfs(y-1, x);
        dfs(y, x-1);
        dfs(x+1, y);
        dfs(x, y+1);
        return true;
 
   }
   return false;
}
int main(){
    cin >> n >> m;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> map[y][x];
        }
    }
    int res = 0;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            if(dfs(y, x)){
                res++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}