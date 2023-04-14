#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int n, m;
int start = 1;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만들기
vector<pair<int, int> > graph[20001];
// 최단 거리 테이블 만들기
int d[20001];
void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    //큐가 비어있지 않다면
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now]<dist) continue;
        for(int i = 0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost<d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }   
}
int main(){
    
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    //최단 거리 테이블 무한으로 초기화
    fill(d, d+20001, INF);
    //다익스트라 알고리즘 돌리기
    dijkstra(start);
    int maxNode = 0;
    int maxDistance = 0;
    vector<int> result;
    for(int i = 1;i<=n;i++){
        if(maxDistance <d[i]){
            maxNode = i;
            maxDistance = d[i];
            result.clear();
            result.push_back(maxNode);
        }
        else if(maxDistance == d[i]){
            result.push_back(i);
        }
    }
    cout << maxNode << ' ' << maxDistance << ' ' << result.size()<< "\n";
    return 0;
}