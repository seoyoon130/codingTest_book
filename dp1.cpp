#include <iostream>
using namespace std;
//한번 계산된 결과를 메모이제이션 하기 위한 리스트 초기화

long long d[100];

long long fibo(int x){
    //종료 조건 (1혹은2일때 1을 반환)
    if(x==1 || x==2){
        return 1;
    }
    //이미 계산한 적이 있는 문제라면 그대로 반환
    if(d[x]!=0){
        return d[x];
    }
    //아직 계산하지 않은 문제라면 점화식에 따라서 피보나치 결과 반환
    d[x] = fibo(x-1)+fibo(x-2);
    return d[x];
}
int main(){
    cout << fibo(50) << "\n";
}