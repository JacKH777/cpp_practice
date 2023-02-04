# 3-1 動態配置記憶體

## 3-1-1 and 3-1-2
配置動態變數與陣列 </br>
EX. </br>
```c++
//Sum Of Array
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
    
    delete [] pr; //最後要釋放記憶體

    system("pause");
    return 0;
}

/*
m = 3
pr[0] = 1
pr[1] = 2
pr[2] = 3
Sum of 3 numbers : 6
Press any key to continue . . .
*/
```

# 3-2 單向串列 (Single Linked List)
一節點由兩個欄位組成，即資料欄以及指標欄，而指標欄會指出下一個元素的記憶體所在位址。

          s1     -->      s2      -->       s3
    [data1|ptr1] --> [data2|ptr2] --> [data3|ptr3]
