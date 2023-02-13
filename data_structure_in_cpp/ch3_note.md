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

## 3-2-1 單向串列建立
一節點由兩個欄位組成，即資料欄以及指標欄，而指標欄會指出下一個元素的記憶體所在位址。

         s1      -->      s2      -->      s3
    [data1|ptr1] --> [data2|ptr2] --> [data3|ptr3] --> NULL

**ptr1** 會指向 **&s2**，而 **ptr3** 則會指向 **NULL** 表示結束

EX. 考慮以下資料，建立單向串列 </br>

$$
 \begin{matrix}
   Num & Name & Score \\
   1 & A & 60         \\
   2 & B & 50         \\
   3 & C & 80         \\
   4 & D & 100        \\
  \end{matrix}
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

/*
Num = 1
Name = A
Score = 60
Next num(press q to finish) = 2
Name = B
Score = 50
Next num(press q to finish) = 3
Name = C
Score = 80
Next num(press q to finish) = 4
Name = D
Score = 100
Next num(press q to finish) = q
all students grade :
Num : 1 Name : A Score : 60
Num : 2 Name : B Score : 50
Num : 3 Name : C Score : 80
Num : 4 Name : D Score : 100
請按任意鍵繼續 . . .
*/
```

## 3-2-2 單向串列插入新節點

- 插入到第一個節點 </br>
  新節點的指標指向原來第一個節點，再將串列指標的頭移到新節點

```cpp
node_new -> next = node_head;
node_head = node_new;
```

- 插入到最後一個節點 </br>
  原本最後一個節點指向新節點，新節點指向 NULL

```cpp
node_last -> next = node_new;
node_last = node_new; //node_last 移到最後一位
node_last -> NULL;
```

- 插入到中間節點 </br>
  假設將新節點插入到 X 與 Y 中間，需要將 X 指向新節點，新節點指向 Y 即可

```cpp
node_X -> next = node_new;
node_new -> next = node_Y;
```

## 3-2-3 單向串列刪除節點

- 刪除第一個節點 </br>
  第一個節點的指標指向第二個節點

```cpp
node_top = node_head;
node_head = node_head -> next;
delete node_top;
```

- 刪除最後一個節點 </br>
  原本指向最後一個節點的指標，指向 NULL 即可

```cpp
node_current -> next = node_last; //node_current 原本指向 node_last
node_current -> next = NULL;
delete node_last;
```

- 刪除中間節點 </br>
  假設節點原本在 X 與 Y 中間，將 X 指向 Y

```cpp
node_current = node_X -> next;
node_X -> next = node_current -> next;
delete node_current;
```

## 3-2-4 單向串列反轉與連結

### 反轉 (invert)
![Image](https://i.imgur.com/R4R5b9t.png) </br>
程式碼如下：
```cpp
typedef class list{
    public:
        int num;
        char name[10];
        int score;
        class list * next;
}node;

typedef node * link;

link invert(link x){
    link p, q, r;
    p = x;
    q = NULL;
    
    while(p != NULL){
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }

    return q;
}

```

### 連結(concatenation)
若要合併兩個或以上的鏈結串列，只需將串列首尾相連即可

## 3-2-5 多項式表示法
EX. </br>
P(x) = 12x^5 + 23x^4 + 5x^2 + 4x + 1 </br>
可以表示成 </br>
P = (5, 12, 5, 23, 4, 5, 2, 4, 1, 1, 0) </br>
第一個數表示有幾個非零數，後面分別表示非零數的係數以及指數 </br>

**可以使用 Linked List 來表示多項式** </br>
使用三個欄位來進行表示 </br>

    一個 node 包含以下內容
    [ COEF | EXP | LINK ]  
    COEF : 該變數的係數
    EXP  : 該變數的指數
    LINK : 指到下一個節點的指標

EX. </br>
A(x) = 3x^2 + 6x -2 可以表示成以下 : </br>
[ 3 | 2 | LINK1 ] -> [ 6 | 1 | LINK2 ] -> [ -2 | 0 | LINK3 ] 

> 考慮如何將兩個多項式相加

# 3-3 環狀串列 (Circular Linked List)

單向串列具有方向性，若首指標被破壞或是遺失，整個串列都會遺失，且浪費整個串列的記憶體空間，因此考慮 **將最後一個節點指標指向串列首，而不是指向NULL**，其優點是可以從任何一個節點追蹤所有節點，缺點是需要多一個鏈結空間，**環狀鏈結串列走訪與單向的類似，不過檢查串列的結束條件為 ```ptr -> next != head```** </br>

## 3-3-1 環狀串列插入新節點
有以下兩種情況：
- 將新節點插在第一個節點前成為串列首 </br>
  將新節點指標指向原串列首節點，找到最後一個節點並將其指向新節點，並將串列首節點改成新節點
```cpp
node_new -> next = node_head;
node_current = node_head;
while(node_current -> next != node_head){ 
    node_current = node_current -> next;
} //當 next 是 head 時結束
node_last -> next = node_new;
node_head = node_new; //head 指向新的首節點
```

- 將新節點插在任意節點 </br>
  將新節點指向下一個節點，並將前一個節點 X 指向新節點

```cpp
node_new -> next = node_X -> next;
node_X -> next = node_new;
```

## 3-3-2 環狀串列刪除節點
有以下兩種情況：
- 刪除第一個節點 </br>
  將串列首移至第一個節點，並將最後一個節點的指標指向新串列首

```cpp
node_current = node_head;
while(node_current -> next != node_head){
    node_current = node_current -> next;
}
node_last = node_current; //找到最後一個node
node_current = node_head; //刪除串列首
node_head = node_head -> next; //指向下一個node
delete node_current;
node_last -> next = node_head;
```

- 刪除中間節點 </br>
  首先找到要刪除的節點 Y ，先找到 Y 前面一個節點 previous，並將 previous 指向 Y 的下一個節點

```cpp
node_previous = node_head; //從串列首開始
while(node_previous -> next != node_Y){ 
    node_previous  = node_previous -> next;
} //找到 node_previous
node_previous -> next = node_Y -> next; //node_previous 指向 Y 的下一個節點
delete node_Y; // 刪除 Y
```

## 3-3-3 環狀串列的連結
更改兩個環狀串列各一個指標即可(使其連在一起)

# 3-4 雙向串列 (Double Linked List)
單向串列以及環狀串列若有鏈結斷裂，那麼後面的串列資料都會遺失而無法復原，因此可以**使用兩個不同方向的指標，一個指向前面節點，一個指向下一個節點**，其優點是可以從任一節點找到其他節點，而不需要經過反轉，執行速度較快，若一端鏈結斷裂，可經由反方向串列走訪，快速完整的重建鏈結，缺點則是較為浪費空間。

## 3-4-1 雙向串列的建立與走訪
雙向連結的資料結構定義如下： </br>

      [L_Link1 | Data1 | R_Link1] -> [L_Link2 | Data2 | R_Link2]

1. 其中 L_Link 指向前一個節點，R_Link 指向下一個節點
2. 通常加上一個串列首，裡面不儲存任何資料，其 L_Link 指向串列最後一個資料，R_Link 指向第一個節點
3. 其資料結構如下
  
```cpp
class _NODE{
  public:
      int data;
      class _NODE * LLINK;
      class _NODE * RLINK;
}
```
其串列走訪方式： </br>
```cpp
node_current = node_head -> RLINK;
while(node_current != NULL){
    cout << node_current -> data;
    node_current = node_current -> RLINK;
}
```

## 3-4-2 雙向串列插入節點
有以下三種情況：
- 將新節點加入此串列的第一個節點前

```cpp
node_new -> RLINK = node_head; //node_new 的 RLINK 指向原本的第一個
node_head -> LLINK = node_new; //原本的串列首指向新節點
node_head = node_new; //node_head 重新指向串列首
```

- 將新節點加入此串列的最後

```cpp
node_new -> RLINK = NULL; //node_new 的 RLINK 指向NULL
node_new -> LLINK = node_last; 
node_last -> RLINK = node_new; //原本的串列尾指向新節點
node_last = node_new; //node_last 重新指向串列尾
```

- 將新節點加入此串列的某一節點 ptr 之後

```cpp
node_new -> RLINK = ptr -> RLINK; //node_new 的 RLINK 指向 ptr 的下一個節點
node_new -> LLINK = ptr; 
ptr -> RLINK = node_new; //ptr 指向新節點
```

## 3-4-3 雙向串列刪除節點
有以下三種情況：

- 刪除第一個節點
  
```cpp
node_delete = node_head;
node_head = node_head -> RLINK; 
node_head -> LLINK = NULL;
delete node_delete;
```  

- 刪除最後一個節點

```cpp
node_delete = node_last;
node_last = node_last -> LLINK; 
node_last -> RLINK = NULL;
delete node_delete;
```  

- 刪除中間節點 ptr

```cpp
node_delete = node_ptr;
node_ptr -> LLINK -> RLINK = node_ptr -> RLINK; 
node_ptr -> RLINK -> LLINK = node_ptr -> LLINK; //記得要指回去
delete node_delete;
```  
