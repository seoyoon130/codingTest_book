#include <iostream>
#include <algorithm>
using namespace std;
int n;
int vect[501];

int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> vect[i];
    }
    sort(vect, vect+n, greater<int>());
    for(int i = 0;i<n;i++){
        cout << vect[i] << "\n";

    }
    return 0;
}