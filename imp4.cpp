#include <iostream>
using namespace std;
//좌표를 입력 받을 map
int map[51][51];
//방문한 위치를 저장하기 위한 map
int visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m;
int y, x, d;

//왼쪽으로 회전
void turn_left(){
    d -= 1;
    if(d==-1) d = 3;
}
int main(){
    
    cin >> n >> m;
    cin >> y >> x >> d;
    //현재 좌표 방문 처리
    visited[y][x] = 1;
    //전체 맵 정보를 입력 받기
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> map[y][x];    
        }
    }
    //시뮬레이션 시작
    int cnt =1;
    int turn_time = 0;
    while(1){
        //일단 왼쪽으로 회전 한 다음에
        turn_left();
        int ny = y+dy[d];
        int nx = x+dx[d];
        //회전 이후, 정면에 가보지 않은 칸이 존재하는 경우에 이동
        if(visited[ny][nx]==0 && map[ny][nx] == 0){
            visited[ny][nx] = 1;
            y = ny;
            x = nx;
            cnt++;
            turn_time = 0;
            continue;
        }
        //회전 후 정면에 가보지 않은 칸이 없거나 바다인 경우
        else turn_time +=1;
        //네 방향 모두 갈 수 없는 경우
        if(turn_time==4){
            ny = y-dy[d];
            nx = x-dx[d];
            //뒤로 갈 수 있다면 이동하기
            if(map[ny][nx] == 0){
                x = nx;
                y = ny;
            }
            else break;
            turn_time = 0;
        }
    }
    cout << cnt << "\n";
    return 0;
}