#include <iostream>
#include <vector>
using namespace std;
int v, e;
vector<pair<int, pair<int, int> > > edges;
int result = 0;
int parent[100001];
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
    cin >> v >> e;
    //부모 테이블을 자기 자신으로 초기화하기
    for(int i = 1;i<=v;i++){
        parent[i] = i;
    }
    //모든 간선에 대한 정보를 입력받기
    for(int i = 0;i<e;i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        //비용순으로 정렬하기 위해서 튜플의 첫번째 원소를 비용으로 설정
        edges.push_back({cost, {a, b}});
    }

    //간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());

    //간선을 하나씩 확인하기
    for(int i = 0;i<edges.size();i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        //부모노드가 다를때, 즉 사이클이 발생하지 않는 경우에만 집합에 포함
        if(findParent(a)!=findParent(b)){
            //union함수 써주기
            unionParent(a, b);
            result+= cost;
        }
    }
    cout << result << "\n";
    return 0;
}