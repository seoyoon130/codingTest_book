#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*최소 신장 트리를 만든 후에, 간선의 비용이 가장 큰 간선을 제거해주면 2개로 분할 할 수 있음. */
//부모 테이블
int parent[100001];
int n, m;
vector<pair<int, pair<int, int>>> edges;
int result = 0;
int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]); 
}
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}
int main(){
    //부모 테이블을 자기 자신으로 초기화 시키기
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});

    }
    //크루스칼 알고리즘을 하기 위해서는 먼저
    //간선을 비용순으로 정리해야한다.
    sort(edges.begin(), edges.end());
    //간선을 비용순으로 정리한 이후에
    //간선들을 하나씩 확인하며 현재의 간선이 사이클을 발생시키는지 확인한다.
    int maxCost = 0;

    for(int i = 0;i<edges.size();i++){
        int cost = edges[i].first;
        int v = edges[i].second.first;
        int e = edges[i].second.second;
        //부모노드가 다를떄, 즉 사이클이 발생하지 않을 경우에만 집합에 포함한다.
        if(findParent(v)!=findParent(e)){
            unionParent(v, e);
            result += cost;
            //큰 값이 마지막에 선택되므로
            maxCost = cost;
        }
    }
    cout << result - maxCost << "\n";
    return 0;
}