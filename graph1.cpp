#include <iostream>
using namespace std;
int v, e;
int parent[100001];
//2. 먼저 부모 노드를 찾아줌
int findParent(int x){
    //루트노드라면(즉 x 와 parent x가 같다면 x로 리턴)
    if(x==parent[x]) return x;
    //루트로드가 아니라면 재귀적으로 호출
    return findParent(parent[x]);
}
//1. 두원소가 속한 집합을 합치기
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> v >> e;
    for(int i = 1;i<=v;i++){
        parent[i] = i;
    }
    //union 연산을 각각 수행
    for(int i = 0;i<e;i++){
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
    cout <<"각 원소가 속한 집합 : ";
    for(int i = 1;i<=v;i++){
        cout << findParent(i) << " ";
    }
    cout << "\n";
    cout << "부모 테이블 : ";
    for(int i = 1;i<=v;i++){
        cout << parent[i] << " ";
    }
    cout << "\n";

    return 0;
}