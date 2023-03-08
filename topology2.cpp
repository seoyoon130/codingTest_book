#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
//진입차수 저장 
int indegree[100001];
vector<int> graph[100001];
//각 강의 시간을 0으로 초기화
int times[501];
void topologySort(){
    vector<int> result(501);
    for(int i = 1;i<=n;i++){
        result[i] = times[i];
 
    }
    queue<int> q;
    //처음 시작할때는 진입차수가 0인 노드를 큐에 삽입
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<graph[now].size();i++){
            result[graph[now][i]] = max(result[graph[now][i]], result[now]+times[graph[now][i]]);
            indegree[graph[now][i]]-=1;
            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout << result[i] << "\n";
    }

}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        times[i] = x;
        while(true){
            cin >> x;
            if(x==-1) break;
            //진입차수 1 증가
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }
    topologySort();
    return 0;
}