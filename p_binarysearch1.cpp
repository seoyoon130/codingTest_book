#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countByRange(vector<int> &v, int leftValue, int rightValue){
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    //특정한 숫자가 몇번 나오는지 탐색하고자 할때 
    int cnt = countByRange(v, x, x);
    if(cnt == 0){
        cout << -1 << "\n";
    }
    else {
        cout << cnt << "\n";
    }
     
    
    return 0;
}