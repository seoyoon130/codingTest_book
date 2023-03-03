#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 30001
#define INF 1e9
using namespace std;
int n, m, c;
int x, y, z;
vector <pair<int, int> > map[MAX];
//최단 거리 테이블
int d[MAX];
void dijkstra(int start){
    //우선순위 큐 만들기
    //비용과 거리 저장
    priority_queue<pair<int, int>> pq;
    //시작 노드에서는 가는 것이 0
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        //현재 노드가 이미 처리된 적이 있는 노드라면 
        if(d[now]<dist) continue;
        for(int i = 0;i<map[now].size();i++){
            int cost = dist + map[now][i].second;

            if(cost<d[map[now][i].first]){
                d[map[now][i].first] = cost;
                pq.push(make_pair(-cost, map[now][i].first));
            }
        }
    }

}
int main(){
    cin >> n >> m >> c;
    for(int i = 0;i<m;i++){
        cin >> x >> y >> z;
        map[x].push_back({y, z});
    }
    //최단 거리 테이블 초기화
    fill(d, d+MAX, INF);
    dijkstra(c);
    //도달 할 수 있는 노드의 갯수
    int count = 0;
    //도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리
    int maxDist = 0;

    for(int i = 1;i<=n;i++){
        if(d[i]!=INF){
            count += 1;
            maxDist = max(maxDist, d[i]);
        }
    }
    //시작 노드는 제외하므로 
    cout << count-1 << " " << maxDist << "\n";
    return 0;
}