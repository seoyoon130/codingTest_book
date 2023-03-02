#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, start;
//각 노드에 연결되어있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[100001];
//최단 거리 테이블 만들기
int d[100001];
void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    //1. 시작 노드 0 으로 초기화
    pq.push({0, start});
    d[start] = 0;
    //큐가 비어있지 않다면
    while(!pq.empty()){
        //현재 노드까지의 비용
        int dist = -pq.top().first;
        //현재 노드
        int now = pq.top().second;
        pq.pop();
        //현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if(d[now]<dist) continue;
        //현재 노드와 연결된 다른 인접한 노드들을 확인
        for(int i = 0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost<d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}
int main(){
    cin >> n >> m >> start;
    //모든 간선 정보를 입력 받기
    for(int i = 0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    //최단 거리 테이블을 모두 무한으로 초기화
    fill_n(d, 100001, INF);
    //다익스트라 알고리즘 수행
    dijkstra(start);
    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; i++) {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << d[i] << '\n';
        }
    }
    return 0;
}