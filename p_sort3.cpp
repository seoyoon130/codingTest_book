#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second) return a.first<b.first;
    return a.second>b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > v;
    int p = stages.size();
    for(int i = 1;i<=N;i++){
        int cnt = count(stages.begin(), stages.end(), i);
        double fail = 0;
        if(p>=1){
            fail = (double)cnt/p;
            
        }
        v.push_back({i, fail});
        p -= cnt;
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0;i<N;i++){
        answer.push_back(v[i].first);
    }
    return answer;
}