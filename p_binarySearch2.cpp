#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int binarySearch(vector<int> &v, int start, int end){
    //고정 점을 찾을 수 없을때
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(v[mid] == mid) return mid;
    else if(v[mid]>mid) return binarySearch(v, start, mid-1);
    else return binarySearch(v, mid+1, end);

}
int main(){
    
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int index = binarySearch(v, 0, n-1);
    cout << index << "\n";
    return 0;
}