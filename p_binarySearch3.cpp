#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
    vector<int> v;

int findGap(int n, int c){
    int r = v[n-1];
    int l = 1;
    int ans = 0;
    while(l<=r){
        int cnt = 1;
        int mid = (r+1)/2;
        int start = v[0];
        for(int i = 1;i<n;i++){
            if(v[i]-start>=mid) {
                start = v[i];
                cnt++;
            }
        }
        if(cnt>=c) {
            ans = mid;
            l = mid+1;
        }
        else r = mid -1;
    }
    return ans;
}
int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int answer = findGap(n, c);
    cout << answer << "\n";
    return 0;

}