#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, m, k, x;
    vector<int> v[300001];
    //최단 거리 저장 vector
    vector<int> d(300001, -1);

    cin >> n >> m >> k >> x;
    for(int i = 0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    //출발 도시까지의 거리 : 0
    d[x] = 0;
    //최단거리 : bfs
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i];
            if(d[next] == -1){
                d[next] = d[now]+1;
                q.push(next);
            }
        }
    }
    bool check = false;
    for(int i = 1;i<=n;i++){
        if(d[i] == k){
            cout << i << "\n";
            check = true;
        }
    }
    if(!check) cout << -1 << "\n";
    return 0;
}