#include <iostream>
using namespace std;
int n, m;
int parent[100001];
//원소들의 부모 찾기
int findParent(int x){
    //루트노드가 아니라면, 루트노드를 찾을떄까지 재귀적으로 호출
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
//union 연산 수행
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}
int main(){
    
    cin >> n >> m;
    //1. 부모테이블을 자기 자신으로 초기화
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m;i++){
        int k, a, b;
        cin >> k >> a >> b;
        if(k==1){
            if(findParent(a)==findParent(b)){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
        else unionParent(a, b);
    }
    return 0;
}