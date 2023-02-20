#include <iostream>
using namespace std;
//나이트가 이동할 수 있는 8가지 방향 정의
//수평 이동, 수직 이동
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
string inputdata;
int main(){
    cin >> inputdata;
    int row = inputdata[1] - '0';
    int col = inputdata[0] - 'a' + 1;

    int result = 0;
    for(int i = 0;i<8;i++){
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];
        if(nextRow >= 1 && nextRow <=8 && nextCol>=1 && nextRow <= 8){
            result ++;
        }
    }
    cout << result << '\n';

    
    
    return 0;
}