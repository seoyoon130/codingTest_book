#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
vector<int> a, b;

int main(){
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    //a는 오름차순 정렬
    sort(a.begin(), a.end());
    //b는 내림차순 정렬
    sort(b.begin(), b.end(), greater<int>());
    for(int i = 0;i<k;i++){
        if(a[i]<b[i]) swap(a[i], b[i]);
        else break;
    }
    long long result = 0;
    for(int i = 0;i<n;i++){
        result += a[i];
    }
    cout << result << "\n";
    return 0;
}