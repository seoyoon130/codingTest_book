#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<string, int> > v;
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        string name;
        int grade;
        cin >> name >> grade;
        v.push_back(make_pair(name, grade));
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<n;i++){
        cout << v[i].first << " ";
    }
    return 0;
}