#include <iostream>
#define MAX 30001
using namespace std;
//1. dp 여부를 확인할 d 배열 필요
long long d[MAX];

int main(){
    int x;
    cin >> x;
    //보텀업 방식
    for(int i = 2;i<=x;i++){
        //현재의 수에서 1을 빼는 경우
        d[i] = d[i-1]+1;
        //현재의 수가 2로 나누어 떨어지는 경우
        //1을 더해주는 이유 : 연산횟수를 저장해주어야 하기 때문
        if(i%2==0){
            d[i] = min(d[i], d[i/2]+1);
        }
        //현재의 수가 3로 나누어 떨어지는 경우
        if(i%3==0){
            d[i] = min(d[i], d[i/3]+1);
        }
        if(i%5==0){
            d[i] = min(d[i], d[i/5]+1);
 
        }
    }
    cout << d[x] << "\n";
    return 0;
}