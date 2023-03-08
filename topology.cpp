#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v, e;
//진입차수 저장 정렬
int indegree[100001];
vector<int> graph[100001];
void topologySort(){
    vector<int> result;
    queue<int> q;
    //처음 시작할때는 진입차수가 0인 노드를 큐에 삽입한다
    for(int i = 1;i<=v;i++){
        if(indegree[i] == 0) q.push(i);
    }
    //큐가 빌때까지
    while(!q.empty()){
        //맨 앞에 있는 원소 꺼내기 
        int now = q.front();
        q.pop();
        result.push_back(now);
        //해당 원소와 연결된 노드들의 진입차수에서 1빼기
        for(int i = 0;i<graph[now].size();i++){
            indegree[graph[now][i]] -= 1;
            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            } 
        }
    }
    for(int i = 0;i<result.size();i++){
        cout << result[i] << " ";
    }
}
int main(){
    cin >> v >> e;
    for(int i = 0;i<e;i++){
        int a, b;
        cin >> a >> b;
        //정점 a~b 로 이동 가능
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    topologySort();
    return 0;
}