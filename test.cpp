#include <iostream>

using namespace std;

int main(){
    int m;
    // int * pr = new int[m]; 要先獲得 m 才可以使用動態陣列
    int sum = 0;

    cout << "m = ";
    cin >> m;

    int * pr = new int[m];

    for(int i = 0; i < m; i++){
        cout << "pr[" << i << "] = ";
        cin >> pr[i];
        sum += pr[i];
    }

    cout << "Sum of " << m << " numbers : " << sum << endl; 
    
    delete [] pr;

    system("pause");
    return 0;
}