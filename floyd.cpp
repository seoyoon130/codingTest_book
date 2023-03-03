#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, m;
int graph[501][501];

int main(){
    cin >> n >> m;
    //최단 거리의 테이블을 모두 무한으로 초기화
    for(int i = 0;i<501;i++){
        fill(graph[i], graph[i]+501, INF);
    }
    //자기 자신에서 자기자신으로 가는 비용을 0으로 초기화
    for(int a = 1;a<=n;a++){
        for(int b = 1;b<=n;b++){
            if(a==b) graph[a][b] = 0;
        }
    } 
    //각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for(int i = 0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    //점화식에 따라 플로이드 워셜 알고리즘 수행
    //1. 중간지점
    for(int k = 1;k<=n;k++){
        //2. 첫 지점
        for(int a = 1;a<=n;a++){
            //3. 마지막 지점
            for(int b = 1;b<=n;b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    //수행된 결과를 출력
     for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
            if (graph[a][b] == INF) {
                cout << "INFINITY" << ' ';
            }
            // 도달할 수 있는 경우 거리를 출력
            else {
                cout << graph[a][b] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}