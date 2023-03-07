#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> arr;
int m;
vector<int> arr2;
int binarySearch(vector<int> &arr, int target, int start, int end){
    while(start<=end){
        int mid = (start+end)/2;
        while(arr[mid] == target) return mid;
        else if(arr[mid]>target) end = mid-1;
        else start = mid + 1;
    }
    return -1;
}


int main(){
    
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        arr2.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0;i<arr2.size();i++){
        int res = binarySearch(arr, arr2[i],0, n-1);
        if(res!=-1){
            cout << "yes" << " "; 
        }
        else{
            cout << "no" << " ";
        }
    }
    return 0;

}