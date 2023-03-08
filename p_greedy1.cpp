#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    //그룹 순
    int result = 0;
    //모험가 수
    int cnt = 0;
    for(int i = 0;i<n;i++){
        cnt++;
        //현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면,
        if(cnt>=v[i]){
            result++;
            cnt = 0;
        }
    }
    cout << result << " ";
    return 0;
}