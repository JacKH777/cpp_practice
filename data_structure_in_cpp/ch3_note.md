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

         s1      -->      s2      -->      s3
    [data1|ptr1] --> [data2|ptr2] --> [data3|ptr3] --> NULL

**ptr1** 會指向 **&s2**，而 **ptr#** 則會指向 **NULL** 表示結束

EX. 考慮以下資料，建立單向串列 </br>
$$
 \begin{bmatrix}
   Num & Name & Score \\
   1 & A & 60         \\
   2 & B & 50         \\
   3 & C & 80         \\
   4 & D & 100        \\
  \end{bmatrix}
$$

```c++
#include <iostream>

using namespace std;

class list{
    public:
        int num;
        char name;
        int score;
        list * next;
};

typedef class list node;

/*亦可使用
typedef class list{
    int num;
    char name;
    int score;
    list * next;
}node;
*/

typedef node * link; //定義一個新的型別名稱 link，表示指向 node 類型的指標

int main(){
    link node_head, node_current, node_last; //first node, current node, last node
    node_head = new node; //給第一個node地址

    //檢查是否成功配置記憶體
    if(!node_head){
        cout << "記憶體配置失敗";
        exit(1); //程式出現問題，強制退出
    }

    //第一組
    cout << "Num = ";
    cin >> node_head -> num;
    cout << "Name = ";
    cin >> node_head -> name;
    cout << "Score = ";
    cin >> node_head -> score;
    node_head -> next = NULL;

    node_last = node_head; //最後一個node

    //下一組
    cout << "Next num(press q to finish) = ";
    node_current = new node;

    //檢查是否成功配置記憶體
    if(!node_current){
        cout << "記憶體配置失敗";
        exit(1); //程式出現問題，強制退出
    }

    //當輸入成功，建立新的node，輸入q則結束
    while(cin >> node_current -> num){
        cout << "Name = ";
        cin >> node_current -> name;
        cout << "Score = ";
        cin >> node_current -> score;
        node_current -> next = NULL;

        node_last -> next = node_current; //node_last 所指的 next 指到 node_current
        //node_last = node_new;
        node_last = node_last -> next; //node_last 指到最後一個值

        cout << "Next num(press q to finish) = "; //new node
        node_current = new node;

        if(!node_current){
            cout << "記憶體配置失敗";
            exit(1); //程式出現問題，強制退出
        }   
    }

    node_current = node_head; //node_current 指到最前面

    //遍歷
    cout << "all students score :" << endl;
    while(node_current != NULL){
        cout << "Num : " << node_current -> num << " Name : " << node_current -> name << " Score : " << node_current -> score << endl;
        node_head = node_current; //node_head 更新成 node_current
        node_current = node_current -> next; //node_current 指向下一個
        delete node_head; //解放記憶體
    }
    
    system("pause");
    return 0;
}
```
