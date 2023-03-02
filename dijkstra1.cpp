#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, m, start;
//각 노드에 연결되어있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[100001];
//방문한 적이 있는지 체크하는 배열
bool visited[100001];
//최단 거리 테이블 만들기
int d[100001];
int getSmallestNode(){
    int min_value = INF;
    int idx = 0;
    for(int i = 1;i<=n;i++){
        if(d[i]<min_value &&!visited[i]){
            min_value = d[i];
            idx = i;
        }

    }
    return idx;
}
void dijkstra(int start){
    //1. 시작 노드에 대해 0으로 초기화 및 방문 표시
    d[start] = 0;
    visited[start] = true;
    //2. 시작노드에서 아무것도 거치지 않고 바로 연결된 노드의 d 테이블 채우기
    for(int i = 0;i<graph[start].size();i++){
        d[graph[start][i].first] = graph[start][i].second;
    }
    //3. 시작 노드를 제외한 전체 n-1 개의 노드에 대해 반복
    for(int i = 0;i<n-1;i++){
        //3-1. 최단 거리가 가장 짧은 곳은 Now로 잡아주기 
        int now = getSmallestNode();
        visited[now] = true;
        //3-2. 현재 노드와 연결된 다른 노드를 확인
        for(int j = 0;j<graph[now].size();j++){
            int cost = d[now] + graph[now][j].second;
            //3-3.금액이 적다면 갱신해주기
            if(cost<d[graph[now][j].first]){
                d[graph[now][j].first] = cost;
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

    //모든 노드로 가기 위한 최단 거리를 출력
    for(int i = 1;i<=n;i++){
        if(d[i] == INF){
            cout << "INFINITY" << "\n";

        }
        else{
            cout << d[i] << '\n';
        }
    }
    return 0;
}