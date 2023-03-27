#include <iostream>
using namespace std;
int arr[11];
int n, m;

int main(){
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        //무게마다 분류해준다.
        arr[num] +=1;
    }
    int result = 0;
    for(int i = 1;i<=m;i++){
        //a가 선택할 수 있는 경우의 수 제외
        n -= arr[i];
        result += arr[i]*n;
    }
    cout << result << "\n";
    return 0;
}