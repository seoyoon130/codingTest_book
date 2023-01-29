#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int vect[10001];
    int n, m, k;
    //가장 큰수, 그 다음으로 큰 수를 지정해준다.
    int max1, max2;
    int sum = 0;
    cin >> n >> m>>k;
    for(int i = 0;i<n;i++){
        cin >> vect[i];
    }
    sort(vect, vect+n);
    max1 = vect[n-1];
    max2 = vect[n-2];
    
    while(1){
        for(int i = 0;i<k;i++){
            if(m==0) break;
            sum += max1;
            m--;
        }
        if(m==0) break;
        sum += max2;
        m--;

    }
    cout << sum;

    return 0;
}