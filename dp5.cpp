#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 0;i<n;i++){
        int k;
        cin >> k;
        arr.push_back(k);
    }
    //계산된 결과를 저장하기 위한 dp 테이블 초기화
    vector<int> d(m+1, 10001);

    d[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j = arr[i];j<=m;j++){
            //i-k 원을 만드는 방법이 존재하는 경우
            if(d[j-arr[i]]!=10001){
                d[j] = min(d[j], d[j-arr[i]]+1);
            }
        }
    }
    if(d[m] == 10001){
        cout << "-1" << "\n";
    }
    else {
        cout << d[m] << "\n";
    }
    return 0;
}