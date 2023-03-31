#include <iostream>
#include <vector>
using namespace std;
int n, k, l;
int map[101][101];
int main(){
    vector<pair<int, char> > dir;    
    cin >> n >> k;
    for(int i = 0;i<k;i++){
        int a, b;
        cin >> a >> b;
        //사과 자리 표시해주기
        map[a][b] = 1;
    }
    cin >> l;
    for(int i = 0;i<l;i++){
        char a;
        int b;
        cin >> a >> b;
        dir.push_back(make_pair{a, b});
        
    }
    return 0;
}
