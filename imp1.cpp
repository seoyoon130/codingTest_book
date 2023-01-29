#include <iostream>
using namespace std;
string plans;
int y = 1, x = 1;
int n;
//up, down, left, right 순
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char types[4] = {'U', 'D', 'L', 'R'};

int main(){
    
    cin >> n;
    getline(cin, plans);
    int ny, nx;
    for(int i = 0;i<plans.size();i++){
        char plan = plans[i];
        for(int j = 0;j<4;j++){
            if(plan == types[j]){
               nx = x+dx[j];
               ny = y+dy[j]; 
            }
        }
        if(nx<1 || ny<1||ny>n||nx>n) continue;
        x = nx;
        y = ny;
    }
    cout << y << " " <<x << "\n";
    return 0;
}