#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;
int graph[MAX][MAX];
int main(){
    int n, m;
    cin >> n >> m;
    //1. 그래프를 초기화 해주기
    for(int i =0;i<MAX;i++){
        fill(graph[i], graph[i]+101, INF);
    }
    //2. 자기 자신에서 자기자신으로 가는 비용을 0으로 초기화
    for(int a = 1;a<=n;a++){
        for(int b = 1;b<=n;b++){
            if(a==b) graph[a][b] = 0;
        }
    }
    for(int i = 0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(graph[a][b]>c) graph[a][b] = c;

    }
    for(int k = 1;k<=n;k++){
        for(int a = 1;a<=n;a++){
            for(int b = 1;b<=n;b++){
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]);
            }
        }
    }
    //수행된 결과를 출력하기
    for(int a = 1;a<=n;a++){
        for(int b = 1;b<=n;b++){
            if(graph[a][b]== INF){
                cout << 0 << " ";
            }
            else{
                cout << graph[a][b] << " ";
            }
     
        }
        cout << "\n";
    }
    return 0;
}