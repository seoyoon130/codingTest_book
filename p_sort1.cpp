#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
    string name;
    int kor;
    int eng;
    int math;
    
};
bool cmp(const student &now, const student &last){
    //국어 점수가 다를때는 큰 순으로 정렬
    if(now.kor!=last.kor) return now.kor>last.kor;
    //국어 점수가 같으면 영어 점수는 오름차순으로
    else{
        if(now.eng!=last.eng) return now.eng < last.eng;
        else{
            if(now.math!=last.math) return now.math>last.math;
            return now.name<last.name;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<student> stu(n); 
    for(int i = 0;i<n;i++){
        cin >> stu[i].name >>stu[i].kor>> stu[i].eng >> stu[i].math; 
        
    }
    //1. 국어 내림차순
    //2. 국어가 같으면, 영어점수 오름차순
    //3. 국어점수와 영어점수가 같으면 이름이 사전순으로 증가하는 순으로 
    sort(stu.begin(), stu.end(), cmp);
    for(int i = 0;i<n;i++){
        cout << stu[i].name << "\n";
    }
    return 0;
}